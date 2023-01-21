#include "RosHandlerFactory.h"
#include "ControlGroup.h"
#include "Group.h"
#include "MockMotor.h"
#include "Motor.h"
#include "XmlRpcValue.h"
#include <algorithm>
#include <stdexcept>

namespace ConfigParsing {

using Hardware::ControlGroup;
using Hardware::Group;
using Hardware::MockMotor;
using Hardware::Motor;
using XmlRpc::XmlRpcValue;

// TODO: Fix CC rating
RosHandlerFactory::RosHandlerFactory(const XmlRpcValue &dictionary) {

    // ATOMIC MOTORS/MOCKS

    if (!dictionary.hasMember("physicalMotors")) {
        throw std::invalid_argument{"Missing required component /physicalMotors"};
    }

    const auto &physicalMotors{dictionary["physicalMotors"]};
    std::map<std::string, std::shared_ptr<ControlGroup>> controlGroups;
    for (const auto &[motorName, motorProperties] : physicalMotors) {
        if (motorProperties.hasMember("mock") && static_cast<bool>(motorProperties["mock"]))
            controlGroups.insert({motorName, std::make_shared<MockMotor>(motorName)});
        else {
            if (!motorProperties.hasMember("ID"))
                throw std::invalid_argument{"Missing required component /physicalMotors/" + motorName + "/ID for a real motor"};
            controlGroups.insert({motorName, std::make_shared<Motor>(static_cast<uint8_t>(static_cast<int32_t>(motorProperties["ID"])), motorName)});
        }
    }

    // COMPOSITE GROUPS

    if (!dictionary.hasMember("compositeGroups")) {
        throw std::invalid_argument{"Missing required component /compositeGroups"};
    }

    const auto &compositeGroups{dictionary["compositeGroups"]};
    std::map<std::string, std::vector<std::string>> dependencyGraph;
    for (const auto &[groupName, groupProperties] : compositeGroups) {
        if (!groupProperties.hasMember("containedGroups"))
            throw std::invalid_argument{"Missing required component /controlGrcompositeGroupsoups/" + groupName + "/containedGroups for composite group"};

        dependencyGraph.insert({groupName, {}});
        for (const auto &[_, dependency] : groupProperties["containedGroups"])
            dependencyGraph.at(groupName).push_back(static_cast<std::string>(dependency));
    }

    // Preserve original dependency graph
    const auto referenceDependencyGraph{dependencyGraph};

    // Remove dependencies on atomic groups
    for (const auto &[controlGroupName, _] : controlGroups) {
        for (auto &[groupName, dependencies] : dependencyGraph) {
            const auto &toRemove = std::find(dependencies.begin(), dependencies.end(), controlGroupName);
            if (toRemove != dependencies.end()) {
                dependencies.erase(toRemove);
            }
        }
    }

    // Resolve dependency graph
    while (!dependencyGraph.empty()) {
        auto anyEmpty{false};
        std::vector<std::string> toRemove;

        for (const auto &[groupName, dependencies] : dependencyGraph) {
            if (!dependencies.empty())
                continue;

            anyEmpty = true;

            auto newControlGroup{std::make_shared<Group>(groupName)};
            for (const auto &dependency : referenceDependencyGraph.at(groupName))
                newControlGroup->addControlGroup(controlGroups.at(dependency));

            controlGroups.insert({groupName, newControlGroup});
            toRemove.push_back(groupName);
        }

        for (const auto &groupName : toRemove) {
            dependencyGraph.erase(groupName);
        }

        if (!anyEmpty)
            throw std::invalid_argument{"Cyclic dependency detected in config file"};
    }
}

} // namespace ConfigParsing

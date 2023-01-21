#include "RosHandlerFactory.h"
#include "ControlGroup.h"
#include "MockMotor.h"
#include "Motor.h"
#include "XmlRpcValue.h"
#include <stdexcept>

namespace ConfigParsing {

using Hardware::ControlGroup;
using Hardware::MockMotor;
using Hardware::Motor;
using XmlRpc::XmlRpcValue;

RosHandlerFactory::RosHandlerFactory(const XmlRpcValue &dictionary) {
    if (!dictionary.hasMember("physicalMotors")) {
        throw std::invalid_argument{"Missing required component /physicalMotors"};
    }

    XmlRpcValue &physicalMotors{dictionary["physicalMotors"]};
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
}

} // namespace ConfigParsing

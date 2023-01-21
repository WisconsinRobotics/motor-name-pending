#ifndef ROS_HANDLER_FACTORY_H
#define ROS_HANDLER_FACTORY_H

#include "ControlGroup.h"
#include <XmlRpcValue.h>
#include <memory>
#include <vector>

namespace ConfigParsing {
class RosHandlerFactory {
public:
    explicit RosHandlerFactory(const XmlRpc::XmlRpcValue &dictionary);

private:
    std::vector<std::unique_ptr<Hardware::ControlGroup>> parsedControlGroups;
};
} // namespace ConfigParsing

#endif

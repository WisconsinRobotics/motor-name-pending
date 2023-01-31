#ifndef ROS_SERVICE_ACTION_H
#define ROS_SERVICE_ACTION_H

#include "RosConcepts.h" // IWYU pragma: keep; Concept defintion
#include "ros/node_handle.h"

namespace RosHandler::RosHandlerCore {

template <RosService T>
class RosServiceAction {
public:
    RosServiceAction(ros::NodeHandle &node, const std::string &serviceName, const ros::Duration &maxResponseTime)
        : server{node.advertiseService(serviceName, &RosServiceAction<T>::serviceCallback, this)},
          maxResponseTime{maxResponseTime} {}

    virtual ~RosServiceAction() = default;
    RosServiceAction(const RosServiceAction &) = delete;
    auto operator=(const RosServiceAction &) -> RosServiceAction & = delete;
    RosServiceAction(RosServiceAction &&) = delete;
    auto operator=(RosServiceAction &&) = delete;

private:
    auto serviceCallback(ros::ServiceEvent<typename T::Request, typename T::Response> &event) -> bool {
        // No timing information on these, may be implemented later
        return onServiceRequest(event.getRequest(), event.getResponse());
    }

    virtual auto onServiceRequest(const typename T::Request &req, typename T::Response &resp) -> bool = 0;

    const ros::ServiceServer server;
    const ros::Duration maxResponseTime;
};
} // namespace RosHandler::RosHandlerCore

#endif
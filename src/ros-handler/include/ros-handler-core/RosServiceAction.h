#ifndef ROS_SERVICE_ACTION_H
#define ROS_SERVICE_ACTION_H

#include "RosConcepts.h" // IWYU pragma: keep; Concept defintion
#include "ros/node_handle.h"

namespace RosHandler::RosHandlerCore {

template <RosService T>
class RosServiceAction {
public:
    RosServiceAction(const ros::NodeHandle &node, std::string_view serviceName, const ros::Duration &maxResponseTime)
        : server(node.advertiseService<T>(serviceName, &RosServiceAction<T>::serviceCallback, this)),
          maxResponseTime{maxResponseTime} {}

    virtual ~RosServiceAction() = default;
    RosServiceAction(const RosServiceAction &) = delete;
    auto operator=(const RosServiceAction &) -> RosServiceAction & = delete;
    RosServiceAction(RosServiceAction &&) = delete;
    auto operator=(RosServiceAction &&) = delete;

private:
    void serviceCallback(const ros::ServiceEvent<typename T::Request, typename T::Response> &event) {
        const auto responseDelay = ros::Time::now() - event.getReceiptTime();
        if (responseDelay > maxResponseTime) {
            ROS_WARN_STREAM(
                "Response on service '" << server.getService() << "' is taking longer than expected: Exp: " << maxResponseTime << " Act: " << responseDelay);
        }
        onMessageReceived(event.getRequest(), event.getResponse());
    }

    virtual void onServiceRequest(typename T::Request &req, typename T::Response &resp) = 0;

    const ros::ServiceServer server;
    const ros::Duration maxResponseTime;
};
} // namespace RosHandler::RosHandlerCore

#endif
#ifndef ROS_CONCEPTS_H
#define ROS_CONCEPTS_H

namespace RosHandler::RosHandlerCore {

template <class T>
concept RosMessage = requires {
    typename T::ConstPtr;
};

template <class T>
concept RosService = requires {
    typename T::Request;
    typename T::Response;
};

} // namespace RosHandler::RosHandlerCore

#endif
#ifndef ROS_CONCEPTS_H
#define ROS_CONCEPTS_H

namespace RosHandler::RosHandlerCore {

template <class T>
concept RosMessage = requires {
    T::ConstPtr;
};

template <class T>
concept RosService = requires {
    T::Request;
    T::Response;
};

} // namespace RosHandler::RosHandlerCore

#endif
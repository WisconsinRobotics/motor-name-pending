#ifndef COMMUNICATION_HANDLER_H
#define COMMUNICATION_HANDLER_H

namespace rosLib {
    class communicationHandler {
        public:
            void spinOnce();
            void spin(bool set);
    };
}

#endif
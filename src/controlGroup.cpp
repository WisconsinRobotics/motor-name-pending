#include <stdint.h>

using namespace std;

class ControlGroup {
    public:
        enum class ZeroPowerBehavior{
            BRAKE, COAST
        };
        void setPower(double power);
        int32_t getEncoder();
        void setZeroPowerBehavior(ZeroPowerBehavior inputBehavior);
        void setReversal(bool inverted);
};
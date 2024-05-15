#include "PigeonIMU.h"
#include "ctre/phoenix/platform/can/PlatformCAN.h"
#include <chrono>
#include <iostream>
#include <memory>
#include <string>
#include <thread>

using Hardware::PigeonIMU;
using std::this_thread::sleep_for;

constexpr int32_t PIGEON_CAN_ID{10};
constexpr std::chrono::seconds LONG_WAIT{60};

auto main() -> int32_t {

    ctre::phoenix::platform::can::PlatformCAN::SetCANInterface("can0");
    std::cout << "Hardware setup" << std::endl;

    auto pigeon{std::make_shared<Hardware::PigeonIMU>(PIGEON_CAN_ID, "pigeon")};
    pigeon->enableCompass(false);

    std::cout << "Starting calibration" << std::endl;

    pigeon->startMagCal();

    sleep_for(LONG_WAIT);

    std::cout << "Saving calibration" << std::endl;

    pigeon->endMagCal(true);

}

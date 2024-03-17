#include "ControlGroup.h"
#include "Group.h"
#include "Motor.h"
#include "ctre/phoenix/platform/Platform.h"
#include "ctre/phoenix/platform/can/PlatformCAN.h"
#include "ctre/phoenix/unmanaged/Unmanaged.h"
#include <chrono>
#include <iostream>
#include <memory>
#include <string>
#include <thread>

using Hardware::ControlGroup;
using Hardware::Group;
using Hardware::Motor;
using std::this_thread::sleep_for;

void printControlGroup(const ControlGroup &obj);

constexpr int32_t FEED_ENABLE_TIMEOUT_MILLISECONDS{100000};
constexpr int32_t MOTOR_1_ID{1};
constexpr int32_t MOTOR_2_ID{2};
constexpr double SLOW_SPEED{0.1};
constexpr std::chrono::seconds LONG_WAIT{5};

auto main() -> int32_t {

    short int some_num = 0;

    ctre::phoenix::platform::can::PlatformCAN::SetCANInterface("can0");
    std::cout << "Starting motor" << std::endl;
    ctre::phoenix::unmanaged::Unmanaged::FeedEnable(FEED_ENABLE_TIMEOUT_MILLISECONDS);

    TalonFX mtr{1};
    // mtr.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput, 0.2);

    // TODO (@Tzanccc): while true loop here to isolate diagnostic program. Should seperate test program from diaognistic server into two applications instead
    while(true);
    std::shared_ptr<Motor> testMotor1 = std::make_shared<Motor>(MOTOR_1_ID, "MOTOR1");
    std::shared_ptr<Motor> testMotor2 = std::make_shared<Motor>(MOTOR_2_ID, "MOTOR2");
    Group testGroup1{"testGroup1"};
    
    std::cout << "Enable state: " << ctre::phoenix::unmanaged::Unmanaged::GetEnableState() << std::endl;

    testMotor1->setPower(0.5);
    testGroup1.addControlGroup(testMotor1);
    //testGroup1.addControlGroup(testMotor2);
    testGroup1.resetSettings();
    printControlGroup(testGroup1);
    testGroup1.setPrimaryEncoder(testMotor1);
    testGroup1.setPower(SLOW_SPEED);
    sleep_for(LONG_WAIT);
    testGroup1.setPower(0);
    sleep_for(LONG_WAIT);
    testGroup1.setZeroPowerBehavior(Hardware::ZeroPowerBehavior::COAST);
    testGroup1.setPower(SLOW_SPEED);
    sleep_for(LONG_WAIT);
    testGroup1.setPower(0);
    sleep_for(LONG_WAIT);

    //testGroup1.removeControlGroup(testGroup1.getControlGroup("2"));
    testGroup1.resetSettings();
    printControlGroup(testGroup1);
    testGroup1.setPrimaryEncoder(testMotor1);
    testGroup1.setPower(SLOW_SPEED);
    sleep_for(LONG_WAIT);
    testGroup1.setPower(0);
    sleep_for(LONG_WAIT);
    testGroup1.setZeroPowerBehavior(Hardware::ZeroPowerBehavior::COAST);
    testGroup1.setPower(SLOW_SPEED);
    sleep_for(LONG_WAIT);
    testGroup1.setPower(0);
    sleep_for(LONG_WAIT);

    testGroup1.clearGroup();
    printControlGroup(testGroup1);
};

void printControlGroup(const ControlGroup &obj) {
    std::cout << "Motor Name:  " << obj.getName() << std::endl;
    std::cout << "Encoder Value:  " << obj.getEncoder().value_or(-1)
              << std::endl;
}

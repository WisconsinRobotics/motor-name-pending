#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include "controlGroup.h"
#include "group.h"
#include "motor.h"

using std::to_string;
using MotorLib::Motor;
using MotorLib::ControlGroup;
using namespace std::this_thread;
using namespace std::chrono;
using std::cout;

void printControlGroup(const ControlGroup &obj);

int main() {

    ctre::phoenix::platform::can::SetCANInterface("can0");
    std::unique_ptr<TalonFX> testMotor0;
    static constexpr int8_t PRIMARY_CLOSED_LOOP_PID = 0;
    testMotor0 = std::unique_ptr<TalonFX>(new TalonFX{1});
    testMotor0->SetInverted(false);
    testMotor0->SetSensorPhase(false);
    testMotor0->SetSelectedSensorPosition(0, PRIMARY_CLOSED_LOOP_PID, 100);
    testMotor0->SetNeutralMode(Brake);
    cout << testMotor0->GetSelectedSensorPosition(PRIMARY_CLOSED_LOOP_PID) << std::endl;
    std::cout << "Starting motor" << std::endl;
    ctre::phoenix::unmanaged::FeedEnable(100000);
    cout << testMotor0->GetSelectedSensorPosition(PRIMARY_CLOSED_LOOP_PID) << std::endl;

    sleep_for(seconds(5));
    testMotor0->Set(ControlMode::Position, 2048);
    cout << testMotor0->GetSelectedSensorPosition(PRIMARY_CLOSED_LOOP_PID) << std::endl;

    sleep_for(seconds(5));
    testMotor0->Set(ControlMode::Position, 4096);
    cout << testMotor0->GetSelectedSensorPosition(PRIMARY_CLOSED_LOOP_PID) << std::endl;

    sleep_for(seconds(5));
    testMotor0->SetInverted(true);
    testMotor0->SetSensorPhase(true);
    testMotor0->Set(ControlMode::Position, -4096);
    cout << testMotor0->GetSelectedSensorPosition(PRIMARY_CLOSED_LOOP_PID) << std::endl;

    sleep_for(seconds(5));
    testMotor0->Set(ControlMode::Position, 0);
    cout << testMotor0->GetSelectedSensorPosition(PRIMARY_CLOSED_LOOP_PID) << std::endl;

    // ctre::phoenix::platform::can::SetCANInterface("can0");
    // Motor testMotor0 {1};
    // printControlGroup(testMotor0);
    // std::cout << "Starting motor" << std::endl;
    // ctre::phoenix::unmanaged::FeedEnable(100000);
    


    // testMotor0.setZeroPowerBehavior(MotorLib::ZeroPowerBehavior::COAST);
    // testMotor0.setPower(0.2);
    // sleep_for(seconds(10));
    // printControlGroup(testMotor0);
    // testMotor0.setPower(0);
    // sleep_for(seconds(5));

    // testMotor0.setZeroPowerBehavior(MotorLib::ZeroPowerBehavior::BRAKE);
    // testMotor0.setPower(0.2);
    // sleep_for(seconds(10));
    // printControlGroup(testMotor0);
    // testMotor0.setPower(0);
    // sleep_for(seconds(5));

    // testMotor0.setReversal(true);

    // testMotor0.setZeroPowerBehavior(MotorLib::ZeroPowerBehavior::COAST);
    // testMotor0.setPower(0.2);
    // sleep_for(seconds(10));
    // printControlGroup(testMotor0);
    // testMotor0.setPower(0);
    // sleep_for(seconds(5));

    // testMotor0.setZeroPowerBehavior(MotorLib::ZeroPowerBehavior::BRAKE);
    // testMotor0.setPower(0.2);
    // sleep_for(seconds(10));
    // printControlGroup(testMotor0);
    // testMotor0.setPower(0);
    // sleep_for(seconds(5));
    // printControlGroup(testMotor0);
};


void printControlGroup(const ControlGroup &obj){
    printf("Motor Name:  %s\n", obj.getName().c_str());
    printf("Encoder Value:  %s\n", to_string(obj.getEncoder()).c_str());
}
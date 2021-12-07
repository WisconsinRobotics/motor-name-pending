#include <iostream>
#include <chrono>
#include <thread>
#include "controlGroup.h"
#include "group.h"
#include "motor.h"

using MotorLib::Motor;
using MotorLib::ControlGroup;
using namespace std::this_thread;
using namespace std::chrono;

int main() {
    Motor testMotor0 {0};
    testMotor0.getEncoder();
    testMotor0.getName();

    testMotor0.setZeroPowerBehavior(ControlGroup::ZeroPowerBehavior::COAST);
    testMotor0.setPower(0.2);
    sleep_for(seconds(10));
    testMotor0.setPower(0);
    sleep_for(seconds(5));

    testMotor0.setZeroPowerBehavior(ControlGroup::ZeroPowerBehavior::BRAKE);
    testMotor0.setPower(0.2);
    sleep_for(seconds(10));
    testMotor0.setPower(0);
    sleep_for(seconds(5));

    testMotor0.setReversal(true);

    testMotor0.setZeroPowerBehavior(ControlGroup::ZeroPowerBehavior::COAST);
    testMotor0.setPower(0.2);
    sleep_for(seconds(10));
    testMotor0.setPower(0);
    sleep_for(seconds(5));

    testMotor0.setZeroPowerBehavior(ControlGroup::ZeroPowerBehavior::BRAKE);
    testMotor0.setPower(0.2);
    sleep_for(seconds(10));
    testMotor0.setPower(0);
    sleep_for(seconds(5));

    testMotor0.~Motor();
};
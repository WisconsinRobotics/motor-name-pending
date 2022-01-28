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
    Motor testMotor0 {1};
    printControlGroup(testMotor0);
    std::cout << "Starting motor" << std::endl;
    ctre::phoenix::unmanaged::FeedEnable(100000);
    


    testMotor0.setZeroPowerBehavior(MotorLib::ZeroPowerBehavior::COAST);
    testMotor0.setPower(0.1);
    sleep_for(seconds(2));
    printControlGroup(testMotor0);
    testMotor0.setPower(0);
    sleep_for(seconds(5));

    testMotor0.setZeroPowerBehavior(MotorLib::ZeroPowerBehavior::BRAKE);
    testMotor0.setPower(0.1);
    sleep_for(seconds(2));
    printControlGroup(testMotor0);
    testMotor0.setPower(0);
    sleep_for(seconds(5));

    testMotor0.setReversal(true);

    testMotor0.setZeroPowerBehavior(MotorLib::ZeroPowerBehavior::COAST);
    testMotor0.setPower(0.1);
    sleep_for(seconds(2));
    printControlGroup(testMotor0);
    testMotor0.setPower(0);
    sleep_for(seconds(5));

    testMotor0.setZeroPowerBehavior(MotorLib::ZeroPowerBehavior::BRAKE);
    testMotor0.setPower(0.1);
    sleep_for(seconds(2));
    printControlGroup(testMotor0);
    testMotor0.setPower(0);
    sleep_for(seconds(5));
    printControlGroup(testMotor0);
};


void printControlGroup(const ControlGroup &obj){
    printf("Motor Name:  %s\n", obj.getName().c_str());
    printf("Encoder Value:  %s\n", to_string(obj.getEncoder()).c_str());
}
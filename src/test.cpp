#include <iostream>
#include <chrono>
#include <thread>
#include <memory>
#include <string>
#include "controlGroup.h"
#include "group.h"
#include "motor.h"

using std::to_string;
using MotorLib::Motor;
using MotorLib::ControlGroup;
using MotorLib::Group;
using namespace std::this_thread;
using namespace std::chrono;

void printControlGroup(const ControlGroup &obj);

int main() {

    ctre::phoenix::platform::can::SetCANInterface("can0");
    std::cout << "Starting motor" << std::endl;
    ctre::phoenix::unmanaged::FeedEnable(100000);

    std::shared_ptr<Motor> testMotor1 = std::make_shared<Motor>(1);
    std::shared_ptr<Motor> testMotor2 = std::make_shared<Motor>(2);
    Group testGroup1 {"testGroup1"};

    testGroup1.addControlGroup(testMotor1);
    testGroup1.addControlGroup(testMotor2);
    testGroup1.reset();
    printControlGroup(testGroup1);
    testGroup1.setPrimaryEncoder(testMotor1);
    testGroup1.setPower(0.1);
    sleep_for(seconds(5));
    testGroup1.setZeroPowerBehavior(MotorLib::ZeroPowerBehavior::COAST);
    testGroup1.setPower(0.1);
    sleep_for(seconds(5));
    
    testGroup1.removeControlGroup(testGroup1.getControlGroup("2"));
    testGroup1.reset();
    printControlGroup(testGroup1);
    testGroup1.setPrimaryEncoder(testMotor1);
    testGroup1.setPower(0.1);
    sleep_for(seconds(5));
    testGroup1.setZeroPowerBehavior(MotorLib::ZeroPowerBehavior::COAST);
    testGroup1.setPower(0.1);
    sleep_for(seconds(5));

    testGroup1.clearGroup();
    printControlGroup(testGroup1);


    
};


void printControlGroup(const ControlGroup &obj){
    printf("Motor Name:  %s\n", obj.getMembers().c_str());
    printf("Encoder Value:  %s\n", to_string(obj.getEncoder()).c_str());
}
#!/usr/bin/env python3
import rospy
import std_msgs

rospy.init_node("temp_node")
import math

pub = rospy.Publisher("/MOTOR_1/power", std_msgs.msg.Float64, queue_size=10)
rate = rospy.Rate(20)
t = 0
while not rospy.is_shutdown():
    p = math.sin(2 * math.pi * t / (20 * 10))
    t += 1
    pub.publish(p)
    rate.sleep()

#!/usr/bin/env pybricks-micropython
# Group 4
# Kulpitha Chaimongkol 640510639 sec 01
# Ganokporn Pongdilok 640510604 sec 01
# Anchalee Homjai 640510690 sec 01
"""
Example LEGO® MINDSTORMS® EV3 Robot Educator Ultrasonic Sensor Driving Base Program
-----------------------------------------------------------------------------------
This program requires LEGO® EV3 MicroPython v2.0.
Download: https://education.lego.com/en-us/support/mindstorms-ev3/python-for-ev3
Building instructions can be found at:
https://education.lego.com/en-us/support/mindstorms-ev3/building-instructions#robot
"""
from pybricks.hubs import EV3Brick
from pybricks.ev3devices import Motor, UltrasonicSensor, GyroSensor
from pybricks.parameters import Port
from pybricks.tools import wait
from pybricks.robotics import DriveBase
import random
# Initialize the EV3 Brick.
ev3 = EV3Brick()
# Initialize the Ultrasonic Sensor. It is used to detect
# obstacles as the robot drives around.
obstacle_sensor = UltrasonicSensor(Port.S1)
gyroscopic_sensor = GyroSensor(Port.S3)
# Initialize two motors with default settings on Port B and Port C.
# These will be the left and right motors of the drive base.
left_motor = Motor(Port.B)
right_motor = Motor(Port.C)
# The DriveBase is composed of two motors, with a wheel on each motor.
# The wheel_diameter and axle_track values are used to make the motors
# move at the correct speed when you give a motor command.
# The axle track is the distance between the points where the wheels
# touch the ground.
robot = DriveBase(left_motor, right_motor, wheel_diameter=55.5, axle_track=104)
# Play a sound to tell us when we are ready to start moving
ev3.speaker.beep()
# The following loop makes the robot drive forward until it detects an
# obstacle. Then it backs up and turns around. It keeps on doing this
# until you stop the program.
while True:
    # Begin driving forward at 200 millimeters per second.
    robot.drive(200, 0)
    
    ev3.screen.draw_text(0, 50,"Distance = " + str(obstacle_sensor.distance()) + "mm")
    # Wait until an obstacle is detected. This is done by repeatedly
    # doing nothing (waiting for 10 milliseconds) while the measured
    # distance is still greater than 300 mm.
    while obstacle_sensor.distance() > 100:
        wait(1)
        ev3.screen.clear()
        ev3.screen.draw_text(0, 50,"Distance = " + str(obstacle_sensor.distance()) + "mm")
    robot.stop()
    

    ev3.speaker.beep()
    x = random.randint(0,1)
    if (x == 0) :
        ev3.screen.clear()
        ev3.screen.draw_text(0, 50,"Left " + str(gyroscopic_sensor.angle()) + " degree")
        robot.turn(138)
    else :
        ev3.screen.clear()
        ev3.screen.draw_text(0, 50,"Right " + str(gyroscopic_sensor.angle()) + " degree")
        robot.turn(-138)
    
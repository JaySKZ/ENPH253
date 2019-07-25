#include <movement.h>

using namespace constants;

/*
Drive.cpp contains all the functions related to movement of the robot through the drive motors.

This file needs a lot of thought and redesigning as we test things and make design decisions about whats best
Feel free to change
*/

/*
* Drives the robot forwards throughout the course and makes turns itself
*/
void movement::drive(void) {
}

/*
* Drives the robot forward by following the tape
*/
void movement::pidDrive(void){

}

/*
* Performs a 180 by spinning a bit to get off the tape and then continues turning until the line sensor detects tape again
*/
void movement::turnAround(void) {
  //Might want to add direction?
}

void movement::checkSonars(void){
  //This needs to be done with interrupts instead
}

/*
* Aligns the robot with the gauntlet to prepare for dispensing
*/
void movement::alignGauntlet(void) {

}

/*
* Turns all drive motors off
*/
void killDriveMotors(void) {
    analogWrite(LF_MOTOR,0);
    analogWrite(LR_MOTOR,0);
    analogWrite(RF_MOTOR,0);
    analogWrite(RR_MOTOR,0);
}

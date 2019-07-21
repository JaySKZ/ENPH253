#include <Arduino.h>
#include <arm.h>

/*
Arm.cpp contains all functions related to moving the arm including collection, dispensing, and other movement.
*/



/*
* Homes all the components of the arm: lift,slider,claw, and rotates it to home.
* Home is defined as the claw as being at the bottom of the lift, the slider retracted fully, and the arm rotated forwards
*/
void arm::homeArm(void) {
lowerClaw();
homeSlider();

}

/*
* Extends all components of the arm: lift,slider,claw, and rotation
*/
void arm::extendArm(void) {

}

/*
* Dispenses all the stones into the gauntlet once already lined up
*/
void arm::dispenseStones(void) {

}

/*
* Collects a stone and places it into the dispenser once the robot has parked beside it
*/
void arm::collectStone(void) {

}


/*
* Raises the claw to the highest position
*/
void arm::raiseClaw(void) {
  while(digitalRead(LIFT_TOP_SW)==LOW) {
    analogWrite(LIFT_DIR, 255);
    analogWrite(LIFT_STEP, 255);
  }
  analogWrite(LIFT_STEP, 0);
}

/*
*  Lowers the claw to the lowest point or until it hits a stone
*/

void arm::lowerClaw(void) {
  while(digitalRead(LIFT_BOT_SW)==LOW) {
    analogWrite(LIFT_DIR,0);
    analogWrite(LIFT_STEP,255);
  }
  analogWrite(LIFT_STEP,0);
}

/*
* Extends the slider of the arm fully
*/
void arm::extendSlider(void) {

}
/*
* Retracts the slider of the arm fully
*/
void arm::homeSlider(void){

}

/*
* Rotates the arm to it's home position
*/
void arm::homeRotateArm(void){

}

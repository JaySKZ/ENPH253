#include <Arduino.h>
#include <arm.h>

/*
Arm.cpp contains all functions related to moving the arm including collection, dispensing, and other movement.
*/

/*
* Constructer for the arm object
*/
arm::arm(uint8_t* SPI1, uint8_t* SPI2) {
  SPIdata1 = SPI1;
  SPIdata2 = SPI2;
}

/*
* Homes all the components of the arm: lift,slider,claw, and rotates it to home.
* Home is defined as the claw as being at the bottom of the lift, the slider retracted fully, and the arm rotated forwards
*/
void arm::homeArm(void) {
homeClaw();
homeSlider();

}

/*
* Extends all components of the arm: lift,slider,claw, and rotation
*/
void arm::extendArm(void) {
  raiseClaw();
  extendSlider();
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
  analogWrite(LIFT_DIR, UP);
  while(*SPIdata1 & (pow(2,LIFT_TOP_BIT) == 0)) {
    analogWrite(LIFT_STEP, 255);
  }
  analogWrite(LIFT_STEP, 0);
}

/*
* Lowers the claw until it hits a pole or hits the bottom
*/
void arm::lowerClaw(void) {
  
}

/*
*  Lowers the claw to the lowest point
*/
void arm::homeClaw(void) {
  digitalWrite(LIFT_DIR,DOWN);
  while(!(*SPIdata1 & ((int)pow(2,LIFT_BOT_BIT)))) {
    analogWrite(LIFT_STEP,255);
  }
  analogWrite(LIFT_STEP,LOW);
}

/*
* Extends the slider of the arm fully
*/
void arm::extendSlider(void) {
  analogWrite(SLIDE_DIR,FORWARDS);
  while(*SPIdata1 & (pow(2,SLIDE_FRONT_BIT) == 0)) {
    analogWrite(SLIDE_STEP, 255);
  }
  analogWrite(LIFT_STEP,0);
}

/*
* Retracts the slider of the arm fully
*/
void arm::homeSlider(void){
  digitalWrite(SLIDE_DIR,BACKWARDS);

  while(!(*SPIdata1 & ((int)pow(2,SLIDE_BACK_BIT)))) {
    analogWrite(SLIDE_STEP,255);
  }
  analogWrite(SLIDE_STEP,0);
}

/*
* Rotates the arm to it's home position. Pass true for clockwise and false for CCW
*/
void arm::homeRotateArm(bool direction){
  if(direction == true) {analogWrite(SLIDE_DIR,CW);}
  else {analogWrite(SLIDE_DIR,CCW);}

  while(*SPIdata1 & (pow(2,ARM_HOME_BIT) == 0)) {
    analogWrite(ARM_STEP,255);
  }
  analogWrite(ARM_STEP,0);
}

#include <arm.h>
#include <Arduino.h>
#include <constants.h>
#include <A4988.h>
#include <Servo.h>

/*
Arm.cpp contains all functions related to moving the arm including collection, dispensing, and other movement.
*/


//This is so you dont have to write constants:: every time you want to use it.
//Its not really good practice but its ok :P
using namespace constants;

//Motor Objects
A4988 sliderStepper(200, SLIDER_DIR, SLIDER_STEP);
A4988 armStepper(200, ARM_DIR, ARM_STEP);
A4988 liftStepper(200, LIFT_DIR, LIFT_STEP);
Servo clawOpenServo;
Servo clawRotateServo;
Servo dispenserServo;


/*
* Constructer for the arm object. SPI1 and SPI2 are the pointers to our limit switch data
*/
arm::arm(uint8_t *SPI1, uint8_t *SPI2) {
  SPIdata1 = SPI1;
  SPIdata2 = SPI2;
  liftPosition = 0;
  sliderPosition = 0;
  armPosition = 0;

  clawOpenServo.attach(CLAW_OPEN_PIN);
  clawRotateServo.attach(CLAW_ROTATE_PIN);
  dispenserServo.attach(DISPENSE_PIN);
  sliderStepper.begin(300,1);
  armStepper.begin(300,1);
  liftStepper.begin(300,1);
}


/*
* Homes the larger components of the arm: the slider,lower the lifts and rotates it CW to home.
* Home is defined as the claw as being at the bottom of the lift, the slider retracted fully, and the arm rotated forwards
*/
void arm::homeArm(void) {
  homeSlider();
  homeRotateArm();
  homeClaw();
}


/*
* Extends the slider and lifts the claw/lift
*/
void arm::extendArm(void) {
  raiseClaw();
  extendSlider();
}


/*
* Moves the lift to a desired position
* Parameters: position (0- idk)
*/
void arm::moveLift(int position) {
  liftStepper.move(position - liftPosition);
  liftPosition = position;
}


/*
* Moves the slider to a desired position
* Parameters: position (0-idk)
*/
void arm::moveSlider(int position) {
  sliderStepper.move(position - sliderPosition);
  sliderPosition = position;
}


/*
* Moves the arm to a desired position
* Parameters: position (-idk,idk)
*/
void arm::moveArm(int position) {
  armStepper.move(position - armPosition);
  armPosition = position;
}


/*
* Dispenses all the stones into the gauntlet once already lined up
*/
void arm::dispenseStones(void) {
  dispenserServo.write(DISPENSER_POSITION);
}


/*
* Collects a stone and places it into the dispenser once the robot has parked beside it
* Parameters: stoneNumber is the number of stones already stored (0-3)
*/
void arm::collectStone(int stoneNumber) {
  homeArm();
  delay(1000);
  moveArm(-180);
  extendSlider();
  poleRotateArm();
  retractSlider();
  //lowerClaw();
}


/*
* Homes arm then stores stone from claw to a spot on the flipper.
* Parameters: stoneNumber is the number of stones already stored (0-3)
*/
void arm::storeStone(int stoneNumber) {
  homeArm();
  switch(stoneNumber){
    case 0:
          armStepper.move(ARM_STONE0);
          sliderStepper.move(SLIDER_STONE0);
          clawRotateServo.write(CLAW_STONE0);
          break;
    case 1:
          armStepper.move(ARM_STONE1);
          sliderStepper.move(SLIDER_STONE1);
          clawRotateServo.write(CLAW_STONE1);
          break;
    case 2:
          armStepper.move(ARM_STONE2);
          sliderStepper.move(SLIDER_STONE2);
          clawRotateServo.write(CLAW_STONE2);
          break;
    case 3:
          armStepper.move(ARM_STONE3);
          sliderStepper.move(SLIDER_STONE3);
          clawRotateServo.write(CLAW_STONE3);
          break;
  }
  openClaw();
}


/*
* Raises the claw to the highest position
*/
void arm::raiseClaw(void) {
  moveLift(LIFT_TOP_POSITION);
  liftPosition = LIFT_TOP_POSITION;
}


/*
* Lowers the claw until it hits a pole or hits the bottom
*/
void arm::lowerClaw(void) {
  while((!(((*SPIdata1) & ((int)pow(2,CLAW_COLLIDE_BIT))))) && ((!(((*SPIdata1) & ((int)pow(2,LIFT_BOT_BIT))))))) {
    liftStepper.move(-5);
    liftPosition-=5;
    delay(5);
  }
}


/*
*  Lowers the claw to the lowest point
*/
void arm::homeClaw(void) {
  digitalWrite(LIFT_DIR,DOWN);
    while(!(((*SPIdata1) & ((int)pow(2,LIFT_BOT_BIT))))) {
    analogWrite(LIFT_STEP,255);

  }
  analogWrite(LIFT_STEP,LOW);
  liftPosition = 0;
  moveLift(LIFT_TOP_POSITION);
}


/*
* Opens the claw
*/
void arm::openClaw(){
  clawOpenServo.write(CLAW_OPEN_DEG);
}


/*
* Closes the claw
*/
void arm::closeClaw(){
  clawOpenServo.write(CLAW_CLOSE_DEG);
}


/*
* Extends the slider of the arm fully
*/
void arm::extendSlider(void) {
  moveSlider(SLIDER_FRONT_POSITION);
  sliderPosition = SLIDER_FRONT_POSITION;
}


/*
* Retracts the slider of the arm fully
*/
void arm::homeSlider(void){
  digitalWrite(SLIDER_DIR,BACKWARDS);
  while(!(((*SPIdata1) & ((int)pow(2,SLIDER_BACK_BIT))))){
    analogWrite(SLIDER_STEP,255);
  }
  analogWrite(SLIDER_STEP,0);
  sliderPosition = 0;
}


/*
* Retracts the slider until it collides with a pole or comes home
*/
void arm::retractSlider(void){
  while((!(((*SPIdata1) & ((int)pow(2,SLIDER_BACK_BIT))))) && (!(((*SPIdata1) & ((int)pow(2,HOOK_COLLIDE_BIT)))))) {
    sliderStepper.move(5);
    sliderPosition+=5;
    delay(5);
  }
  analogWrite(SLIDER_STEP,0);
}


/*
* Rotates the arm to it's home position.
* Parameters: direction: true for CW / false for CCW
*/
void arm::homeRotateArm(void){
   digitalWrite(ARM_DIR,CCW);
   while(!(((*SPIdata1) & (ARM_HOME_BIT)))) {
     analogWrite(ARM_STEP,255);
   }
   analogWrite(ARM_STEP,0);
   armStepper.move(720);
   armPosition = 0;
}


/*
* Rotates the arm until it either collides with a pole or reaches home
*/
void arm::poleRotateArm(void) {
  //TODO CHECK POLARITY
  while(!((*SPIdata1) & (ARM_HOME_BIT))) {
    armStepper.move(-5);
    armPosition-=5;
    delay(5);
  }
}

int arm::getLiftPosition(void) {
  return liftPosition;
}

int arm::getSliderPosition(void) {
  return sliderPosition;
}

int arm::getArmPosition(void) {
  return armPosition;
}

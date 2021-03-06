#include <arm.h>
#include <Arduino.h>
#include <constants.h>
#include <Servo.h>

/*
Arm.cpp contains all functions related to moving the arm including collection, dispensing, and other movement.
*/


//This is so you dont have to write constants:: every time you want to use it.
//Its not really good practice but its ok :P
using namespace constants;

//Motor Objects
Servo clawOpenServo;
Servo clawRotateServo;


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
  clawOpenServo.write(CLAW_OPEN_DEG);
  clawRotateServo.write(45);
}


/*
* Homes the larger components of the arm: the slider,lower the lifts and rotates it CW to home.
* Home is defined as the claw as being at the bottom of the lift, the slider retracted fully, and the arm rotated forwards
*/
void arm::homeArm(void) {
  homeSlider();
  homeClaw();
  homeRotateArm();
}


/*
* Extends the slider and lifts the claw/lift
*/
void arm::extendArm(void) {
  raiseClaw();
  extendSlider();
}

/*
* Sleeps all the stepper motors of the arm
*/
void arm::sleepArm(void) {
  digitalWrite(ARM_SLEEP,LOW);
  digitalWrite(SLIDER_SLEEP,LOW);
  digitalWrite(LIFT_SLEEP,LOW);
}

/*
* Wakes up all the stepper motors of the arm
*/
void arm::wakeupArm(void) {
  digitalWrite(ARM_SLEEP,HIGH);
  digitalWrite(SLIDER_SLEEP,HIGH);
  digitalWrite(LIFT_SLEEP,HIGH);
}


/*
* Moves the lift to a desired position
* Parameters: position (0- idk)
*/
void arm::moveLift(int position) {
  if(position > liftPosition) {
    digitalWrite(LIFT_DIR,UP);
  }
  else {
    digitalWrite(LIFT_DIR,DOWN);
  }
  for(int i = 0; i < abs(position - liftPosition); i++) {
    digitalWrite(LIFT_STEP,HIGH);
    delayMicroseconds(800);
    digitalWrite(LIFT_STEP,LOW);
    delayMicroseconds(800);
  }

  liftPosition = position;
}


/*
* Moves the slider to a desired position
* Parameters: position (0-idk)
*/
void arm::moveSlider(int position) {
  if(position > sliderPosition) {
    digitalWrite(SLIDER_DIR,FORWARDS);
  }
  else {
    digitalWrite(SLIDER_DIR,BACKWARDS);
  }
  for(int i = 0; i < abs(position - sliderPosition); i++) {
    digitalWrite(SLIDER_STEP,HIGH);
    delay(1);
    digitalWrite(SLIDER_STEP,LOW);
    delay(1);
  }

  liftPosition = position;

  sliderPosition = position;
}


/*
* Moves the arm to a desired position
* Parameters: position (-idk,idk)
*/
void arm::moveArm(int position) {
  if(position > armPosition) {
    digitalWrite(ARM_DIR,CW);
  }
  else {
    digitalWrite(ARM_DIR,CCW);
  }
  for(int i = 0; i < abs(position - armPosition); i++) {
    digitalWrite(ARM_STEP,HIGH);
    delay(2);
    digitalWrite(ARM_STEP,LOW);
    delay(2);
  }

  armPosition = position;
}


/*
* Dispenses all the stones into the gauntlet once already lined up
*/
void arm::dispenseStones(void) {
  digitalWrite(DISPENSER,HIGH);
}


/*
* Collects a stone and places it into the dispenser once the robot has parked beside it
* Parameters: stoneNumber is the number of stones already stored (0-3)
*/
void arm::collectStone(int stoneNumber) {
  homeArm();
  clawRotateServo.write(CLAW_COLLECT_DEG);
  extendSlider();
  poleRotateArm();
  Serial.println(armPosition);
  retractSlider();
  Serial.println(sliderPosition);
  openClaw();
  delay(400);
  lowerClaw();
  delay(400);
  Serial.println(liftPosition);
  closeClaw();
  delay(400);
  moveLift(LIFT_TOP_POSITION);
  extendSlider();
  moveArm(ARM_FRONT_POSITION);
  homeSlider();
  clawRotateServo.write(0);

}


/*
* Stores stone from claw to a spot on the flipper.
* Parameters: stoneNumber is the number of stones already stored (0-3)
*/
void arm::storeStone(int stoneNumber) {
  switch(stoneNumber){
    case 0:
          moveArm(ARM_STONE0);
          moveSlider(SLIDER_STONE0);
          clawRotateServo.write(CLAW_STONE0);
          break;
    case 1:
          moveArm(ARM_STONE1);
          moveSlider(SLIDER_STONE1);
          clawRotateServo.write(CLAW_STONE1);
          break;
    case 2:
          moveArm(ARM_STONE2);
          moveSlider(SLIDER_STONE2);
          clawRotateServo.write(CLAW_STONE2);
          break;
    case 3:
          moveArm(ARM_STONE3);
          moveSlider(SLIDER_STONE3);
          clawRotateServo.write(CLAW_STONE3);
          break;
  }
  moveLift(150);
  delay(300);
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
  digitalWrite(LIFT_DIR,DOWN);
  while((!(((*SPIdata1) & ((int)pow(2,CLAW_COLLIDE_BIT))))) && ((!(((*SPIdata1) & ((int)pow(2,LIFT_BOT_BIT))))))) {
    digitalWrite(LIFT_STEP,HIGH);
    delayMicroseconds(800);
    digitalWrite(LIFT_STEP,LOW);
    delayMicroseconds(800);
    liftPosition -= 1;
  }
}


/*
*  Lowers the claw to the lowest point
*/
void arm::homeClaw(void) {
  openClaw();
  clawRotateServo.write(CLAW_ROTATE_HOME);
  digitalWrite(LIFT_DIR,DOWN);
  while(!(((*SPIdata1) & ((int)pow(2,LIFT_BOT_BIT))))) {
      digitalWrite(LIFT_STEP,HIGH);
      delayMicroseconds(800);
      digitalWrite(LIFT_STEP,LOW);
      delayMicroseconds(800);
  }
  liftPosition = 0;
  delay(600);
  digitalWrite(LIFT_DIR,UP);
  for(int i = 0; i < LIFT_TOP_POSITION;i++) {
    digitalWrite(LIFT_STEP,HIGH);
    delayMicroseconds(800);
    digitalWrite(LIFT_STEP,LOW);
    delayMicroseconds(800);
  }
  liftPosition = LIFT_TOP_POSITION;
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
    digitalWrite(SLIDER_STEP,HIGH);
    delay(1);
    digitalWrite(SLIDER_STEP,LOW);
    delay(1);
  }
  digitalWrite(SLIDER_STEP,LOW);
  sliderPosition = 0;
}


/*
* Retracts the slider until it collides with a pole or comes home
*/
void arm::retractSlider(void){
  digitalWrite(SLIDER_DIR,BACKWARDS);
  while((!(((*SPIdata1) & ((int)pow(2,SLIDER_BACK_BIT))))) && (!(((*SPIdata1) & ((int)pow(2,HOOK_COLLIDE_BIT)))))) {
    digitalWrite(SLIDER_STEP,HIGH);
    delay(1);
    digitalWrite(SLIDER_STEP,LOW);
    delay(1);
    sliderPosition--;
  }
}


/*
* Rotates the arm to it's home position.
* Parameters: direction: true for CW / false for CCW
*/
void arm::homeRotateArm(void){
   digitalWrite(ARM_DIR,CCW);
   while(!(((*SPIdata1) & (ARM_HOME_BIT)))) {
     digitalWrite(ARM_STEP,HIGH);
     delay(2);
     digitalWrite(ARM_STEP,LOW);
     delay(2);
   }
   digitalWrite(ARM_STEP,LOW);
   delay(500);
   armPosition = 0;
   moveArm(ARM_FRONT_POSITION);
}


/*
* Rotates the arm until it either collides with a pole or reaches home
*/
void arm::poleRotateArm(void) {
  digitalWrite(ARM_DIR,CCW);
  while(!((*SPIdata1) & (ARM_HOME_BIT))) {
    digitalWrite(ARM_STEP,HIGH);
    delay(2);
    digitalWrite(ARM_STEP,LOW);
    delay(2);
    armPosition -= 1;
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

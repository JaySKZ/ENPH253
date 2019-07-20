#include <Arduino.h>
#include <arm.h>

void arm::homeArm(void) {
lowerClaw();
homeSlider();

}

void arm::extendArm(void) {

}

void arm::dispenseStones(void) {

}

void arm::collectStone(void) {

}


void arm::raiseClaw(void); {
  while(digitalRead(LIFT_TOP_SW)==FALSE) {
    analogWrite(LIFT_DIR_PIN, 255);
    analogWrite(LIFT_STEP_PIN, 255);
  }
  analogWrite(LIFT_STEP_PIN, 0);
}

void arm::lowerClaw(void) {
  while(digitalRead(LIFT_BOT_SW)==FALSE) {
    analogWrite(LIFT_DIR_PIN,0)
    analogWrite(LIFT_STEP_PIN,255);
  }
  analogWrite(LIFT_STEP_PIN,0);
}
void arm::extendSlider(void) {

}
void arm::homeSlider(void){

}
void arm::homeRotateArm(void){

}

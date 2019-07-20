#include <movement.h>

void movement::drive(void) {

}

void movement::pidDrive(void){

}

void movement::turnAround(void) {

}

void movement::checkSonars(void){

}

void movement::alignGauntlet(void) {

}

void killMotors(void) {
    analogWrite(LF_MOTOR,0);
    analogWrite(LR_MOTOR,0);
    analogWrite(RF_MOTOR,0);
    analogWrite(RR_MOTOR,0);
}

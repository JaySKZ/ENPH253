#include <movement.h>

//Pin Constants
#define LF_MOTOR 16
#define LR_MOTOR 17
#define RF_MOTOR 18
#define RR_MOTOR 19

//Tuning Paramaters
const int kp = 0.57;
const int kd = 5.7;
const int MAX_SPEED = 100;
const int BASE_SPEED = 80;


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

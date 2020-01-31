#include <movement.h>
#include <sensorbar.h>

using namespace constants;

SensorBar mySensorBar(SX1509_ADDRESS);
int *stones;
boolean *side;

/*
Drive.cpp contains all the functions related to movement of the robot through the drive motors.

This file needs a lot of thought and redesigning as we test things and make design decisions about whats best
Feel free to change
*/

movement::movement(int *stonesBehind, boolean *rightSide) {
    side = rightSide;
    stones = stonesBehind;
    intersectionCount = 0;

    uint8_t returnStatus = mySensorBar.begin();
        mySensorBar.clearInvertBits();

        if(returnStatus) {
                Serial.println("sx1509 IC communication OK");
        }
        else {
                Serial.println("sx1509 IC communication FAILED!");
        }

        position = mySensorBar.getPosition();

        motorSpeed = 0;
}

/*
* Drives the robot forwards throughout the course and makes turns itself
*/
void movement::drive(void) {
  position = mySensorBar.getPosition() + 127;
  rawValue = mySensorBar.getRaw();
  exists = intersection(rawValue);
  error = position - 127;

  if(position != 127) {
      motorSpeed = Kp * error + Kd * (error - lastError);
  }

  if(mySensorBar.getDensity() >= 3) {
    *stones++;
  }


//intersection
  if(!exists && intersectionCount == CHECK_FALSE_POSITIVE){
        if(*side == false) {
          //turnLeft();
        }
        else {
          //turnRight();
        }
    }

//intersection end
  lastError = error;

  rightMotorSpeed = RIGHT_BASE_SPEED - motorSpeed;
  leftMotorSpeed = LEFT_BASE_SPEED + motorSpeed;

  if (rightMotorSpeed > RIGHT_MAX_SPEED ) {
      rightMotorSpeed = RIGHT_MAX_SPEED;
  }
  if (leftMotorSpeed > LEFT_MAX_SPEED ) {
      leftMotorSpeed = LEFT_MAX_SPEED;
  }

  if (rightMotorSpeed < 0) {
      analogWrite(RR_MOTOR,50);
      rightMotorSpeed = 0;
  }
  else{
      analogWrite(RR_MOTOR,0);
  }
  if (leftMotorSpeed < 0) {
      analogWrite(LR_MOTOR,50);
      leftMotorSpeed = 0;
  }
  else {
      analogWrite(LR_MOTOR,0);
  }

  analogWrite(RF_MOTOR, rightMotorSpeed);
  analogWrite(LF_MOTOR, leftMotorSpeed);
}

boolean movement::intersection(int element) {
  for (int i = 0; i < NUM_MAX; i++) {
     if (intersectionCheck[i] == element) {
         return true;
     }
   }
 return false;
}

void movement::turnLeft() {

}

void movement::turnRight() {

}

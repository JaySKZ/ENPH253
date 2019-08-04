#pragma once
#include <Arduino.h>

namespace constants {

  //Pins
  const int CLAW_OPEN_PIN = 1000;
  const int CLAW_ROTATE_PIN = 1000;
  const int SLIDER_STEP = 8; //GOOD
  const int SLIDER_DIR = 7; //GOOD
  const int SLIDER_SLEEP = 1000;
  const int LIFT_STEP = 30; //GOOD
  const int LIFT_DIR = 29; //GOOD
  const int LIFT_SLEEP = 1000;
  const int ARM_STEP = 3; //GOOD
  const int ARM_DIR = 2; //GOOD
  const int ARM_SLEEP = 1000;
  const int DISPENSE_PIN = 1000;
  const int LATCH = 5; //GOOD
  const int LF_MOTOR = 35; //GOOD
  const int LR_MOTOR = 36; //GOOD
  const int RF_MOTOR = 38;
  const int RR_MOTOR = 37; //GOOD
  const int SIDE_SWITCH = 1000;
  const int DISPENSER = 1000;

  //Byte Order: 0 is farthest right, represents 2^0
  const int LIFT_BOT_BIT = 7; //GOOD
  const int SLIDER_BACK_BIT = 2; //GOOD
  const int ARM_HOME_BIT = 58; //GOOD
  const int CLAW_COLLIDE_BIT = 5;
  const int HOOK_COLLIDE_BIT = 6; //GOOD
  const int ARM_COLLIDE_BIT = 58; //GOOD AND 4 5 6

  //Directions
  #define UP HIGH //GOOD
  #define DOWN LOW //GOOD
  #define FORWARDS HIGH //GOOD
  #define BACKWARDS LOW //GOOD
  #define CW HIGH //GOOD
  #define CCW LOW //GOOD

  //Stone storing distances
  const int ARM_STONE0 = 0;
  const int ARM_STONE1 = 0;
  const int ARM_STONE2 = 0;
  const int ARM_STONE3 = 0;
  const int SLIDER_STONE0 = 0;
  const int SLIDER_STONE1 = 0;
  const int SLIDER_STONE2 = 0;
  const int SLIDER_STONE3 = 0;
  const int CLAW_STONE0 = 0;
  const int CLAW_STONE1 = 0;
  const int CLAW_STONE2 = 0;
  const int CLAW_STONE3 = 0;
  const int CLAW_OPEN_DEG = 0;
  const int CLAW_CLOSE_DEG = 0;

  //End of belt distances
  const int SLIDER_FRONT_POSITION = 860; //GOOD
  const int LIFT_TOP_POSITION = 900; //GOOD
  const int ARM_FRONT_POSITION = 700; //GOOD

  //Misc
  const int SPI_TIMING = 1000; //microseconds
  const int DESIRED_STONES = 1;

  //Tuning Paramaters
  const float Kp = 0.57;
  const float Kd = 5.7;
  #define RIGHT_MAX_SPEED 150 //150|| 150 || 150 ||150 //max speed of the robot
  #define LEFT_MAX_SPEED 150 //150 || 150 || 150 ||150 //max speed of the robot
  #define RIGHT_BASE_SPEED 75//60 || 65|| 67 ||70|| this is the speed at which the motors should spin when the robot is perfectly on the line
  #define LEFT_BASE_SPEED 75  // 60 || 65|| 67||70|| this is the speed at which the motors should spin when the robot is perfectly on the line
  const uint8_t SX1509_ADDRESS = 0x3E;
  const int CHECK_FALSE_POSITIVE = 10;
  const int intersectionCheck[] = {0,1,2,3,4,6,7,8,12,14,15,16,24,28,30,31,32,48,56,60,62,63,64,96,112,120,124,126,127,128,192,224,240,248,252,254,255};
  const int NUM_MAX = sizeof(intersectionCheck)/sizeof(intersectionCheck[0]);
}

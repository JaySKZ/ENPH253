#pragma once

  //Pins
  #define SLIDE_STEP 6
  #define SLIDE_DIR 5
  #define LIFT_STEP 4
  #define LIFT_DIR 3
  #define ARM_STEP A16
  #define ARM_DIR A16
  #define DISPENSE_PIN A16
  #define LATCH 2
  #define LF_MOTOR 16
  #define LR_MOTOR 17
  #define RF_MOTOR 18
  #define RR_MOTOR 19

  //Byte Order: 0 is farthest right, represents 2^0
  #define LIFT_TOP_BIT 0
  #define LIFT_BOT_BIT 0
  #define SLIDE_FRONT_BIT 2
  #define SLIDE_BACK_BIT 1
  #define ARM_HOME_BIT 4

  //Directions
  #define UP LOW
  #define DOWN HIGH
  #define FORWARDS LOW
  #define BACKWARDS HIGH
  #define CW HIGH
  #define CCW LOW

  //Misc
  #define SPI_TIMING 1000 //microseconds

  //Tuning Paramaters
  const int kp = 0.57;
  const int kd = 5.7;
  const int MAX_SPEED = 100;
  const int BASE_SPEED = 80;

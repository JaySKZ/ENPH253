#pragma once

namespace constants {
  //Pins
  const int CLAW_OPEN_PIN = 7;
  const int CLAW_ROTATE_PIN = 8;
  const int SLIDER_STEP = 6;
  const int SLIDER_DIR = 5;
  const int LIFT_STEP = 4;
  const int LIFT_DIR = 3;
  const int ARM_STEP = 16;
  const int ARM_DIR = 16;
  const int DISPENSE_PIN = 16;
  const int LATCH = 2;
  const int LF_MOTOR = 16;
  const int LR_MOTOR = 17;
  const int RF_MOTOR = 18;
  const int RR_MOTOR = 19;

  //Byte Order: 0 is farthest right, represents 2^0
  const int LIFT_BOT_BIT = 0;
  const int SLIDER_BACK_BIT = 1;
  const int ARM_HOME_BIT = 4;
  const int CLAW_COLLIDE_BIT = 5;
  const int HOOK_COLLIDE_BIT = 6;
  const int ARM_COLLIDE_BIT = 7;

  //Directions
  #define UP LOW
  #define DOWN HIGH
  #define FORWARDS LOW
  #define BACKWARDS HIGH
  #define CW HIGH
  #define CCW LOW

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
  const int SLIDER_FRONT_POSITION = 0;
  const int LIFT_TOP_POSITION = 0;

  //Misc
  const int SPI_TIMING = 1000; //microseconds

  //Tuning Paramaters
  const int kp = 0.57;
  const int kd = 5.7;
  const int MAX_SPEED = 100;
  const int BASE_SPEED = 80;
}

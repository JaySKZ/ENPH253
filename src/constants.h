#pragma once

namespace constants {
  //Pins
  const int CLAW_OPEN_PIN = 1000;
  const int CLAW_ROTATE_PIN = 1000;
  const int SLIDER_STEP = 8; //GOOD
  const int SLIDER_DIR = 7; //GOOD
  const int LIFT_STEP = 30; //GOOD
  const int LIFT_DIR = 29; //GOOD
  const int ARM_STEP = 2; //GOOD
  const int ARM_DIR = 1; //GOOD
  const int DISPENSE_PIN = 1000;
  const int LATCH = 6; //GOOD
  const int LF_MOTOR = 35; //GOOD
  const int LR_MOTOR = 36; //GOOD
  const int RF_MOTOR = 38;
  const int RR_MOTOR = 37; //GOOD

  //Byte Order: 0 is farthest right, represents 2^0
  const int LIFT_BOT_BIT = 7; //GOOD
  const int SLIDER_BACK_BIT = 2; //GOOD
  const int ARM_HOME_BIT = 58;
  const int CLAW_COLLIDE_BIT = 5;
  const int HOOK_COLLIDE_BIT = 6; //GOOD
  const int ARM_COLLIDE_BIT = 58; //GOOD AND 4 5 6

  //Directions
  #define UP HIGH //GOOD
  #define DOWN LOW //GOOD
  #define FORWARDS LOW //GOOD
  #define BACKWARDS HIGH //GOOD
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
  const int DISPENSER_POSITION = 0;

  //End of belt distances
  const int SLIDER_FRONT_POSITION = -860;
  const int LIFT_TOP_POSITION = 920;

  //Misc
  const int SPI_TIMING = 1000; //microseconds
  const int DESIRED_STONES = 3;

  //Tuning Paramaters
  const int kp = 0.57;
  const int kd = 5.7;
  const int MAX_SPEED = 100;
  const int BASE_SPEED = 80;
}

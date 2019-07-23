#pragma once
#include <Arduino.h>

//Motor Pins
#define SLIDE_STEP 6
#define SLIDE_DIR 5
#define LIFT_STEP 4
#define LIFT_DIR 3
#define ARM_STEP A16
#define ARM_DIR A16
#define DISPENSE_PIN A16

//Byte Order: 0 is farthest right, represents 2^0
#define LIFT_TOP_BIT 0
#define LIFT_BOT_BIT 0
#define SLIDE_FRONT_BIT 2
#define SLIDE_BACK_BIT 1
#define ARM_HOME_BIT 4

//Constants
#define UP LOW
#define DOWN HIGH
#define FORWARDS 0
#define BACKWARDS 255
#define CW 255
#define CCW 0


class arm
{
    public:
    arm(uint8_t *SPI1, uint8_t *SPI2);
    void homeArm(void);
    void extendArm(void);
    void dispenseStones(void);
    void collectStone(void);

    void raiseClaw(void);
    void lowerClaw(void);
    void extendSlider(void);
    void homeSlider(void);
    void homeRotateArm(bool direction);

    private:


    uint8_t *SPIdata1;
    uint8_t *SPIdata2;

};

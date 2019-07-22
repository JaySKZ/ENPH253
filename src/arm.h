#pragma once
#include <Arduino.h>

//Motor Pins
#define SLIDE_STEP A16
#define SLIDE_DIR A16
#define LIFT_STEP A16
#define LIFT_DIR A16
#define ARM_STEP A16
#define ARM_DIR A16
#define DISPENSE_PIN A16

//Byte Order: 0 is farthest right, represents 2^0
#define LIFT_TOP_BI 0
#define LIFT_BOT_BI 1
#define SLIDE_FRONT_BI 2
#define SLIDE_BACK_BI 3
#define ARM_HOME_BI 4

//Constants
#define UP 255
#define DOWN 0
#define FORWARDS 255
#define BACKWARDS 0
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

    private:
    void raiseClaw(void);
    void lowerClaw(void);
    void extendSlider(void);
    void homeSlider(void);
    void homeRotateArm(bool direction);

    uint8_t *SPIdata1;
    uint8_t *SPIdata2;

};

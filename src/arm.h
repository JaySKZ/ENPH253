#pragma once
#include <Arduino.h>

//Switch Pins
#define LIFT_TOP_SW A16
#define LIFT_BOT_SW A16
#define SLIDE_FRONT_SW A16
#define SLIDE_BACK_SW A16
#define ARM_HOME_SW A16

//Motor Pins
#define SLIDE_STEP A16
#define SLIDE_DIR A16
#define LIFT_STEP A16
#define LIFT_DIR A16
#define ARM_STEP A16
#define ARM_DIR A16


class arm
{
    public:
    void homeArm(void);
    void extendArm(void);
    void dispenseStones(void);
    void collectStone(void);

    private:
    void raiseClaw(void);
    void lowerClaw(void);
    void extendSlider(void);
    void homeSlider(void);
    void homeRotateArm(void);

};

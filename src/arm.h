#pragma once
#include <Arduino.h>

//Switch Pins
#define LIFT_TOP_SW
#define LIFT_BOT_SW
#define SLIDE_FRONT_SW
#define SLIDE_BACK_SW
#define ARM_HOME_SW

//Motor Pins
#define SLIDE_STEP
#define SLIDE_DIR
#define LIFT_STEP
#define LIFT_DIR
#define ARM_STEP
#define ARM_DIR


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
    void homeArmRotate(void);

};

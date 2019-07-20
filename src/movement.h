#pragma once
#include <Arduino.h>

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


class movement
{
    public:
    void drive(void);


    private:
    void pidDrive(void);
    void turnAround(void);
    void checkSonars(void);
    void alignGauntlet(void);
    void killMotors(void);
};

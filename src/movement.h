#pragma once
#include <Arduino.h>


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
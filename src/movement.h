#pragma once
#include <Arduino.h>
#include <constants.h>

class movement
{
    public:
    movement(int *stonesBehind, boolean *rightSide);
    void drive(void);


    private:
    boolean intersection(int element);
    void turnLeft();
    void turnRight();
    int intersectionCount;
    uint8_t position;
    int motorSpeed;
    uint8_t rawValue;
    bool exists;
    int error;
    int lastError;
    int leftMotorSpeed;
    int rightMotorSpeed;

};

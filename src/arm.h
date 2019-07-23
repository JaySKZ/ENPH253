#pragma once
#include <Arduino.h>
#include <constants.h>


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
    void homeClaw(void);
    void extendSlider(void);
    void homeSlider(void);
    void homeRotateArm(bool direction);

    private:
    uint8_t *SPIdata1;
    uint8_t *SPIdata2;

};

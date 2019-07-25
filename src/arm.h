#pragma once
#include <constants.h>
#include <Arduino.h>

class arm
{
    public:
    arm(uint8_t *SPI1, uint8_t *SPI2);

    void homeArm(void);
    void extendArm(void);

    void moveSlider(int position);
    void moveLift(int position);
    void moveArm(int position);

    void dispenseStones(void);
    void collectStone(int stoneNumber);
    void storeStone(int stoneNumber);

    void raiseClaw(void);
    void lowerClaw(void);
    void openClaw(void);
    void closeClaw(void);
    void homeClaw(void);

    void extendSlider(void);
    void retractSlider(void);
    void homeSlider(void);

    void homeRotateArm(bool direction);
    void poleRotateArm(void);

    private:
    uint8_t *SPIdata1;
    uint8_t *SPIdata2;
    int liftPosition;
    int armPosition;
    int sliderPosition;
};

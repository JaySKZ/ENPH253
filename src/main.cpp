#include <Arduino.h>
#include <movement.h>
#include <arm.h>
#include <SPI.h>

//Create Variables
IntervalTimer myTimer;
volatile uint8_t limitSwitches;

//Constants
#define SPI_TIMING 1000

//Function Declarations
void updateSPI();


void setup() {
  //Initiate Processes
  myTimer.begin(updateSPI, SPI_TIMING);
  SPI.begin();
}

void loop() {
}

void updateSPI() {
  noInterrupts();



  interrupts();
}

#include <Arduino.h>
#include <movement.h>
#include <arm.h>
#include <SPI.h> //Serial communication
#include <bitset> //For converting integers to binary

//Create Variables
IntervalTimer myTimer;
uint8_t SPIdata1;
uint8_t SPIdata2;
arm robotarm(&SPIdata1, &SPIdata2);
movement robotmovement;

//Constants
#define SPI_TIMING 1000000 //microseconds
#define LATCH 23

//Function Declarations
void updateSPI();


void setup() {
  //Initiate Processes
  Serial.begin(112500);
  //SPI
  SPI.begin();
  pinMode(LATCH, OUTPUT);
  digitalWrite(LATCH, HIGH);
  myTimer.begin(updateSPI, SPI_TIMING);


  //Create arm and movement objects

}

void loop() {
}

/*
* Updates the digital data from the robots limit switches
*/
void updateSPI() {
  noInterrupts();

  digitalWrite(LATCH,LOW);
  digitalWrite(LATCH,HIGH);

  SPIdata1 = SPI.transfer(0);
  SPIdata2 = SPI.transfer(0);

  interrupts();
}

#include <Arduino.h>
#include <movement.h>
#include <arm.h>
#include <SPI.h> //Serial communication
#include <bitset> //For converting integers to binary
#include <A4988.h> //Stepper driver libary
#include <constants.h>

//State Variables
IntervalTimer myTimer;
uint8_t SPIdata1;
uint8_t SPIdata2;
//Objects
arm robotarm (&SPIdata1, &SPIdata2);
movement robotmovement;
A4988 liftStepper (200,3,4);

//Function Declarations
void updateSPI();
void initializePins();

void setup() {
  //Initiate Processes
  Serial.begin(9600);
  liftStepper.begin(300,1);

  //SPI
  SPI.begin();
  pinMode(LATCH, OUTPUT);
  digitalWrite(LATCH, HIGH);
  myTimer.begin(updateSPI, SPI_TIMING);

  initializePins();
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
//  SPIdata2 = SPI.transfer(0);

  interrupts();
}

void initializePins() {
  pinMode(3,OUTPUT);
  digitalWrite(3,LOW);
  pinMode(5,OUTPUT);
  digitalWrite(5,LOW);
  analogWrite(4,0);
  analogWrite(6,0);
}

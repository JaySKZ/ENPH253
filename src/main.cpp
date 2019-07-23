#include <Arduino.h>
#include <movement.h>
#include <arm.h>
#include <SPI.h> //Serial communication
#include <bitset> //For converting integers to binary

//Create Variables
IntervalTimer myTimer;
uint8_t SPIdata1;
uint8_t SPIdata2;
arm robotarm (&SPIdata1, &SPIdata2);
movement robotmovement;
int count = 0;

//Constants
#define SPI_TIMING 1000 //microseconds
#define LATCH 2

//Function Declarations
void updateSPI();


void setup() {
  //Initiate Processes
  Serial.begin(9600);
  //SPI
  SPI.begin();
  pinMode(LATCH, OUTPUT);
  digitalWrite(LATCH, HIGH);
  myTimer.begin(updateSPI, SPI_TIMING);

  //Initialize Pins
  pinMode(3,OUTPUT);
  digitalWrite(3,LOW);
  pinMode(5,OUTPUT);
  digitalWrite(5,LOW);
  analogWrite(4,0);
  analogWrite(6,0);
}

void loop() {
  robotarm.homeSlider();
  robotarm.lowerClaw();
  delay(5000);
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

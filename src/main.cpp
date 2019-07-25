#include <Arduino.h>
#include <movement.h>
#include <arm.h>
#include <SPI.h> //Serial communication
#include <constants.h>

//State Variables
IntervalTimer myTimer;
uint8_t SPIdata1;
uint8_t SPIdata2;
enum State {Drive,Collection,Dispense,Done};
State state;
int stonesBehind;
//Objects
arm robotarm (&SPIdata1, &SPIdata2);
movement robotmovement(&stonesBehind);
//Function Declarations
void updateSPI();
void initializePins();

void setup() {
  state = Drive;
  stonesBehind = 0;
  //Initiate Processes
  Serial.begin(9600);

  //SPI
  SPI.begin();
  pinMode(constants::LATCH, OUTPUT);
  digitalWrite(constants::LATCH, HIGH);
  myTimer.begin(updateSPI, constants::SPI_TIMING);

  initializePins();
  robotarm.homeArm();
}

void loop() {
  switch(state) {
    case Drive:
      while(stonesBehind != constants::DESIRED_STONES) {
      //drive();
    }
      if(stonesBehind == constants::DESIRED_STONES) {
        state = Collection;
      }
      break;

    case Collection:
      robotarm.collectStone(constants::DESIRED_STONES-stonesBehind);
    //  drive();
      if(stonesBehind == 0) {
        state = Dispense;
      }
      break;

    case Dispense:
    //  drive();
      robotarm.dispenseStones();
      break;

    case Done:
      //killMotors();
      //celebration();
      break;
  }
}

/*
* Updates the digital data from the robots limit switches
*/
void updateSPI() {
  noInterrupts();

  digitalWrite(constants::LATCH,LOW);
  digitalWrite(constants::LATCH,HIGH);

  SPIdata1 = SPI.transfer(0);
//  SPIdata2 = SPI.transfer(0);

  interrupts();
}

void initializePins() {
  //TODO
  pinMode(3,OUTPUT);
  digitalWrite(3,LOW);
  pinMode(5,OUTPUT);
  digitalWrite(5,LOW);
  analogWrite(4,0);
  analogWrite(6,0);
}

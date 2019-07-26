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

  //robotarm.homeArm();
  initializePins();

  robotarm.collectStone(1);
}

void loop() {
  /*
  robotarm.homeClaw();
  Serial.println(robotarm.getLiftPosition());
  robotarm.moveLift(400);
  Serial.println(robotarm.getLiftPosition());
  delay(2000);
  */
  /*
  Serial.printf("LIFT POSITION: ");
  Serial.println(robotarm.getLiftPosition());
  Serial.printf("ARM POSITION: ");
  Serial.println(robotarm.getArmPosition());
  Serial.printf("SLIDER POSITION: ");
  Serial.println(robotarm.getSliderPosition());
  delay(2000);
  */
  /*
  Serial.printf("DATA1: ");
  Serial.println(SPIdata1);
  Serial.printf("\n");
  Serial.printf("DATA2: ");
  Serial.println(SPIdata2);
  Serial.printf("\n");
  delay(1000);
*/




/*
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
  */

}

/*
* Updates the digital data from the robots limit switches
*/
void updateSPI() {

  noInterrupts();

  digitalWrite(constants::LATCH,LOW);
  digitalWrite(constants::LATCH,HIGH);

  SPIdata2 = SPI.transfer(0);
  SPIdata1 = SPI.transfer(0);

  interrupts();

}

void initializePins() {
  pinMode(constants::LIFT_DIR,OUTPUT);
  pinMode(constants::SLIDER_DIR,OUTPUT);
  pinMode(constants::ARM_DIR,OUTPUT);
  digitalWrite(constants::LIFT_DIR,LOW);
  digitalWrite(constants::SLIDER_DIR,LOW);
  digitalWrite(constants::ARM_DIR,LOW);
  digitalWrite(constants::LIFT_STEP,LOW);
  digitalWrite(constants::SLIDER_STEP,LOW);
  digitalWrite(constants::ARM_STEP,LOW);
}

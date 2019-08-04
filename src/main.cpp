#include <Arduino.h>
#include <constants.h>
#include <movement.h>
#include <arm.h>
#include <SPI.h> //Serial communication

//State Variables
IntervalTimer myTimer;
uint8_t SPIdata1;
uint8_t SPIdata2;
enum State {Drive,Collection,Dispense,Done};
State state;
int stonesBehind;
int count;
boolean rightSide = false;

//Objects
arm robotarm (&SPIdata1, &SPIdata2);

movement robotmovement(&stonesBehind, &rightSide);
//Function Declarations
void updateSPI();
void initializePins();

void setup() {
  count = 0;
  state = Drive;
  stonesBehind = 0;
  if(digitalRead(constants::SIDE_SWITCH) == HIGH) {
    rightSide = true;
  }

  //Initiate Processes
  Serial.begin(9600);

  //SPI
  SPI.begin();
  pinMode(constants::LATCH, OUTPUT);
  digitalWrite(constants::LATCH, HIGH);
  myTimer.begin(updateSPI, constants::SPI_TIMING);


  initializePins();

  //This is the command that i've been changing for testing bullshit.
  robotarm.homeRotateArm();
}

void loop() {
  Serial.println(count);
  Serial.println(SPIdata2,BIN);
  Serial.println(SPIdata1,BIN);
  count++;
  delay(1000);
/*
  switch(state) {
    case Drive:
      while(stonesBehind != constants::DESIRED_STONES) {
      //robotmovement.drive();
    }
      if(stonesBehind == constants::DESIRED_STONES) {
        state = Collection;
      }
      break;

    case Collection:
      robotarm.collectStone(constants::DESIRED_STONES-stonesBehind);
      if(side == Left) {
    //  robotmovement.turnAroundLeft();
  }
    else {
        robotmovement.turnAroundRight();
  }
    //  robotmovement.drive();
      if(stonesBehind == 0) {
        state = Dispense;
      }
      break;

    case Dispense:
    //  robotmovement.drive();
    //  robotmovement.alignGauntlet();
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
  pinMode(constants::LIFT_STEP,OUTPUT);
  pinMode(constants::SLIDER_STEP,OUTPUT);
  pinMode(constants::ARM_STEP,OUTPUT);
  pinMode(constants::DISPENSER,OUTPUT);
  digitalWrite(constants::LIFT_DIR,LOW);
  digitalWrite(constants::SLIDER_DIR,LOW);
  digitalWrite(constants::ARM_DIR,LOW);
  digitalWrite(constants::LIFT_STEP,LOW);
  digitalWrite(constants::SLIDER_STEP,LOW);
  digitalWrite(constants::ARM_STEP,LOW);
  digitalWrite(constants::DISPENSER,LOW);
  analogWrite(constants::LF_MOTOR,0);
  analogWrite(constants::LR_MOTOR,0);
  analogWrite(constants::RF_MOTOR,0);
  analogWrite(constants::RR_MOTOR,0);
}

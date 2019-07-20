// Pin connections for Uno and similar:
// https://www.pjrc.com/teensy/td_libs_SPI.html
// Chip pin 1 (/PL)  goes to LATCH (D9)  (or any other pin by changing LATCH below)
// Chip pin 2 (CP)   goes to SCK   (D13)
// Chip pin 9 (Q7)   goes to MISO  (D12)


#include <SPI.h>

const byte LATCH = 9;

void setup ()
{
  SPI.begin ();
  // Can bump this up a lot more if needed
  Serial.begin (9600);
  Serial.println ("Begin switch test.");
  pinMode (LATCH, OUTPUT);
  digitalWrite (LATCH, HIGH);
}  // end of setup

// Not 100% necessary to set zero for bytes but still good practice
byte byte1 = 0b00000000;
byte byte2 = 0b00000000;
byte byte3 = 0b00000000;

void loop ()
{
  digitalWrite (LATCH, LOW);
  digitalWrite (LATCH, HIGH); // clock the data in - or whatever the HC165 needs to capture the data
  byte1 = SPI.transfer(0);  // send out dummy byte while reading in data at the same time
  byte2 = SPI.transfer(0);
  byte3 = SPI.transfer(0);

  Serial.print("Juan: ");
  Serial.println(byte1, BIN); // Arduino printing as BIN skips beginning bits of they are zero, so 00001111 => 1111
  Serial.print("Too: ");
  Serial.println(byte2, BIN);
  Serial.print("Free: ");
  Serial.println(byte3, BIN);
  
  delay (5000);   // debounce via timing lmao
}  // end of loop

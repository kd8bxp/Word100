#include "Arduino.h"
#include "Word100.h"
#include <SPI.h>

/*
The "100+ Word" Arduino Audio Shield! Speak Arduino, Speak!
by Patrick Thomas Mitchell
http://www.engineeringshock.com/100-word-arduino-audio-shield.html
Library version 1.0 by LeRoy Miller

If you find this or any of my projects useful or enjoyable please support me.  
Anything I do get goes to buy more parts and make more/better projects.  
https://www.patreon.com/kd8bxp  
https://ko-fi.com/lfmiller  

Copyright (c) 2017 LeRoy Miller

This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses>
*/

// Connect pin#13 (SCLK) To S2 on AP23 
// Connect pin#11 (DATOUT) To S3 on AP23 
// Connect pin#13 (SCLK) To S2 on AP23 
// Connect pin#10 (CS) To S1 on AP23
// GPIO 9 = STOP
// DO from Ap23 optional S4 - Not used here
// ** Add stop bit so that MCU knows then  the chip has stopped talking.  OUT1 is what you'll want to use
#define _STOP 9      // The STOP wire is the busy signal of the 
#define _PLAY 0x98
#define _RAMPUP 0xA8 //COUT ramp up - this value never changes
#define _RAMPDOWN 0xB8 //COUT ram down


Word100::Word100(int cs) {
_cs = cs;
}

void Word100::begin() {
pinMode(_STOP,INPUT);     // Set the "STOP" GPIO as an input.  This is the busy signal, and is high when the shield is busy playing a word
  SPI.begin();             // Initialize SPI
  SPI.setClockDivider(SPI_CLOCK_DIV32); // low frequency SPI
  pinMode(_cs,OUTPUT);    // Chip select pins is an output
  digitalWrite(_cs,HIGH); // Set chip select to be HIGH (5v) by default.  The chip on the shield is selected when this line is brought low. 
  SPI.setBitOrder(MSBFIRST);  // OTP requires MSB first
  SPI.setDataMode(SPI_MODE0);  // Use MODE0, as all other modes to not work
  delay(1000);   // One second delay
}

void Word100::say(int value)    // Calling this function reads words individually
{
  // ramp up
  digitalWrite(_cs,LOW);
  SPI.transfer(_RAMPUP);
  SPI.transfer(0x00);
  digitalWrite(_cs,HIGH);
  delay(7);
  // Transmit Data
  digitalWrite(_cs,LOW);
  SPI.transfer(_PLAY);
  SPI.transfer(value);
  digitalWrite(_cs,HIGH);
  delay(5);
  while (digitalRead(_STOP) == HIGH) { 
       {}
    } 
  //delay(5);
  // ramp down
  digitalWrite(_cs,LOW);
  SPI.transfer(_RAMPDOWN);
  SPI.transfer(0x00);
  digitalWrite(_cs,HIGH);
  delay(10);
  // YOU REALLY NEED TO ADD A STOP INPUT HERE, OR ELSE YOU'RE REALLY WASTING POWER!
}

Word100ham::Word100ham(int cs) {
_cs = cs;
}

void Word100ham::begin() {
pinMode(_STOP,INPUT);     // Set the "STOP" GPIO as an input.  This is the busy signal, and is high when the shield is busy playing a word
  SPI.begin();             // Initialize SPI
  SPI.setClockDivider(SPI_CLOCK_DIV32); // low frequency SPI
  pinMode(_cs,OUTPUT);    // Chip select pins is an output
  digitalWrite(_cs,HIGH); // Set chip select to be HIGH (5v) by default.  The chip on the shield is selected when this line is brought low. 
  SPI.setBitOrder(MSBFIRST);  // OTP requires MSB first
  SPI.setDataMode(SPI_MODE0);  // Use MODE0, as all other modes to not work
  delay(1000);   // One second delay
}

void Word100ham::say(int value)    // Calling this function reads words individually
{
  // ramp up
  digitalWrite(_cs,LOW);
  SPI.transfer(_RAMPUP);
  SPI.transfer(0x00);
  digitalWrite(_cs,HIGH);
  delay(7);
  // Transmit Data
  digitalWrite(_cs,LOW);
  SPI.transfer(_PLAY);
  SPI.transfer(value);
  digitalWrite(_cs,HIGH);
  delay(5);
  while (digitalRead(_STOP) == HIGH) { 
       {}
    } 
  //delay(5);
  // ramp down
  digitalWrite(_cs,LOW);
  SPI.transfer(_RAMPDOWN);
  SPI.transfer(0x00);
  digitalWrite(_cs,HIGH);
  delay(10);
  // YOU REALLY NEED TO ADD A STOP INPUT HERE, OR ELSE YOU'RE REALLY WASTING POWER!
}

Word100lbt::Word100lbt(int cs) {
_cs = cs;
}

void Word100lbt::begin() {
//pinMode(_STOP,INPUT);     // Set the "STOP" GPIO as an input.  This is the busy signal, and is high when the shield is busy playing a word
  SPI.begin();             // Initialize SPI
  SPI.setClockDivider(SPI_CLOCK_DIV32); // low frequency SPI
  pinMode(_cs,OUTPUT);    // Chip select pins is an output
  digitalWrite(_cs,HIGH); // Set chip select to be HIGH (5v) by default.  The chip on the shield is selected when this line is brought low. 
  SPI.setBitOrder(MSBFIRST);  // OTP requires MSB first
  SPI.setDataMode(SPI_MODE0);  // Use MODE0, as all other modes to not work
  delay(1000);   // One second delay
  digitalWrite(_cs, LOW);
  SPI.transfer(_RAMPUP);
  SPI.transfer(0x00);
  digitalWrite(_cs,HIGH);
}

void Word100lbt::say(int value)    // Calling this function reads words individually
{
  // ramp up
//digitalWrite(_cs,LOW);
 // SPI.transfer(_RAMPUP);
  //SPI.transfer(0x00);
  //digitalWrite(_cs,HIGH);
  delay(7);
  // Transmit Data
  digitalWrite(_cs,LOW);
  SPI.transfer(_PLAY);
  SPI.transfer(value);
  digitalWrite(_cs,HIGH);
  delay(700); 
  //while (digitalRead(_STOP) == HIGH) { 
   //    {}
   // } 
  //delay(5);
  // ramp down
  //digitalWrite(_cs,LOW);
  //SPI.transfer(_RAMPDOWN);
  //SPI.transfer(0x00);
  //digitalWrite(_cs,HIGH);
  //delay(10);
  // YOU REALLY NEED TO ADD A STOP INPUT HERE, OR ELSE YOU'RE REALLY WASTING POWER!
}

#include "Arduino.h"
#include "Word100.h"

#if SSPI_MODE
#include <SoftwareSPI.h>
// this SSPI demo uses the UNO SPI pins for convenience
#define SCK_PIN 13
#define MISO_PIN 12
#define MOSI_PIN 11
#define CS_PIN 10
#define SELECT *csReg &= ~csBit;
#define DESELECT *csReg |= csBit;
#else
#include <SPI.h>
#endif

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
Word100:setAMPM(1);
}

void Word100::begin() {

pinMode(_STOP,INPUT);     // Set the "STOP" GPIO as an input.  This is the busy signal, and is high when the shield is busy playing a word
#if SSPI_MODE
uint8_t success = SSPI.begin(SCK_PIN, MISO_PIN, MOSI_PIN);
SSPI.makeRegMask(CS_PIN, &csReg, &csBit, OUTPUT);
#else
  SPI.begin();             // Initialize SPI
  SPI.setClockDivider(SPI_CLOCK_DIV32); // low frequency SPI  
  SPI.setBitOrder(MSBFIRST);  // OTP requires MSB first
  SPI.setDataMode(SPI_MODE0);  // Use MODE0, as all other modes to not work
#endif
pinMode(_cs,OUTPUT);    // Chip select pins is an output
  digitalWrite(_cs,HIGH); // Set chip select to be HIGH (5v) by default.  The chip on the shield is selected when this line is brought low. 
  delay(1000);   // One second delay
}

void Word100::say(int value)    // Calling this function reads words individually
{
#if SSPI_MODE
  // ramp up
  digitalWrite(_cs,LOW);
  SSPI.transfer(_RAMPUP);
  SSPI.transfer(0x00);
  digitalWrite(_cs,HIGH);
  delay(7);
  // Transmit Data
  digitalWrite(_cs,LOW);
  SSPI.transfer(_PLAY);
  SSPI.transfer(value);
  digitalWrite(_cs,HIGH);
  delay(5);
  while (digitalRead(_STOP) == HIGH) { 
       {}
    } 
  //delay(5);
  // ramp down
  digitalWrite(_cs,LOW);
  SSPI.transfer(_RAMPDOWN);
  SSPI.transfer(0x00);
  digitalWrite(_cs,HIGH);
  delay(10);
  // YOU REALLY NEED TO ADD A STOP INPUT HERE, OR ELSE YOU'RE REALLY WASTING POWER!
#else
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
#endif
}

/* Portions of this code based on example by Matt Ganis (matt.ganis@gmail.com) or @mattganis on Twitter
 *  Copyright (c) 2018 Matt Ganis
 *  New functions: sayNumber(), sayHours(), sayMinutes()
 */

int Word100::sayMinutes(long number) {
if (number == 0) {
    
  Word100::say(_ZERO);   //special case for zero
   return 0;
}

  int _period = number;
  int _tens = _period / TEN;
   if (_tens == 1) {
         Word100::say(_sayTens[_period-10]);
		            
         _period = 0; }
                 
   if (_tens > 1) {
      	 Word100::say(_sayDecades[_tens]);
	     _period = _period - _tens*TEN; } else {
           Word100::say(_ZERO);
		       }
          
   if (_period == 0)  { return 0; } else {
         Word100::say(_sayDigits[_period]);
			}
if (_AMPM == 1) {
	Word100::say(_sayAMPM); }
}

int Word100::sayHours(long number) {
if (number == 0) {
   
	 Word100::say(_ZERO);   //special case for zero
	 return 0;
}

int _period = number;

if (_AMPM == 1) {
 if (_period >= 13) { _period = _period -12;}
 if (number < 12) {_sayAMPM = _AM_; } else {_sayAMPM = _PM_; }
}

  int _tens = _period / TEN;
   if (_tens == 1) {
		    
		Word100::say(_sayTens[_period-10]);
		         
         _period = 0; }
                 
   if (_tens > 1) {
       	Word100::say(_sayDecades[_tens]);
		 
       _period = _period - _tens*TEN; } 
          
   if (_period == 0)  { return 0; } else {
		Word100::say(_sayDigits[_period]);
		
	  }
}

int Word100::sayPeriod(int _period) {

int _hundreds = _period / HUNDRED;

if (_hundreds != 0) {
		
	Word100::say(_sayDigits[_hundreds]);
	Word100::say(_HUNDRED);
	_period = _period - (_hundreds * HUNDRED);
	}

int _tens = _period / TEN;

if (_tens == 1) {
	
	Word100::say(_sayTens[_period-10]);
	_period=0;
	}

if (_tens > 1) {
	Word100::say(_sayDecades[_tens]);
	_period = _period - _tens * TEN;
	}

if (_period == 0) { return(0); } else {
	Word100::say(_sayDigits[_period]);
		}
}

int Word100::sayNumber(long number) {

if (number == 0) {
	Word100::say(_ZERO);
	return(0);
	}
int _period;
	_period = number / MILLION;
if (_period != 0) {
	Word100::sayPeriod(_period);
	Word100::say(_MILLION);
	number=number - _period * MILLION;
	}

_period = number / THOUSAND;
if (_period != 0) {
	Word100:sayPeriod(_period);
	Word100::say(_THOUSAND);
	number = number - _period * THOUSAND;
}
Word100::sayPeriod(number);
}

void Word100::setAMPM(bool AMPM) {
_AMPM = AMPM;
}

void Word100::setDelay(int wait) {
_wait = wait;
}

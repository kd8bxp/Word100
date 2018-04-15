#include "Arduino.h"
#include "Word100Ham.h"
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

/* Portions of this code based on example by Matt Ganis (matt.ganis@gmail.com) or @mattganis on Twitter
 *  Copyright (c) 2018 Matt Ganis
 *  New functions: sayNumber(), sayHours(), sayMinutes()
 */

int Word100ham::sayMinutes(long number) {
if (number == 0) {
  
  Word100ham::say(_ZERO);   //special case for zero
   return 0;
}

  int _period = number;
  int _tens = _period / TEN;
   if (_tens == 1) {
         Word100ham::say(_sayTens[_period-10]);
		      
         _period = 0; }
                 
   if (_tens > 1) {
      
		 Word100ham::say(_sayDecades[_tens]);
	    
       _period = _period - _tens*TEN; } else {
      
	      Word100ham::say(_ZERO);
		
       }
          
   if (_period == 0)  { return 0; } else {
        
		   Word100ham::say(_sayDigits[_period]);
		 
	}
}

int Word100ham::sayHours(long number) {
if (number == 0) {
  
  	 Word100ham::say(_ZERO);   //special case for zero
	
  return 0;
}

int _period = number;
int _tens = _period / TEN;
   if (_tens == 1) {
		Word100ham::say(_sayTens[_period-10]);
         _period = 0; }
                 
   if (_tens > 1) {
       		Word100ham::say(_sayDecades[_tens]);
		    _period = _period - _tens*TEN; } 
          
   if (_period == 0)  { return 0; } else {
		
        Word100ham::say(_sayDigits[_period]);
		
	  }
}


int Word100ham::sayPeriod(int _period) {
int _hundreds = _period / HUNDRED;
if (_hundreds != 0) {

	Word100ham::say(_sayDigits[_hundreds]);
	Word100ham::say(_HUNDRED);
	
	_period = _period - (_hundreds * HUNDRED);
	}

int _tens = _period / TEN;

if (_tens == 1) {
	
	Word100ham::say(_sayTens[_period-10]);
	
	_period=0;
	}

if (_tens > 1) {
	
	Word100ham::say(_sayDecades[_tens]);
	
	_period = _period - _tens * TEN;
	}

if (_period == 0) { return(0); } else {
	
	Word100ham::say(_sayDigits[_period]);
	
	}
}

int Word100ham::sayNumber(long number) {
if (number == 0) {
	
	Word100ham::say(_ZERO);
	return(0);
	}
int _period;
	_period = number / MILLION;
if (_period != 0) {
	
	Word100ham::sayPeriod(_period);
	Word100ham::say(_MILLION);
	
	number=number - _period * MILLION;
	}

_period = number / THOUSAND;
if (_period != 0) {
	
	Word100ham:sayPeriod(_period);
	Word100ham::say(_THOUSAND);
	
	number = number - _period * THOUSAND;
}
Word100ham::sayPeriod(number);
}

void Word100ham::setAMPM(bool AMPM) {
_AMPM = AMPM;
}

void Word100ham::setDelay(int wait) {
_wait = wait;
}

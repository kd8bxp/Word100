#include "Arduino.h"
#include "Word100BBT.h"
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

May 4, 2018 Updated for the Big Buddy Talker, LeRoy Miller (2018 (c))
May 12, 2018 sayNumber functions (minutes,hours) all working again.
	Made small change to how setAMPM work, but nothing that effects the sketches
May 28, 2018 Updated timing to 850, and fixed sayMinute issues
*/


 
#define _PLAY_ 0x98
#define _RAMPUP 0xA8 //COUT ramp up - this value never changes
#define _RAMPDOWN 0xB8 //COUT ram down


Word100bbt::Word100bbt(int cs1, int cs2, int cs3,int cs4) {
_cs[0] = cs1;
_cs[1] = cs2;
_cs[2] = cs3;
_cs[3] = cs4;
Word100bbt::setAMPM(1);
Word100bbt:setDelay(850); //default delay is about 850 milliseconds
}

void Word100bbt::begin() {

  SPI.begin();             // Initialize SPI
  SPI.setClockDivider(SPI_CLOCK_DIV32); // low frequency SPI
for (int __count=0;__count<4;__count++) {  
pinMode(_cs[__count],OUTPUT);    // Chip select pins is an output
  digitalWrite(_cs[__count],HIGH); // Set chip select to be HIGH (5v) by default.  The chip on the shield is selected when this line is brought low. 
  SPI.setBitOrder(MSBFIRST);  // OTP requires MSB first
  SPI.setDataMode(SPI_MODE0);  // Use MODE0, as all other modes to not work
  //delay(500);   // One second delay
  digitalWrite(_cs[__count], LOW);
  SPI.transfer(_RAMPUP);
  SPI.transfer(0x00);
  digitalWrite(_cs[__count],HIGH);
}
}

void Word100bbt::say(int value, int pin)    // Calling this function reads words individually
{
  
  delay(7);
  // Transmit Data
  digitalWrite(_cs[pin-1],LOW);
  SPI.transfer(_PLAY_);
  SPI.transfer(value);
  digitalWrite(_cs[pin-1],HIGH);
  delay(_wait); 
  //delay(700);
}

/* Portions of this code based on example by Matt Ganis (matt.ganis@gmail.com) or @mattganis on Twitter
 *  Copyright (c) 2018 Matt Ganis
 *  New functions: sayNumber(), sayHours(), sayMinutes()
 */

int Word100bbt::sayMinutes(long number) {
if (number == 0) {
    
  //Word100bbt::say(_ZERO);   //special case for zero
   return 0;
}

  int _period = number;
  int _tens = _period / TEN;
   if (_tens == 1) {
         Word100bbt::say(_sayTens[_period-10][0],_sayTens[_period-10][1]);
		            
         _period = 0; }
                 
   if (_tens > 1) {
      	 Word100bbt::say(_sayDecades[_tens][0],_sayDecades[_tens][1]);
	     _period = _period - _tens*TEN; } else {
           //Word100bbt::say(_ZERO);
		       }
      if (number < 10) { Word100bbt::say(_ZERO); }    
   if (_period == 0)  { return 0; } else {
         Word100bbt::say(_sayDigits[_period][0],_sayDigits[_period][1]);
			}
if (_AMPM == 1) {
	if (_sayAMPM == 1) { Word100bbt::say(_AM_); } else { Word100bbt::say(_PM_); }
	//Word100bbt::say(_sayAMPM);
	 }
}


int Word100bbt::sayHours(long number) {
if (number == 0) {
   
	 Word100bbt::say(_ZERO);   //special case for zero
	 return 0;
}

int _period = number;

if (_AMPM == 1) {
 if (_period >= 13) { _period = _period -12;}
 if (number < 12) {_sayAMPM = 1 /*_AM_*/; } else {_sayAMPM = 0 /*_PM_*/; }
}

  int _tens = _period / TEN;
   if (_tens == 1) {
		    
		Word100bbt::say(_sayTens[_period-10][0],_sayTens[_period-10][1]);
		         
         _period = 0; }
                 
   if (_tens > 1) {
       	Word100bbt::say(_sayDecades[_tens][0],_sayDecades[_tens][1]);
		 
       _period = _period - _tens*TEN; } 
          
   if (_period == 0)  { return 0; } else {
		Word100bbt::say(_sayDigits[_period][0],_sayDigits[_period][1]);
		
	  }

}

int Word100bbt::sayPeriod(int _period) {

int _hundreds = _period / HUNDRED;

if (_hundreds != 0) {
		
	Word100bbt::say(_sayDigits[_hundreds][0],_sayDigits[_hundreds][1]);
	Word100bbt::say(_HUNDRED);
	_period = _period - (_hundreds * HUNDRED);
	}

int _tens = _period / TEN;

if (_tens == 1) {
	
	Word100bbt::say(_sayTens[_period-10][0],_sayTens[_period-10][1]);
	_period=0;
	}

if (_tens > 1) {
	Word100bbt::say(_sayDecades[_tens][0],_sayDecades[_tens][1]);
	_period = _period - _tens * TEN;
	}

if (_period == 0) { return(0); } else {
	Word100bbt::say(_sayDigits[_period][0],_sayDigits[_period][1]);
		}

}


int Word100bbt::sayNumber(long number) {

if (number == 0) {
	Word100bbt::say(_ZERO);
	return(0);
	}
int _period;
	_period = number / MILLION;
if (_period != 0) {
	Word100bbt::sayPeriod(_period);
	Word100bbt::say(_MILLION);
	number=number - _period * MILLION;
	}

_period = number / THOUSAND;
if (_period != 0) {
	Word100bbt:sayPeriod(_period);
	Word100bbt::say(_THOUSAND);
	number = number - _period * THOUSAND;
}

Word100bbt::sayPeriod(number);

}


void Word100bbt::setAMPM(bool AMPM) {
_AMPM = AMPM;
}

void Word100bbt::setDelay(int wait) {
_wait = wait;
}

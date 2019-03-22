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
/* Portions of this code based on example by Matt Ganis (matt.ganis@gmail.com) or @mattganis on Twitter
 *  Copyright (c) 2018 Matt Ganis
 *  New functions: sayNumber(), sayHours(), sayMinutes()
 */

/*
 * Mar 11, 2018 Updated words start with underscore.
 * A.M. is _am_ and P.M. is _pm_
 * Based on feedback from user jjdeprisco (Thank You)
 * LeRoy Miller, (C) 2018
 * Version 1.5.1 

Mar 16, 2018
version number is changed to compile with Arduino 1.5 specifications and semantic
versioning. https://semver.org/
Added _100, _1000, _thr, updated documentation. 
Library now Arduino 1.5 spec, and sumitted for library manager.

Version 2.1.0 (semver)  

Version 3.0.0 - Mar 19, 2018 Split classes into own header and cpp files, to over come problem that was found when using the original 100+ Word Shield and the HAM chip. May make it easier to include other external libraries, or build on these.
 - Found that not all the words had been underscored - corrected. - LeRoy Miller

version 3.2.2 - added sayHours, sayMinutes, sayNumber, setAMPM

V 5.1.0 - Mar 22, 2019 added support for softwareSPI, the 100+ Word Shield and E-Z will work with the Leonardo and MEGA2560 boards.
Requires: SoftwareSPI library found here: https://github.com/RevPhil/arduino_SoftwareSPI
 */

#ifndef Word100_h
#define Word100_h

//#define AMPM  //default is for AMPM hour. In otherwords when 13 is sent to sayHours(int number) and AMPM is true, the number said will be one (1)

#if ARDUINO_AVR_LEONARDO || ARDUINO_AVR_MEGA2560
#define SSPI_MODE true
#else
#define SSPI_MODE false
#endif

#include "Arduino.h"
#include "default.h"

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


class Word100 {
private:
    int _cs;
    int sayPeriod(int _period);
		int _sayDigits[10] = {_ZERO,_ONE,_TWO,_THREE,_FOUR,_FIVE,_SIX,_SEVEN,_EIGHT,_NINE};
	int _sayDecades[11] = {0x00,0x00,_TWENTY,_THIRTY,_FORTY,_FIFTY,_SIXTY,_SEVENTY,_EIGHTY,_NINETY};
	int _sayTens[11] = {_TEN,_ELEVEN,_TWELVE,_THIRTEEN,_FOURTEEN,_FIFTEEN,_SIXTEEN,_SEVENTEEN,_EIGHTEEN,_NINETEEN};
	int _hundreds;
	int _tens;
	int _number;
	bool _AMPM;
	int _sayAMPM;
	int _wait;
	uint8_t csBit, *csReg;  // Chip Select bit and register
public:
Word100(int cs);
    void begin();
    void say(int _value);
	int sayNumber(long number);
	int sayHours(long number);
	int sayMinutes(long number);
	void setAMPM(bool AMPM);
	void setDelay(int wait);
};


#endif

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
v 3.2.3 - added setDelay to LBT library
 */

#ifndef Word100LBT_h
#define Word100LBT_h

#include "Arduino.h"
#include <SPI.h>
#include "default.h"


class Word100lbt {
private:
    int _cs;
    int sayPeriod(int _period);
	int _sayDigits[10] = {_zero,_one,_two,_three,_four,_five,_six,_seven,_eight,_nine};
	int _sayDecades[11] = {0x00,0x00,_twenty,_thirty,_forty,_fifty,_sixty,_seventy,_eighty,_ninety};
	int _sayTens[11] = {_ten,_eleven,_twelve,_thirteen,_fourteen,_fifteen,_sixteen,_seventeen,_eighteen,_nineteen};
	int _hundreds;
	int _tens;
	int _number;
	bool _AMPM;
	int _sayAMPM;
	int _wait;
public:
Word100lbt(int cs);
    void begin();
    void say(int _value);
	int sayNumber(long number);
	int sayHours(long number);
	int sayMinutes(long number);
	void setAMPM(bool AMPM);
	void setDelay(int wait);
};


#endif

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

version 3.2.2 - added sayHours, sayMinutes, sayNumber, setAMPM (Does Nothing in Word100Ham library)
 */


#ifndef Word100Ham_h
#define Word100Ham_h

#include "Arduino.h"
#include <SPI.h>

#define WORD100 1
#define MILLION  1000000
#define THOUSAND 1000
#define HUNDRED  100
#define TEN     10

//Alphabet
#define _a 0x00  //US spelling
#define _b 0x01
#define _c 0x02
#define _d 0x03
#define _e 0x04
#define _f 0x05
#define _g 0x06
#define _h 0x07
#define _i 0x08
#define _j 0x09
#define _k 0x0a
#define _l 0x0b
#define _m 0x0c
#define _n 0x0d
#define _o 0x0e
#define _p 0x0f
#define _q 0x10
#define _r 0x11
#define _s 0x12
#define _t 0x13
#define _u 0x14
#define _v 0x15
#define _w 0x16
#define _x 0x17
#define _y 0x18
#define _z 0x19

//Phonetic Alphabet
#define _alpha 0x1a
#define _bravo 0x1b
#define _charlie 0x1c
#define _delta 0x1d
#define _echo 0x1e
#define _foxtrot 0x1f
#define _golf 0x20
#define _hotel 0x21
#define _india 0x22
#define _juliet 0x23
#define _kilo 0x24
#define _lima 0x25
#define _mike 0x26
#define _november 0x27
#define _oscar 0x28
#define _papa 0x29
#define _quebec 0x2a
#define _romeo 0x2b
#define _sierra 0x2c
#define _tango 0x2d
#define _uniform 0x2e
#define _victor 0x2f
#define _whiskey 0x30
#define _xray 0x31
#define _yankee 0x32
#define _zulu 0x33

//Numbers
#define _zero 0x34
#define _0 0x34
#define _one 0x35
#define _1 0x35
#define _two 0x36
#define _2 0x36
#define _three 0x37
#define _3 0x37
#define _four 0x38
#define _4 0x38
#define _five 0x39
#define _5 0x39
#define _six 0x3a
#define _6 0x3a
#define _seven 0x3b
#define _7 0x3b
#define _eight 0x3c
#define _8 0x3c
#define _nine 0x3d
#define _9 0x3d
#define _ten 0x3e
#define _10 0x3e
#define _eleven 0x3f
#define _11 0x3f
#define _twelve 0x40
#define _12 0x40
#define _thirteen 0x41
#define _13 0x41
#define _fourteen 0x42
#define _14 0x42
#define _fifteen 0x43
#define _15 0x43
#define _sixteen 0x44
#define _16 0x44
#define _seventeen 0x45
#define _17 0x45
#define _eighteen 0x46
#define _18 0x46
#define _nineteen 0x47
#define _19 0x47
#define _twenty 0x48
#define _20 0x48
#define _thirty 0x49
#define _30 0x49
#define _forty 0x4a
#define _40 0x4a
#define _fifty 0x4b
#define _50 0x4b
#define _sixty 0x4c
#define _60 0x4c
#define _seventy 0x4d
#define _70 0x4d
#define _eighty 0x4e
#define _80 0x4e
#define _ninety 0x4f
#define _90 0x4f
#define _hundred 0x50
#define _100 0x50
#define _thousand 0x51
#define _1000 0x51
#define _million 0x52

//Words General
#define _ac 0x53
#define _amps 0x54
#define _band 0x55
#define _boardcasting 0x56
#define _calling 0x57
#define _come 0x58
#define _contact 0x59
#define _db 0x5a
#define _dc 0x5b
#define _degrees 0x5c
#define _first 0x5d
#define _frequency 0x5e
#define _giga 0x5f
#define _goodbye 0x60
#define _hello 0x61
#define _here 0x62
#define _hertz 0x63
#define _hz 0x63
#define _in 0x64
#define _incoming 0x65
#define _it 0x66
#define _key 0x67
#define _kilo 0x68
#define _last 0x69
#define _level 0x6a
#define _mega 0x6b
#define _off 0x6c
#define _ohms 0x6d
#define _on 0x6e
#define _operator 0x6f
#define _out 0x70
#define _over 0x71
#define _radio 0x72
#define _ready 0x73
#define _receiving 0x74
#define _rf 0x75
#define _sent 0x76
#define _sleep 0x77
#define _the 0x78
//#define two 0x79
#define _transmitting 0x7a
#define _volts 0x7b
#define _watts 0x7c

class Word100ham {
private:
    int _cs;
    void sayPeriod(int _period);
	int _sayDigits[10] = {_zero,_one,_two,_three,_four,_five,_six,_seven,_eight,_nine};
	int _sayDecades[11] = {0x00,0x00,_twenty,_thirty,_forty,_fifty,_sixty,_seventy,_eighty,_ninety};
	int _sayTens[11] = {_ten,_eleven,_twelve,_thirteen,_fourteen,_fifteen,_sixteen,_seventeen,_eighteen,_nineteen};
	int _hundreds;
	int _tens;
	int _number;
	bool _AMPM;
	int _sayAMPM;
public:
Word100ham(int cs);
    void begin();
    void say(int _value);
	void sayNumber(long number);
	void sayHours(long number);
	void sayMinutes(long number);
	void setAMPM(bool AMPM);
};


#endif

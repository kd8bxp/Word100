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

/*
 * Mar 11, 2018 Updated words start with underscore.
 * A.M. is _am_ and P.M. is _pm_
 * Based on feedback from user jjdeprisco (Thank You)
 * LeRoy Miller, (C) 2018
 * Version 1.5.1 
 */

#ifndef Word100_h
#define Word100_h

#include "Arduino.h"
#include <SPI.h>

class Word100 {
private:
    int _cs;
public:
Word100(int cs);
    void begin();
    void say(int _value);
//Colour
#define _colour 0x00 //EU spelling
#define _color 0x00  //US spelling
#define _black 0x01
#define _white 0x02
#define _blue 0x03
#define _green 0x04
#define _orange 0x05
#define _red 0x06
#define _yellow 0x07
#define _purple 0x08

//Command
#define _abort 0x09
#define _activate 0x0a
#define _begin 0x0b
#define _deactivate 0x0c
#define _destruct 0x0d
#define _go 0x0e
#define _move 0x0f
#define _off 0x10
#define _on 0x11
#define _open 0x12
#define _pull 0x13
#define _push 0x14
#define _reset 0x15
#define _run 0x16
#define _stop 0x17
#define _turn 0x18

//Months/Days/Time
#define _january 0x19
#define _jan 0x19
#define _february 0x1a
#define _feb 0x1a
#define _march 0x1b
#define _mar 0x1b
#define _april 0x1c
#define _apr 0x1c
#define _may 0x1d
#define _june 0x1e
#define _july 0x1f
#define _august 0x20
#define _aug 0x20
#define _september 0x21
#define _sep 0x21
#define _sept 0x21
#define _october 0x22
#define _oct 0x22
#define _november 0x23
#define _nov 0x23
#define _december 0x24
#define _dec 0x24
#define _monday 0x25
#define _mon 0x25
#define _tuesday 0x26
#define _tue 0x26
#define _wednesday 0x27
#define _wed 0x27
#define _thursday 0x28
#define _thur 0x28
#define _friday 0x29
#define _fri 0x29
#define _saturday 0x2a
#define _sat 0x2a
#define _sunday 0x2b
#define _sun 0x2b
#define _am_ 0x2c
#define _pm_ 0x2d
#define _date 0x2e
#define _day 0x2f
#define _hours 0x30
#define _hrs 0x30
#define _month 0x31
#define _oclock 0x32
#define _time 0x33
#define _week 0x34
#define _year 0x35

//Numbers
#define _zero 0x36
#define _0 0x36
#define _one 0x37
#define _1 0x37
#define _two 0x38
#define _2 0x38
#define _three 0x39
#define _3 0x39
#define _four 0x3a
#define _4 0x3a
#define _five 0x3b
#define _5 0x3b
#define _six 0x3c
#define _6 0x3c
#define _seven 0x3d
#define _7 0x3b
#define _eight 0x3e
#define _8 0x3e
#define _nine 0x3f
#define _9 0x3f
#define _ten 0x40
#define _10 0x40
#define _eleven 0x41
#define _11 0x41
#define _twelve 0x42
#define _12 0x42
#define _thirteen 0x43
#define _13 0x43
#define _fourteen 0x44
#define _14 0x44
#define _fifteen 0x45
#define _15 0x45
#define _sixteen 0x46
#define _16 0x46
#define _seventeen 0x47
#define _17 0x47
#define _eighteen 0x48
#define _18 0x48
#define _nineteen 0x49
#define _19 0x49
#define _twenty 0x4a
#define _20 0x4a
#define _thirty 0x4b
#define _30 0x4b
#define _forty 0x4c
#define _40 0x4c
#define _fifty 0x4d
#define _50 0x4d
#define _sixty 0x4e
#define _60 0x4e
#define seventy 0x4f
#define _70 0x4f
#define eighty 0x50
#define _80 0x50
#define ninety 0x51
#define _90 0x51
#define _hundred 0x52
#define _thousand 0x53
#define _million 0x54

//Directions
#define _north 0x55
#define _east 0x56
#define _south 0x57
#define _west 0x58
#define _up 0x59
#define _down 0x5a
#define _left 0x5b
#define _right 0x5c
#define _backward 0x5d
#define _forward 0x5e

//feelings
#define _happy 0x5f
#define _sad 0x60
#define _angry 0x61

//Measurement
#define _ac 0x62
#define _amps 0x63
#define _celsius 0x64
#define _centi 0x65
#define _cubic 0x66
#define _dc 0x67
#define _degrees 0x68
#define _diameter 0x69
#define _fahrenheit 0x6a
#define _farads 0x6b
#define _feet 0x6c
#define _frequency 0x6d
#define _giga 0x6e
#define _gram 0x6f
#define _height 0x70
#define _hertz 0x71
#define _humidity 0x72
#define _inches 0x73
#define _kilo 0x74
#define _length 0x75
#define _light 0x76
#define _litre 0x77
#define _mega 0x78
#define _meters 0x79
#define _micro 0x7a
#define _milli 0x7b
#define _minutes 0x7c
#define _nano 0x7d
#define _newton 0x7e
#define _night 0x7f
#define _ohms 0x80
#define _per 0x81
#define _pico 0x82
#define _pitch 0x83
#define _pounds 0x84
#define _radius 0x85
#define _rate 0x86
#define _seconds 0x87
#define _sound 0x88
#define _speed 0x89
#define _temperature 0x8a
#define _volts 0x8b
#define _watts 0x8c
#define _weight 0x8d

//Security
#define _alarm 0x8e
#define _alert 0x8f
#define _detected 0x90
#define _intruder 0x91
#define _security 0x92
#define _system 0x93
#define _warning 0x94

//Math
#define _clockwise 0x95
#define _counter 0x96
#define _divide 0x97
#define _equals 0x98
#define _minus 0x99
#define _multiply 0x9a
#define _not 0x9b
#define _plus 0x9c
#define _square_root 0x9d

 //Words General
 #define _a 0x9e
 #define _ahead 0x9f
 #define _air 0xa0
 #define _altitude 0xa1
 #define _an 0xa2
 #define _am 0xa3 //am not a.m.
 #define _and 0xa4
 #define _are 0xa5
 #define _area 0xa6
 #define _at 0xa7
 #define _axis 0xa8
 #define _back 0xa9
 #define _be 0xaa
 #define _bearing 0xab
 #define _been 0xac
 #define _button 0xad
 #define _by 0xae
 #define _can 0xaf
 #define _caution 0xb0
 #define _change 0xb1
 #define _check 0xb2
 #define _closed 0xb3
 #define _condition 0xb4
 #define _contact 0xb5
 #define _critical 0xb6
 #define _door 0xb7
 #define _empty 0xb8  
 #define _end 0xb9  
 #define _environment 0xba  
 #define _falling 0xbb  
 #define  _fast 0xbc  
 #define  _fatal 0xbd  
 #define  _feel 0xbe  
 #define  _first 0xbf  
 #define  _from 0xc0  
 #define  _front 0xc1  
 #define  _going 0xc2  
 #define  _goodbye 0xc3  
 #define  _he  0xc4  
 #define  _hello 0xc5  
 #define  _high 0xc6  
 #define  _how 0xc7  
 #define  _i 0xc8  
 #define  _in  0xc9  
 #define  _incoming 0xca  
 #define  _ing 0xcb  
 #define  _inside 0xcc  
 #define  _is 0xcd  
 #define  _it 0xce  
 #define  _laser 0xcf  
 #define  _last 0xd0  
 #define  _level 0xd1  
 #define  _locked 0xd2  
 #define  _low 0xd3  
 #define  _me 0xd4  
 #define  _message 0xd5  
 #define  _mode 0xd6  
 #define  _motor 0xd7  
 #define  _new 0xd8  
 #define  _next 0xd9  
 #define  _nomincal 0xda  
 #define  _object 0xdb  
 #define  _obstacle 0xdc  
 #define  _of 0xdd  
 #define  _out 0xde  
 #define  _outside 0xdf  
 #define  _press 0xe0  
 #define  _process 0xe1  
 #define  _purge 0xe2  
 #define  _range 0xe3  
 #define  _rear 0xe4  
 #define  _received 0xe5  
 #define  _rising 0xe6  
 #define  _sent 0xe7  
 #define  _sequence 0xe8  
 #define  _she 0xe9  
 #define  _sleep 0xea  
 #define  _slow 0xeb  
 #define  _stable 0xec  
 #define  _start 0xed  
 #define  _step 0xee  
 #define  _stepper 0xef  
 #define  _switch 0xf0  
 #define  _tell 0xf1  
 #define  _the 0xf2  
 #define  _there 0xf3  
 #define  _they 0xf4  
 #define  _to  0xf5  
 #define  _total 0xf6  
 #define  _vent 0xf7  
 #define  _we  0xf9  
 #define  _will 0xfa  
 #define  _window 0xfb  
 #define  _you 0xfc  
 #define  _zone 0xfd 

};

class Word100ham {
private:
    int _cs;
public:
Word100ham(int cs);
    void begin();
    void say(int _value);
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
#define _thousand 0x51
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
};

class Word100lbt {
private:
    int _cs;
public:
Word100lbt(int cs);
    void begin();
    void say(int _value);
//Colour
#define _colour 0x00 //EU spelling
#define _color 0x00  //US spelling
#define _black 0x01
#define _white 0x02
#define _blue 0x03
#define _green 0x04
#define _orange 0x05
#define _red 0x06
#define _yellow 0x07
#define _purple 0x08

//Command
#define _abort 0x09
#define _activate 0x0a
#define _begin 0x0b
#define _deactivate 0x0c
#define _destruct 0x0d
#define _go 0x0e
#define _move 0x0f
#define _off 0x10
#define _on 0x11
#define _open 0x12
#define _pull 0x13
#define _push 0x14
#define _reset 0x15
#define _run 0x16
#define _stop 0x17
#define _turn 0x18

//Months/Days/Time
#define _january 0x19
#define _jan 0x19
#define _february 0x1a
#define _feb 0x1a
#define _march 0x1b
#define _mar 0x1b
#define _april 0x1c
#define _apr 0x1c
#define _may 0x1d
#define _june 0x1e
#define _july 0x1f
#define _august 0x20
#define _aug 0x20
#define _september 0x21
#define _sep 0x21
#define _sept 0x21
#define _october 0x22
#define _oct 0x22
#define _november 0x23
#define _nov 0x23
#define _december 0x24
#define _dec 0x24
#define _monday 0x25
#define _mon 0x25
#define _tuesday 0x26
#define _tue 0x26
#define _wednesday 0x27
#define _wed 0x27
#define _thursday 0x28
#define _thur 0x28
#define _friday 0x29
#define _fri 0x29
#define _saturday 0x2a
#define _sat 0x2a
#define _sunday 0x2b
#define _sun 0x2b
#define _am_ 0x2c
#define _pm_ 0x2d
#define _date 0x2e
#define _day 0x2f
#define _hours 0x30
#define _hrs 0x30
#define _month 0x31
#define _oclock 0x32
#define _time 0x33
#define _week 0x34
#define _year 0x35

//Numbers
#define _zero 0x36
#define _0 0x36
#define _one 0x37
#define _1 0x37
#define _two 0x38
#define _2 0x38
#define _three 0x39
#define _3 0x39
#define _four 0x3a
#define _4 0x3a
#define _five 0x3b
#define _5 0x3b
#define _six 0x3c
#define _6 0x3c
#define _seven 0x3d
#define _7 0x3b
#define _eight 0x3e
#define _8 0x3e
#define _nine 0x3f
#define _9 0x3f
#define _ten 0x40
#define _10 0x40
#define _eleven 0x41
#define _11 0x41
#define _twelve 0x42
#define _12 0x42
#define _thirteen 0x43
#define _13 0x43
#define _fourteen 0x44
#define _14 0x44
#define _fifteen 0x45
#define _15 0x45
#define _sixteen 0x46
#define _16 0x46
#define _seventeen 0x47
#define _17 0x47
#define _eighteen 0x48
#define _18 0x48
#define _nineteen 0x49
#define _19 0x49
#define _twenty 0x4a
#define _20 0x4a
#define _thirty 0x4b
#define _30 0x4b
#define _forty 0x4c
#define _40 0x4c
#define _fifty 0x4d
#define _50 0x4d
#define _sixty 0x4e
#define _60 0x4e
#define seventy 0x4f
#define _70 0x4f
#define eighty 0x50
#define _80 0x50
#define ninety 0x51
#define _90 0x51
#define _hundred 0x52
#define _thousand 0x53
#define _million 0x54

//Directions
#define _north 0x55
#define _east 0x56
#define _south 0x57
#define _west 0x58
#define _up 0x59
#define _down 0x5a
#define _left 0x5b
#define _right 0x5c
#define _backward 0x5d
#define _forward 0x5e

//feelings
#define _happy 0x5f
#define _sad 0x60
#define _angry 0x61

//Measurement
#define _ac 0x62
#define _amps 0x63
#define _celsius 0x64
#define _centi 0x65
#define _cubic 0x66
#define _dc 0x67
#define _degrees 0x68
#define _diameter 0x69
#define _fahrenheit 0x6a
#define _farads 0x6b
#define _feet 0x6c
#define _frequency 0x6d
#define _giga 0x6e
#define _gram 0x6f
#define _height 0x70
#define _hertz 0x71
#define _humidity 0x72
#define _inches 0x73
#define _kilo 0x74
#define _length 0x75
#define _light 0x76
#define _litre 0x77
#define _mega 0x78
#define _meters 0x79
#define _micro 0x7a
#define _milli 0x7b
#define _minutes 0x7c
#define _nano 0x7d
#define _newton 0x7e
#define _night 0x7f
#define _ohms 0x80
#define _per 0x81
#define _pico 0x82
#define _pitch 0x83
#define _pounds 0x84
#define _radius 0x85
#define _rate 0x86
#define _seconds 0x87
#define _sound 0x88
#define _speed 0x89
#define _temperature 0x8a
#define _volts 0x8b
#define _watts 0x8c
#define _weight 0x8d

//Security
#define _alarm 0x8e
#define _alert 0x8f
#define _detected 0x90
#define _intruder 0x91
#define _security 0x92
#define _system 0x93
#define _warning 0x94

//Math
#define _clockwise 0x95
#define _counter 0x96
#define _divide 0x97
#define _equals 0x98
#define _minus 0x99
#define _multiply 0x9a
#define _not 0x9b
#define _plus 0x9c
#define _square_root 0x9d

 //Words General
 #define _a 0x9e
 #define _ahead 0x9f
 #define _air 0xa0
 #define _altitude 0xa1
 #define _an 0xa2
 #define _am 0xa3 //am not a.m.
 #define _and 0xa4
 #define _are 0xa5
 #define _area 0xa6
 #define _at 0xa7
 #define _axis 0xa8
 #define _back 0xa9
 #define _be 0xaa
 #define _bearing 0xab
 #define _been 0xac
 #define _button 0xad
 #define _by 0xae
 #define _can 0xaf
 #define _caution 0xb0
 #define _change 0xb1
 #define _check 0xb2
 #define _closed 0xb3
 #define _condition 0xb4
 #define _contact 0xb5
 #define _critical 0xb6
 #define _door 0xb7
 #define _empty 0xb8  
 #define _end 0xb9  
 #define _environment 0xba  
 #define _falling 0xbb  
 #define  _fast 0xbc  
 #define  _fatal 0xbd  
 #define  _feel 0xbe  
 #define  _first 0xbf  
 #define  _from 0xc0  
 #define  _front 0xc1  
 #define  _going 0xc2  
 #define  _goodbye 0xc3  
 #define  _he  0xc4  
 #define  _hello 0xc5  
 #define  _high 0xc6  
 #define  _how 0xc7  
 #define  _i 0xc8  
 #define  _in  0xc9  
 #define  _incoming 0xca  
 #define  _ing 0xcb  
 #define  _inside 0xcc  
 #define  _is 0xcd  
 #define  _it 0xce  
 #define  _laser 0xcf  
 #define  _last 0xd0  
 #define  _level 0xd1  
 #define  _locked 0xd2  
 #define  _low 0xd3  
 #define  _me 0xd4  
 #define  _message 0xd5  
 #define  _mode 0xd6  
 #define  _motor 0xd7  
 #define  _new 0xd8  
 #define  _next 0xd9  
 #define  _nomincal 0xda  
 #define  _object 0xdb  
 #define  _obstacle 0xdc  
 #define  _of 0xdd  
 #define  _out 0xde  
 #define  _outside 0xdf  
 #define  _press 0xe0  
 #define  _process 0xe1  
 #define  _purge 0xe2  
 #define  _range 0xe3  
 #define  _rear 0xe4  
 #define  _received 0xe5  
 #define  _rising 0xe6  
 #define  _sent 0xe7  
 #define  _sequence 0xe8  
 #define  _she 0xe9  
 #define  _sleep 0xea  
 #define  _slow 0xeb  
 #define  _stable 0xec  
 #define  _start 0xed  
 #define  _step 0xee  
 #define  _stepper 0xef  
 #define  _switch 0xf0  
 #define  _tell 0xf1  
 #define  _the 0xf2  
 #define  _there 0xf3  
 #define  _they 0xf4  
 #define  _to  0xf5  
 #define  _total 0xf6  
 #define  _vent 0xf7  
 #define  _we  0xf9  
 #define  _will 0xfa  
 #define  _window 0xfb  
 #define  _you 0xfc  
 #define  _zone 0xf

};


#endif

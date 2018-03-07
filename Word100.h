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
#define colour 0x00 //EU spelling
#define color 0x00  //US spelling
#define black 0x01
#define white 0x02
#define blue 0x03
#define green 0x04
#define orange 0x05
#define red 0x06
#define yellow 0x07
#define purple 0x08

//Command
#define abort 0x09
#define activate 0x0a
#define _begin 0x0b
#define deactivate 0x0c
#define destruct 0x0d
#define go 0x0e
#define move 0x0f
#define off 0x10
#define on 0x11
#define open 0x12
#define pull 0x13
#define push 0x14
#define reset 0x15
#define run 0x16
#define stop 0x17
#define turn 0x18

//Months/Days/Time
#define january 0x19
#define jan 0x19
#define february 0x1a
#define feb 0x1a
#define march 0x1b
#define mar 0x1b
#define april 0x1c
#define apr 0x1c
#define may 0x1d
#define june 0x1e
#define july 0x1f
#define august 0x20
#define aug 0x20
#define september 0x21
#define sep 0x21
#define sept 0x21
#define october 0x22
#define oct 0x22
#define november 0x23
#define nov 0x23
#define december 0x24
#define dec 0x24
#define monday 0x25
#define mon 0x25
#define tuesday 0x26
#define tue 0x26
#define wednesday 0x27
#define wed 0x27
#define thursday 0x28
#define thur 0x28
#define friday 0x29
#define fri 0x29
#define saturday 0x2a
#define sat 0x2a
#define sunday 0x2b
#define sun 0x2b
#define am 0x2c
#define pm 0x2d
#define date 0x2e
#define day 0x2f
#define hours 0x30
#define hrs 0x30
#define month 0x31
#define oclock 0x32
#define time 0x33
#define week 0x34
#define year 0x35

//Numbers
#define zero 0x36
#define _0 0x36
#define one 0x37
#define _1 0x37
#define two 0x38
#define _2 0x38
#define three 0x39
#define _3 0x39
#define four 0x3a
#define _4 0x3a
#define five 0x3b
#define _5 0x3b
#define six 0x3c
#define _6 0x3c
#define seven 0x3d
#define _7 0x3b
#define eight 0x3e
#define _8 0x3e
#define nine 0x3f
#define _9 0x3f
#define ten 0x40
#define _10 0x40
#define eleven 0x41
#define _11 0x41
#define twelve 0x42
#define _12 0x42
#define thirteen 0x43
#define _13 0x43
#define fourteen 0x44
#define _14 0x44
#define fifteen 0x45
#define _15 0x45
#define sixteen 0x46
#define _16 0x46
#define seventeen 0x47
#define _17 0x47
#define eighteen 0x48
#define _18 0x48
#define nineteen 0x49
#define _19 0x49
#define twenty 0x4a
#define _20 0x4a
#define thirty 0x4b
#define _30 0x4b
#define forty 0x4c
#define _40 0x4c
#define fifty 0x4d
#define _50 0x4d
#define sixty 0x4e
#define _60 0x4e
#define seventy 0x4f
#define _70 0x4f
#define eighty 0x50
#define _80 0x50
#define ninety 0x51
#define _90 0x51
#define hundred 0x52
#define thousand 0x53
#define million 0x54

//Directions
#define north 0x55
#define east 0x56
#define south 0x57
#define west 0x58
#define up 0x59
#define down 0x5a
#define left 0x5b
#define right 0x5c
#define backward 0x5d
#define forward 0x5e

//feelings
#define happy 0x5f
#define sad 0x60
#define angry 0x61

//Measurement
#define ac 0x62
#define amps 0x63
#define celsius 0x64
#define centi 0x65
#define cubic 0x66
#define dc 0x67
#define degrees 0x68
#define diameter 0x69
#define fahrenheit 0x6a
#define farads 0x6b
#define feet 0x6c
#define frequency 0x6d
#define giga 0x6e
#define gram 0x6f
#define height 0x70
#define hertz 0x71
#define humidity 0x72
#define inches 0x73
#define kilo 0x74
#define length 0x75
#define light 0x76
#define litre 0x77
#define mega 0x78
#define meters 0x79
#define micro 0x7a
#define milli 0x7b
#define minutes 0x7c
#define nano 0x7d
#define newton 0x7e
#define night 0x7f
#define ohms 0x80
#define per 0x81
#define pico 0x82
#define pitch 0x83
#define pounds 0x84
#define radius 0x85
#define rate 0x86
#define seconds 0x87
#define sound 0x88
#define speed 0x89
#define temperature 0x8a
#define volts 0x8b
#define watts 0x8c
#define weight 0x8d

//Security
#define alarm 0x8e
#define alert 0x8f
#define detected 0x90
#define intruder 0x91
#define security 0x92
#define system 0x93
#define warning 0x94

//Math
#define clockwise 0x95
#define counter 0x96
#define divide 0x97
#define equals 0x98
#define minus 0x99
#define multiply 0x9a
#define _not 0x9b
#define plus 0x9c
#define square_root 0x9d

 //Words General
 #define a 0x9e
 #define ahead 0x9f
 #define air 0xa0
 #define altitude 0xa1
 #define an 0xa2
 #define _am 0xa3 //am not a.m.
 #define _and 0xa4
 #define are 0xa5
 #define area 0xa6
 #define at 0xa7
 #define axis 0xa8
 #define back 0xa9
 #define be 0xaa
 #define bearing 0xab
 #define been 0xac
 #define button 0xad
 #define by 0xae
 #define can 0xaf
 #define caution 0xb0
 #define change 0xb1
 #define check 0xb2
 #define closed 0xb3
 #define condition 0xb4
 #define contact 0xb5
 #define critical 0xb6
 #define door 0xb7
 #define  empty 0xb8  
 #define  _end 0xb9  
 #define  environment 0xba  
 #define  falling 0xbb  
 #define  fast 0xbc  
 #define  fatal 0xbd  
 #define  feel 0xbe  
 #define  first 0xbf  
 #define  from 0xc0  
 #define  front 0xc1  
 #define  going 0xc2  
 #define  goodbye 0xc3  
 #define  he  0xc4  
 #define  hello 0xc5  
 #define  high 0xc6  
 #define  how 0xc7  
 #define  _i 0xc8  
 #define  _in  0xc9  
 #define  incoming 0xca  
 #define  ing 0xcb  
 #define  inside 0xcc  
 #define  is 0xcd  
 #define  it 0xce  
 #define  laser 0xcf  
 #define  last 0xd0  
 #define  level 0xd1  
 #define  locked 0xd2  
 #define  low 0xd3  
 #define  me 0xd4  
 #define  message 0xd5  
 #define  mode 0xd6  
 #define  motor 0xd7  
 #define  new 0xd8  
 #define  next 0xd9  
 #define  nomincal 0xda  
 #define  object 0xdb  
 #define  obstacle 0xdc  
 #define  of 0xdd  
 #define  _out 0xde  
 #define  outside 0xdf  
 #define  press 0xe0  
 #define  process 0xe1  
 #define  purge 0xe2  
 #define  range 0xe3  
 #define  rear 0xe4  
 #define  received 0xe5  
 #define  rising 0xe6  
 #define  sent 0xe7  
 #define  sequence 0xe8  
 #define  she 0xe9  
 #define  sleep 0xea  
 #define  slow 0xeb  
 #define  stable 0xec  
 #define  start 0xed  
 #define  step 0xee  
 #define  stepper 0xef  
 #define  switch 0xf0  
 #define  tell 0xf1  
 #define  the 0xf2  
 #define  there 0xf3  
 #define  they 0xf4  
 #define  to  0xf5  
 #define  total 0xf6  
 #define  vent 0xf7  
 #define  we  0xf9  
 #define  will 0xfa  
 #define  window 0xfb  
 #define  you 0xfc  
 #define  zone 0xfd 

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
#define alpha 0x1a
#define bravo 0x1b
#define charlie 0x1c
#define delta 0x1d
#define echo 0x1e
#define foxtrot 0x1f
#define golf 0x20
#define hotel 0x21
#define india 0x22
#define juliet 0x23
#define kilo 0x24
#define lima 0x25
#define mike 0x26
#define november 0x27
#define oscar 0x28
#define papa 0x29
#define quebec 0x2a
#define romeo 0x2b
#define sierra 0x2c
#define tango 0x2d
#define uniform 0x2e
#define victor 0x2f
#define whiskey 0x30
#define xray 0x31
#define yankee 0x32
#define zulu 0x33

//Numbers
#define zero 0x34
#define _0 0x34
#define one 0x35
#define _1 0x35
#define two 0x36
#define _2 0x36
#define three 0x37
#define _3 0x37
#define four 0x38
#define _4 0x38
#define five 0x39
#define _5 0x39
#define six 0x3a
#define _6 0x3a
#define seven 0x3b
#define _7 0x3b
#define eight 0x3c
#define _8 0x3c
#define nine 0x3d
#define _9 0x3d
#define ten 0x3e
#define _10 0x3e
#define eleven 0x3f
#define _11 0x3f
#define twelve 0x40
#define _12 0x40
#define thirteen 0x41
#define _13 0x41
#define fourteen 0x42
#define _14 0x42
#define fifteen 0x43
#define _15 0x43
#define sixteen 0x44
#define _16 0x44
#define seventeen 0x45
#define _17 0x45
#define eighteen 0x46
#define _18 0x46
#define nineteen 0x47
#define _19 0x47
#define twenty 0x48
#define _20 0x48
#define thirty 0x49
#define _30 0x49
#define forty 0x4a
#define _40 0x4a
#define fifty 0x4b
#define _50 0x4b
#define sixty 0x4c
#define _60 0x4c
#define seventy 0x4d
#define _70 0x4d
#define eighty 0x4e
#define _80 0x4e
#define ninety 0x4f
#define _90 0x4f
#define hundred 0x50
#define thousand 0x51
#define million 0x52

//Words General
#define ac 0x53
#define amps 0x54
#define band 0x55
#define boardcasting 0x56
#define calling 0x57
#define come 0x58
#define contact 0x59
#define db 0x5a
#define dc 0x5b
#define degrees 0x5c
#define first 0x5d
#define frequency 0x5e
#define giga 0x5f
#define goodbye 0x60
#define hello 0x61
#define here 0x62
#define hertz 0x63
#define hz 0x63
#define _in 0x64
#define incoming 0x65
#define it 0x66
#define key 0x67
#define kilo 0x68
#define last 0x69
#define level 0x6a
#define mega 0x6b
#define off 0x6c
#define ohms 0x6d
#define on 0x6e
#define operator 0x6f
#define _out 0x70
#define over 0x71
#define radio 0x72
#define ready 0x73
#define receiving 0x74
#define rf 0x75
#define sent 0x76
#define sleep 0x77
#define the 0x78
//#define two 0x79
#define transmitting 0x7a
#define volts 0x7b
#define watts 0x7c
};

class Word100lbt {
private:
    int _cs;
public:
Word100lbt(int cs);
    void begin();
    void say(int _value);
//Colour
#define colour 0x00 //EU spelling
#define color 0x00  //US spelling
#define black 0x01
#define white 0x02
#define blue 0x03
#define green 0x04
#define orange 0x05
#define red 0x06
#define yellow 0x07
#define purple 0x08

//Command
#define abort 0x09
#define activate 0x0a
#define _begin 0x0b
#define deactivate 0x0c
#define destruct 0x0d
#define go 0x0e
#define move 0x0f
#define off 0x10
#define on 0x11
#define open 0x12
#define pull 0x13
#define push 0x14
#define reset 0x15
#define run 0x16
#define stop 0x17
#define turn 0x18

//Months/Days/Time
#define january 0x19
#define jan 0x19
#define february 0x1a
#define feb 0x1a
#define march 0x1b
#define mar 0x1b
#define april 0x1c
#define apr 0x1c
#define may 0x1d
#define june 0x1e
#define july 0x1f
#define august 0x20
#define aug 0x20
#define september 0x21
#define sep 0x21
#define sept 0x21
#define october 0x22
#define oct 0x22
#define november 0x23
#define nov 0x23
#define december 0x24
#define dec 0x24
#define monday 0x25
#define mon 0x25
#define tuesday 0x26
#define tue 0x26
#define wednesday 0x27
#define wed 0x27
#define thursday 0x28
#define thur 0x28
#define friday 0x29
#define fri 0x29
#define saturday 0x2a
#define sat 0x2a
#define sunday 0x2b
#define sun 0x2b
#define am 0x2c
#define pm 0x2d
#define date 0x2e
#define day 0x2f
#define hours 0x30
#define hrs 0x30
#define month 0x31
#define oclock 0x32
#define time 0x33
#define week 0x34
#define year 0x35

//Numbers
#define zero 0x36
#define _0 0x36
#define one 0x37
#define _1 0x37
#define two 0x38
#define _2 0x38
#define three 0x39
#define _3 0x39
#define four 0x3a
#define _4 0x3a
#define five 0x3b
#define _5 0x3b
#define six 0x3c
#define _6 0x3c
#define seven 0x3d
#define _7 0x3b
#define eight 0x3e
#define _8 0x3e
#define nine 0x3f
#define _9 0x3f
#define ten 0x40
#define _10 0x40
#define eleven 0x41
#define _11 0x41
#define twelve 0x42
#define _12 0x42
#define thirteen 0x43
#define _13 0x43
#define fourteen 0x44
#define _14 0x44
#define fifteen 0x45
#define _15 0x45
#define sixteen 0x46
#define _16 0x46
#define seventeen 0x47
#define _17 0x47
#define eighteen 0x48
#define _18 0x48
#define nineteen 0x49
#define _19 0x49
#define twenty 0x4a
#define _20 0x4a
#define thirty 0x4b
#define _30 0x4b
#define forty 0x4c
#define _40 0x4c
#define fifty 0x4d
#define _50 0x4d
#define sixty 0x4e
#define _60 0x4e
#define seventy 0x4f
#define _70 0x4f
#define eighty 0x50
#define _80 0x50
#define ninety 0x51
#define _90 0x51
#define hundred 0x52
#define thousand 0x53
#define million 0x54

//Directions
#define north 0x55
#define east 0x56
#define south 0x57
#define west 0x58
#define up 0x59
#define down 0x5a
#define left 0x5b
#define right 0x5c
#define backward 0x5d
#define forward 0x5e

//feelings
#define happy 0x5f
#define sad 0x60
#define angry 0x61

//Measurement
#define ac 0x62
#define amps 0x63
#define celsius 0x64
#define centi 0x65
#define cubic 0x66
#define dc 0x67
#define degrees 0x68
#define diameter 0x69
#define fahrenheit 0x6a
#define farads 0x6b
#define feet 0x6c
#define frequency 0x6d
#define giga 0x6e
#define gram 0x6f
#define height 0x70
#define hertz 0x71
#define humidity 0x72
#define inches 0x73
#define kilo 0x74
#define length 0x75
#define light 0x76
#define litre 0x77
#define mega 0x78
#define meters 0x79
#define micro 0x7a
#define milli 0x7b
#define minutes 0x7c
#define nano 0x7d
#define newton 0x7e
#define night 0x7f
#define ohms 0x80
#define per 0x81
#define pico 0x82
#define pitch 0x83
#define pounds 0x84
#define radius 0x85
#define rate 0x86
#define seconds 0x87
#define sound 0x88
#define speed 0x89
#define temperature 0x8a
#define volts 0x8b
#define watts 0x8c
#define weight 0x8d

//Security
#define alarm 0x8e
#define alert 0x8f
#define detected 0x90
#define intruder 0x91
#define security 0x92
#define system 0x93
#define warning 0x94

//Math
#define clockwise 0x95
#define counter 0x96
#define divide 0x97
#define equals 0x98
#define minus 0x99
#define multiply 0x9a
#define _not 0x9b
#define plus 0x9c
#define square_root 0x9d

 //Words General
 #define a 0x9e
 #define ahead 0x9f
 #define air 0xa0
 #define altitude 0xa1
 #define an 0xa2
 #define _am 0xa3 //am not a.m.
 #define _and 0xa4
 #define are 0xa5
 #define area 0xa6
 #define at 0xa7
 #define axis 0xa8
 #define back 0xa9
 #define be 0xaa
 #define bearing 0xab
 #define been 0xac
 #define button 0xad
 #define by 0xae
 #define can 0xaf
 #define caution 0xb0
 #define change 0xb1
 #define check 0xb2
 #define closed 0xb3
 #define condition 0xb4
 #define contact 0xb5
 #define critical 0xb6
 #define door 0xb7
 #define  empty 0xb8  
 #define  _end 0xb9  
 #define  environment 0xba  
 #define  falling 0xbb  
 #define  fast 0xbc  
 #define  fatal 0xbd  
 #define  feel 0xbe  
 #define  first 0xbf  
 #define  from 0xc0  
 #define  front 0xc1  
 #define  going 0xc2  
 #define  goodbye 0xc3  
 #define  he  0xc4  
 #define  hello 0xc5  
 #define  high 0xc6  
 #define  how 0xc7  
 #define  _i 0xc8  
 #define  _in  0xc9  
 #define  incoming 0xca  
 #define  ing 0xcb  
 #define  inside 0xcc  
 #define  is 0xcd  
 #define  it 0xce  
 #define  laser 0xcf  
 #define  last 0xd0  
 #define  level 0xd1  
 #define  locked 0xd2  
 #define  low 0xd3  
 #define  me 0xd4  
 #define  message 0xd5  
 #define  mode 0xd6  
 #define  motor 0xd7  
 #define  new 0xd8  
 #define  next 0xd9  
 #define  nomincal 0xda  
 #define  object 0xdb  
 #define  obstacle 0xdc  
 #define  of 0xdd  
 #define  _out 0xde  
 #define  outside 0xdf  
 #define  press 0xe0  
 #define  process 0xe1  
 #define  purge 0xe2  
 #define  range 0xe3  
 #define  rear 0xe4  
 #define  received 0xe5  
 #define  rising 0xe6  
 #define  sent 0xe7  
 #define  sequence 0xe8  
 #define  she 0xe9  
 #define  sleep 0xea  
 #define  slow 0xeb  
 #define  stable 0xec  
 #define  start 0xed  
 #define  step 0xee  
 #define  stepper 0xef  
 #define  switch 0xf0  
 #define  tell 0xf1  
 #define  the 0xf2  
 #define  there 0xf3  
 #define  they 0xf4  
 #define  to  0xf5  
 #define  total 0xf6  
 #define  vent 0xf7  
 #define  we  0xf9  
 #define  will 0xfa  
 #define  window 0xfb  
 #define  you 0xfc  
 #define  zone 0xfd 

};


#endif

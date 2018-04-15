#ifndef Default_h
#define Default_h

#include "Arduino.h"

#define MILLION  1000000
#define THOUSAND 1000
#define HUNDRED  100
#define TEN     10

//COLOUR
#define _COLOUR 0X00 //EU SPELLING
#define _COLOR 0X00  //US SPELLING
#define _BLACK 0X01
#define _WHITE 0X02
#define _BLUE 0X03
#define _GREEN 0X04
#define _ORANGE 0X05
#define _RED 0X06
#define _YELLOW 0X07
#define _PURPLE 0X08

//COMMAND
#define _ABORT 0X09
#define _ACTIVATE 0X0A
#define _BEGIN 0X0B
#define _DEACTIVATE 0X0C
#define _DESTRUCT 0X0D
#define _GO 0X0E
#define _MOVE 0X0F
#define _OFF 0X10
#define _ON 0X11
#define _OPEN 0X12
#define _PULL 0X13
#define _PUSH 0X14
#define _RESET 0X15
#define _RUN 0X16
#define _STOP 0X17
#define _TURN 0X18

//MONTHS/DAYS/TIME
#define _JANUARY 0X19
#define _JAN 0X19
#define _FEBRUARY 0X1A
#define _FEB 0X1A
#define _MARCH 0X1B
#define _MAR 0X1B
#define _APRIL 0X1C
#define _APR 0X1C
#define _MAY 0X1D
#define _JUNE 0X1E
#define _JULY 0X1F
#define _AUGUST 0X20
#define _AUG 0X20
#define _SEPTEMBER 0X21
#define _SEP 0X21
#define _SEPT 0X21
#define _OCTOBER 0X22
#define _OCT 0X22
#define _NOVEMBER 0X23
#define _NOV 0X23
#define _DECEMBER 0X24
#define _DEC 0X24
#define _MONDAY 0X25
#define _MON 0X25
#define _TUESDAY 0X26
#define _TUE 0X26
#define _WEDNESDAY 0X27
#define _WED 0X27
#define _THURSDAY 0X28
#define _THUR 0X28
#define _THR 0X28
#define _FRIDAY 0X29
#define _FRI 0X29
#define _SATURDAY 0X2A
#define _SAT 0X2A
#define _SUNDAY 0X2B
#define _SUN 0X2B
#define _AM_ 0X2C
#define _PM_ 0X2D
#define _DATE 0X2E
#define _DAY 0X2F
#define _HOURS 0X30
#define _HRS 0X30
#define _MONTH 0X31
#define _OCLOCK 0X32
#define _TIME 0X33
#define _WEEK 0X34
#define _YEAR 0X35

//NUMBERS
#define _ZERO 0X36
#define _0 0X36
#define _ONE 0X37
#define _1 0X37
#define _TWO 0X38
#define _2 0X38
#define _THREE 0X39
#define _3 0X39
#define _FOUR 0X3A
#define _4 0X3A
#define _FIVE 0X3B
#define _5 0X3B
#define _SIX 0X3C
#define _6 0X3C
#define _SEVEN 0X3D
#define _7 0X3B
#define _EIGHT 0X3E
#define _8 0X3E
#define _NINE 0X3F
#define _9 0X3F
#define _TEN 0X40
#define _10 0X40
#define _ELEVEN 0X41
#define _11 0X41
#define _TWELVE 0X42
#define _12 0X42
#define _THIRTEEN 0X43
#define _13 0X43
#define _FOURTEEN 0X44
#define _14 0X44
#define _FIFTEEN 0X45
#define _15 0X45
#define _SIXTEEN 0X46
#define _16 0X46
#define _SEVENTEEN 0X47
#define _17 0X47
#define _EIGHTEEN 0X48
#define _18 0X48
#define _NINETEEN 0X49
#define _19 0X49
#define _TWENTY 0X4A
#define _20 0X4A
#define _THIRTY 0X4B
#define _30 0X4B
#define _FORTY 0X4C
#define _40 0X4C
#define _FIFTY 0X4D
#define _50 0X4D
#define _SIXTY 0X4E
#define _60 0X4E
#define _SEVENTY 0X4F
#define _70 0X4F
#define _EIGHTY 0X50
#define _80 0X50
#define _NINETY 0X51
#define _90 0X51
#define _HUNDRED 0X52
#define _100 0X52
#define _THOUSAND 0X53
#define _1000 0X53
#define _MILLION 0X54

//DIRECTIONS
#define _NORTH 0X55
#define _EAST 0X56
#define _SOUTH 0X57
#define _WEST 0X58
#define _UP 0X59
#define _DOWN 0X5A
#define _LEFT 0X5B
#define _RIGHT 0X5C
#define _BACKWARD 0X5D
#define _FORWARD 0X5E

//FEELINGS
#define _HAPPY 0X5F
#define _SAD 0X60
#define _ANGRY 0X61

//MEASUREMENT
#define _AC 0X62
#define _AMPS 0X63
#define _CELSIUS 0X64
#define _CENTI 0X65
#define _CUBIC 0X66
#define _DC 0X67
#define _DEGREES 0X68
#define _DIAMETER 0X69
#define _FAHRENHEIT 0X6A
#define _FARADS 0X6B
#define _FEET 0X6C
#define _FREQUENCY 0X6D
#define _GIGA 0X6E
#define _GRAM 0X6F
#define _HEIGHT 0X70
#define _HERTZ 0X71
#define _HZ 0X71
#define _HUMIDITY 0X72
#define _INCHES 0X73
#define _KILO 0X74
#define _LENGTH 0X75
#define _LIGHT 0X76
#define _LITRE 0X77
#define _MEGA 0X78
#define _METERS 0X79
#define _MICRO 0X7A
#define _MILLI 0X7B
#define _MINUTES 0X7C
#define _NANO 0X7D
#define _NEWTON 0X7E
#define _NIGHT 0X7F
#define _OHMS 0X80
#define _PER 0X81
#define _PICO 0X82
#define _PITCH 0X83
#define _POUNDS 0X84
#define _RADIUS 0X85
#define _RATE 0X86
#define _SECONDS 0X87
#define _SOUND 0X88
#define _SPEED 0X89
#define _TEMPERATURE 0X8A
#define _VOLTS 0X8B
#define _WATTS 0X8C
#define _WEIGHT 0X8D

//SECURITY
#define _ALARM 0X8E
#define _ALERT 0X8F
#define _DETECTED 0X90
#define _INTRUDER 0X91
#define _SECURITY 0X92
#define _SYSTEM 0X93
#define _WARNING 0X94

//MATH
#define _CLOCKWISE 0X95
#define _COUNTER 0X96
#define _DIVIDE 0X97
#define _EQUALS 0X98
#define _MINUS 0X99
#define _MULTIPLY 0X9A
#define _NOT 0X9B
#define _PLUS 0X9C
#define _SQUARE_ROOT 0X9D

 //WORDS GENERAL
 #define _A 0X9E
 #define _AHEAD 0X9F
 #define _AIR 0XA0
 #define _ALTITUDE 0XA1
 #define _AN 0XA2
 #define _AM 0XA3 //AM NOT A.M.
 #define _AND 0XA4
 #define _ARE 0XA5
 #define _AREA 0XA6
 #define _AT 0XA7
 #define _AXIS 0XA8
 #define _BACK 0XA9
 #define _BE 0XAA
 #define _BEARING 0XAB
 #define _BEEN 0XAC
 #define _BUTTON 0XAD
 #define _BY 0XAE
 #define _CAN 0XAF
 #define _CAUTION 0XB0
 #define _CHANGE 0XB1
 #define _CHECK 0XB2
 #define _CLOSED 0XB3
 #define _CONDITION 0XB4
 #define _CONTACT 0XB5
 #define _CRITIAL 0XB6
 #define _DOOR 0XB7
 #define _EMPTY 0XB8  
 #define _END 0XB9  
 #define _ENVIROMENT 0XBA  
 #define _FALLING 0XBB  
 #define  _FAST 0XBC  
 #define  _FATAL 0XBD  
 #define  _FEEL 0XBE  
 #define  _FIRST 0XBF  
 #define  _FROM 0XC0  
 #define  _FRONT 0XC1  
 #define  _GOING 0XC2  
 #define  _GOODBYE 0XC3  
 #define  _HE  0XC4  
 #define  _HELLO 0XC5  
 #define  _HIGH 0XC6  
 #define  _HOW 0XC7  
 #define  _I 0XC8  
 #define  _IN  0XC9  
 #define  _INCOMING 0XCA  
 #define  _ING 0XCB  
 #define  _INSIDE 0XCC  
 #define  _IS 0XCD  
 #define  _IT 0XCE  
 #define  _LASER 0XCF  
 #define  _LAST 0XD0  
 #define  _LEVEL 0XD1  
 #define  _LOCKED 0XD2  
 #define  _LOW 0XD3  
 #define  _ME 0XD4  
 #define  _MESSAGE 0XD5  
 #define  _MODE 0XD6  
 #define  _MOTOR 0XD7  
 #define  _NEW 0XD8  
 #define  _NEXT 0XD9  
 #define  _NOMINCAL 0XDA  
 #define  _OBJECT 0XDB  
 #define  _OBSTACLE 0XDC  
 #define  _OF 0XDD  
 #define  _OUT 0XDE  
 #define  _OUTSIDE 0XDF  
 #define  _PRESS 0XE0  
 #define  _PROCESS 0XE1  
 #define  _PURGE 0XE2  
 #define  _RANGE 0XE3  
 #define  _REAR 0XE4  
 #define  _RECEIVED 0XE5  
 #define  _RISING 0XE6  
 #define  _SENT 0XE7  
 #define  _SEQUENCE 0XE8  
 #define  _SHE 0XE9  
 #define  _SLEEP 0XEA  
 #define  _SLOW 0XEB  
 #define  _STABLE 0XEC  
 #define  _START 0XED  
 #define  _STEP 0XEE  
 #define  _STEPPER 0XEF  
 #define  _SWITCH 0XF0  
 #define  _TELL 0XF1  
 #define  _THE 0XF2  
 #define  _THERE 0XF3  
 #define  _THEY 0XF4  
 #define  _TO  0XF5  
 #define  _TOTAL 0XF6  
 #define  _VENT 0XF7  
 #define  _WE  0XF9  
 #define  _WILL 0XFA  
 #define  _WINDOW 0XFB  
 #define  _YOU 0XFC  
 #define  _ZONE 0XFD

#endif

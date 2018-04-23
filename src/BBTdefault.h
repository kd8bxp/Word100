#ifndef BBTdefault_h
#define BBTdefault_h

#include "Arduino.h"

#define WORD100 1
#define MILLION  1000000
#define THOUSAND 1000
#define HUNDRED  100
#define TEN     10

//CHIP SELECT 1
//COLOUR
#define _COLOUR 0x00,1 //EU SPELLING
#define _COLOR 0x00,1  //US SPELLING
#define _BLACK 0x01,1
#define _WHITE 0x02,1
#define _BLUE 0x03,1
#define _GREEN 0x04,1
#define _ORANGE 0x05,1
#define _RED 0x06,1
#define _YELLOW 0x07,1
#define _PURPLE 0x08,1

//COMMAND
#define _ABORT 0x09,1
#define _ACTIVATE 0x0A,1
#define _BEGIN 0x0B,1
#define _DEACTIVATE 0x0C,1
#define _DESTRUCT 0x0D,1
#define _GO 0x0E,1
#define _MOVE 0x0F,1
#define _OFF 0x10,1
#define _ON 0x11,1
#define _OPEN 0x12,1
#define _PULL 0x13,1
#define _PUSH 0x14,1
#define _RESET 0x15,1
#define _RUN 0x16,1
#define _STOP 0x17,1
#define _TURN 0x18,1

//MONTHS/DAYS/TIME
#define _JANUARY 0x19,1
#define _JAN 0x19,1
#define _FEBRUARY 0x1A,1
#define _FEB 0x1A,1
#define _MARCH 0x1B,1
#define _MAR 0x1B,1
#define _APRIL 0x1C,1
#define _APR 0x1C,1
#define _MAY 0x1D,1
#define _JUNE 0x1E,1
#define _JULY 0x1F,1
#define _AUGUST 0x20,1
#define _AUG 0x20,1
#define _SEPTEMBER 0x21,1
#define _SEP 0x21,1
#define _SEPT 0x21,1
#define _OCTOBER 0x22,1
#define _OCT 0x22,1
#define _NOVEMBER 0x23,1
#define _NOV 0x23,1
#define _DECEMBER 0x24,1
#define _DEC 0x24,1
#define _MONDAY 0x25,1
#define _MON 0x25,1
#define _TUESDAY 0x26,1
#define _TUE 0x26,1
#define _WEDNESDAY 0x27,1
#define _WED 0x27,1
#define _THURSDAY 0x28,1
#define _THUR 0x28,1
#define _THR 0x28,1
#define _FRIDAY 0x29,1
#define _FRI 0x29,1
#define _SATURDAY 0x2A,1
#define _SAT 0x2A,1
#define _SUNDAY 0x2B,1
#define _SUN 0x2B,1
#define _AM_ 0x2C,1
#define _PM_ 0x2D,1
#define _DATE 0x2E,1
#define _DAY 0x2F,1
#define _HOURS 0x30,1
#define _HRS 0x30,1
#define _MONTH 0x31,1
#define _OCLOCK 0x32,1
#define _TIME 0x33,1
#define _WEEK 0x34,1
#define _YEAR 0x35,1

//NUMBERS
#define _ZERO 0x36,1
#define _0 0x36,1
#define _ONE 0x37,1
#define _1 0x37,1
#define _TWO 0x38,1
#define _2 0x38,1
#define _THREE 0x39,1
#define _3 0x39,1
#define _FOUR 0x3A,1
#define _4 0x3A,1
#define _FIVE 0x3B,1
#define _5 0x3B,1
#define _SIx 0x3C,1
#define _6 0x3C,1
#define _SEVEN 0x3D,1
#define _7 0x3B,1
#define _EIGHT 0x3E,1
#define _8 0x3E,1
#define _NINE 0x3F,1
#define _9 0x3F,1
#define _TEN 0x40,1
#define _10 0x40,1
#define _ELEVEN 0x41,1
#define _11 0x41,1
#define _TWELVE 0x42,1
#define _12 0x42,1
#define _THIRTEEN 0x43,1
#define _13 0x43,1
#define _FOURTEEN 0x44,1
#define _14 0x44,1
#define _FIFTEEN 0x45,1
#define _15 0x45,1
#define _SIxTEEN 0x46,1
#define _16 0x46,1
#define _SEVENTEEN 0x47,1
#define _17 0x47,1
#define _EIGHTEEN 0x48,1
#define _18 0x48,1
#define _NINETEEN 0x49,1
#define _19 0x49,1
#define _TWENTY 0x4A,1
#define _20 0x4A,1
#define _THIRTY 0x4B,1
#define _30 0x4B,1
#define _FORTY 0x4C,1
#define _40 0x4C,1
#define _FIFTY 0x4D,1
#define _50 0x4D,1
#define _SIxTY 0x4E,1
#define _60 0x4E,1
#define _SEVENTY 0x4F,1
#define _70 0x4F,1
#define _EIGHTY 0x50,1
#define _80 0x50,1
#define _NINETY 0x51,1
#define _90 0x51,1
#define _HUNDRED 0x52,1
#define _100 0x52,1
#define _THOUSAND 0x53,1
#define _1000 0x53,1
#define _MILLION 0x54,1

//DIRECTIONS
#define _NORTH 0x55,1
#define _EAST 0x56,1
#define _SOUTH 0x57,1
#define _WEST 0x58,1
#define _UP 0x59,1
#define _DOWN 0x5A,1
#define _LEFT 0x5B,1
#define _RIGHT 0x5C,1
#define _BACKWARD 0x5D,1
#define _FORWARD 0x5E,1

//FEELINGS
#define _HAPPY 0x5F,1
#define _SAD 0x60,1
#define _ANGRY 0x61,1

//MEASUREMENT
#define _AC 0x62,
#define _AMPS 0x63,1
#define _CELSIUS 0x64,1
#define _CENTI 0x65,1
#define _CUBIC 0x66,1
#define _DC 0x67,1
#define _DEGREES 0x68,1
#define _DIAMETER 0x69,1
#define _FAHRENHEIT 0x6A,1
#define _FARADS 0x6B,1
#define _FEET 0x6C,1
#define _FREQUENCY 0x6D,1
#define _GIGA 0x6E,1
#define _GRAM 0x6F,1
#define _HEIGHT 0x70,1
#define _HERTZ 0x71,1
#define _HUMIDITY 0x72,1
#define _INCHES 0x73,1
#define _KILO 0x74,1
#define _LENGTH 0x75,1
#define _LIGHT 0x76,1
#define _LITRE 0x77,1
#define _MEGA 0x78,1
#define _METERS 0x79,1
#define _MICRO 0x7A,1
#define _MILLI 0x7B,1
#define _MINUTES 0x7C,1
#define _NANO 0x7D,1
#define _NEWTON 0x7E,1
#define _NIGHT 0x7F,1
#define _OHMS 0x80,1
#define _PER 0x81,1
#define _PICO 0x82,1
#define _PITCH 0x83,1
#define _POUNDS 0x84,1
#define _RADIUS 0x85,1
#define _RATE 0x86,1
#define _SECONDS 0x87,1
#define _SOUND 0x88,1
#define _SPEED 0x89,1
#define _TEMPERATURE 0x8A,1
#define _VOLTS 0x8B,1
#define _WATTS 0x8C,1
#define _WEIGHT 0x8D,1

//SECURITY
#define _ALARM 0x8E,1
#define _ALERT 0x8F,1
#define _DETECTED 0x90,1
#define _INTRUDER 0x91,1
#define _SECURITY 0x92,1
#define _SYSTEM 0x93,1
#define _WARNING 0x94,1

//MATH
#define _CLOCKWISE 0x95,1
#define _COUNTER 0x96,1
#define _DIVIDE 0x97,1
#define _EQUALS 0x98,1
#define _MINUS 0x99,1
#define _MULTIPLY 0x9A,1
#define _NOT 0x9B,1
#define _PLUS 0x9C,1
#define _SQUARE_ROOT 0x9D,1

 //WORDS GENERAL
 #define _A_ 0x9E,1  //DIFFERENCE HERE _A_ ENGLISH FEMALE
 #define _AHEAD 0x9F,1
 #define _AIR 0xA0,1
 #define _ALTITUDE 0xA1,1
 #define _AN 0xA2,1
 #define _AM 0xA3,1 //AM NOT A.M.
 #define _AND 0xA4,1
 #define _ARE 0xA5,1
 #define _AREA 0xA6,1
 #define _AT 0xA7,1
 #define _AXIS 0xA8,1
 #define _BACK 0xA9,1
 #define _BE 0xAA,1
 #define _BEARING 0xAB,1
 #define _BEEN 0xAC,1
 #define _BUTTON 0xAD,1
 #define _BY 0xAE,1
 #define _CAN 0xAF,1
 #define _CAUTION 0xB0,1
 #define _CHANGE 0xB1,1
 #define _CHECK 0xB2,1
 #define _CLOSED 0xB3,1
 #define _CONDITION 0xB4,1
 #define _CONTACT 0xB5,1
 #define _CRITICAL 0xB6,1
 #define _DOOR 0xB7,1
 #define _EMPTY 0xB8,1  
 #define _END 0xB9,1  
 #define _ENVIRONMENT 0xBA,1  
 #define _FALLING 0xBB,1  
 #define  _FAST 0xBC,1  
 #define  _FATAL 0xBD,1  
 #define  _FEEL 0xBE,1  
 #define  _FIRST 0xBF,1  
 #define  _FROM 0xC0,1  
 #define  _FRONT 0xC1,1  
 #define  _GOING 0xC2,1  
 #define  _GOODBYE 0xC3,1  
 #define  _HE  0xC4,1  
 #define  _HELLO 0xC5,1  
 #define  _HIGH 0xC6,1  
 #define  _HOW 0xC7,1  
 #define  _I_ 0xC8,1 //DIFFERENCE HERE _A_ ENGLISH FEMALE  
 #define  _IN  0xC9,1  
 #define  _INCOMING 0xCA,1  
 #define  _ING 0xCB,1  
 #define  _INSIDE 0xCC,1  
 #define  _IS 0xCD,1  
 #define  _IT 0xCE,1  
 #define  _LASER 0xCF,1  
 #define  _LAST 0xD0,1  
 #define  _LEVEL 0xD1,1  
 #define  _LOCKED 0xD2,1  
 #define  _LOW 0xD3,1  
 #define  _ME 0xD4,1  
 #define  _MESSAGE 0xD5,1  
 #define  _MODE 0xD6,1  
 #define  _MOTOR 0xD7,1  
 #define  _NEW 0xD8,1  
 #define  _NEXT 0xD9,1  
 #define  _NOMINCAL 0xDA,1  
 #define  _OBJECT 0xDB,1  
 #define  _OBSTACLE 0xDC,1  
 #define  _OF 0xDD,1  
 #define  _OUT 0xDE,1  
 #define  _OUTSIDE 0xDF,1  
 #define  _PRESS 0xE0,1  
 #define  _PROCESS 0xE1,1  
 #define  _PURGE 0xE2,1  
 #define  _RANGE 0xE3,1  
 #define  _REAR 0xE4,1  
 #define  _RECEIVED 0xE5,1  
 #define  _RISING 0xE6,1  
 #define  _SENT 0xE7,1  
 #define  _SEQUENCE 0xE8,1  
 #define  _SHE 0xE9,1  
 #define  _SLEEP 0xEA,1  
 #define  _SLOW 0xEB,1 
 #define  _STABLE 0xEC,1  
 #define  _START 0xED,1  
 #define  _STEP 0xEE,1  
 #define  _STEPPER 0xEF,1  
 #define  _SWITCH 0xF0,1  
 #define  _TELL 0xF1,1  
 #define  _THE 0xF2,1  
 #define  _THERE 0xF3,1  
 #define  _THEY 0xF4,1  
 #define  _TO  0xF5,1  
 #define  _TOTAL 0xF6,1  
 #define  _VENT 0xF7,1  
 #define  _WE  0xF9,1  
 #define  _WILL 0xFA,1  
 #define  _WINDOW 0xFB,1  
 #define  _YOU 0xFC,1  
 #define  _ZONE 0xFD,1

//CHIP SELECT 2 ALAPHABETS

//NATO PHONETIC ALPHABET
#define _ALPHA 0xD0,2
#define _BRAVO 0xD1,2
#define _CHARLIE 0xD2,2
#define _DELTA 0xD3,2
#define _ECHO 0xD4,2
#define _FOXTROT 0xD5,2
#define _GOLF 0xD6,2
#define _HOTEL 0xD7,2
#define _INDIA 0xD8,2
#define _JULIET 0xD9,2
#define _KILO 0xDA,2
#define _LIMA 0xDB,2
#define _MIKE 0xDC,2
#define _NOVEMBER 0xDD,2
#define _OSCAR 0xDE,2
#define _PAPA 0xDF,2
#define _QUEBEC 0xE0,2
#define _ROMEO 0xE1,2
#define _SIERRA 0xE2,2
#define _TANGO 0xE3,2
#define _UNIFORM 0xE4,2
#define _VICTOR 0xE5,2
#define _WHISKEY 0xE6,2
#define _XRAY 0xE7,2
#define _YANKEE 0xE8,2
#define _ZULU 0xE9,2

//TRANSMISSION WORD
#define _BRACKET 0xEA,2
#define _BREAK 0xEB,2
#define _CODE 0xEC,2
#define _COLON 0xED,2
#define _COMMAN 0xEE,2
#define _DELETE 0xEF,2
#define _END 0xF0,2
#define _ENTER 0xF1,2
#define _ESCAPE 0xF2,2
#define _INSERT 0xF3,2
#define _OVER 0xF4,2
#define _PASS 0xF5,2
#define _PAUSE 0xF6,2
#define _PERIOD 0xF7,2
#define _POUND 0xF8,2
#define _SEQUENCE 0xF9,2
#define _SPACE 0xFA,2
#define _STAR 0xFB,2
#define _START 0xFC,2
#define _TRANSMIT 0xFD,2

//CURRENTLY UNKNOWN
#define _POINT
#define _PERIOD
#define _ISH
#define _ER
#define _LESS
#define _ABLE
#define _UN
#define _DE
#define _MULTI
#define _BYTE
#define _BIT
#define _WORD
#define _ARDUINO
#define _LEONARDO
#define _UNO
#define _DECI
#define _MINIMUM
#define _MAXIMUM
#define _FIRST
#define _SECOND
#define _THIRD
#define _FOURTH
#define _FIFTH
#define _SIXTH
#define _SEVENTH
#define _EIGHTN
#define _NINTH
#define _TENTH
#define _REACTOR
#define _LINE
#define _SENSORS
#define _ALL
#define _SYSTEMS
#define _LEG
#define _ARM
#define _HAND
#define _FEET
#define _HEAD
#define _BODY
#define _OFFLINE
#define _HEAT
#define _ENEMY
#define _INCOMING
#define _VISION
#define _SINK
#define _ROGER
#define _REPEAT
#define _COMMAND
#define _RESPOND
#define _REGROUP
#define _ASSHOLE
#define _FUCK
#define _DANGER
#define _EXTERMINATE
#define _MILES
#define _SPEAK
#define _CHOOSE
#define _CHOICE
#define _BOTH
#define _EITHER
#define _NEITHER
#define _ZED
#define _CAPTAIN
#define _SCIENCE
#define _OFFICER
#define _COMMUNICATIONS
#define _ENGINEERING
#define _BRIDGE
#define _SICK
#define _BAY
#define _ERROR
#define _PASCALS
#define _HECTO
#define _CYCLONIC
#define _ANTI
#define _TYPHOON
#define _HURRICANE
#define _OCCLUDED
#define _SNOW
#define _SLEET
#define _RAIN
#define _SUNNY
#define _CLOUDY
#define _FOG
#define _VISIBILITY
#define _PAGE
#define _SHIFT
#define _KEY
#define _TAB
#define _HEARTS
#define _CLUBS
#define _SPADES
#define _DIAMONDS
#define _KING
#define _QUEEN
#define _JACK
#define _JOKER
#define _TOWER
#define _DOOR
#define _PUMP
#define _BOILER
#define _HOT_TUB
#define _FILTER
#define _BACK
#define _DOOR_BELL
#define _VALVE
#define _WAY
#define _SIDE
#define _FRONT
#define _PRESSED
#define _OPENED
#define _LOWERED
#define _WINDER
#define _SHUTTER
#define _SLEEPING
#define _DINING
#define _KITCHEN
#define _SALON
#define _OFFICE
#define _GARDEN
#define _STREET
#define _ROOF
#define _WALL
#define _MOWER
#define _WATER
#define _BALCONY
#define _POOL
#define _HEATER
#define _CENTRAL
#define _FLOOR
#define _BARN
#define _STABLE
#define _ROUTER
#define _MODEM
#define _COMPUTER
#define _SENSOR
#define _CLOUD
#define _REBOOT_NETWORK
#define _RASPBERRY
#define _PIE
#define _WITH
#define _STAIRS
#define _AGENDA
#define _APARTMENT
#define _VISITOR
#define _GUEST
#define _DINNER
#define _BREAKFAST
#define _KIDS
#define _ADULTS
#define _ANIMAL
#define _CAT
#define _SHEEP
#define _DOG
#define _SOMEONE
#define _KIAORA
#define _PISS
#define _DAMN
#define _HALF
#define _QUARTER
#define _CANADA
#define _AUSTRIA
#define _GERMANY
#define _RUSSIA
#define _ITALY
#define _SPAIN
#define _JAPAN
#define _PRE
#define _POST
#define _GRAYS
#define _SIEVERTS
#define _TESLA
#define _NOZZLE
#define _FILAMENT
#define _THREEMA
#define _SIGNAL
#define _WHATSAPP
#define _TELEGRAM
#define _FACEBOOK
#define _GOOGLE
#define _TWITTER
#define _DIASPORA
#define _YOUTUBE
#define _NIBBLE
#define _AGENDA
#define _APARTMENT
#define _CHEESE
#define _FIRE
#define _EVACUATE
#define _REQUEST
#define _USER
#define _PAST
#define _SHOP
#define _SAY
#define _FUEL
#define _MANOUVER
#define _TARGET
#define _SURFACE
#define _BOO
#define _SCARED
#define _ENIGMA
#define _ENCRYPTION
#define _APOLLO
#define _KEYBOARD
#define _GUIDANCE
#define _BEER
#define _PIZZA
#define _ALCHOL
#define _SOLDERING
#define _IRON
#define _DRINK
#define _BAR
#define _OVERLORD
#define _HUNT
#define _GREAT
#define _COCONUT
#define _APOCALYPSE
#define _KITTY
#define _CYANIDE
#define _ROCK
#define _PAPER
#define _SCISSORS
#define _LIZARD
#define _SPOCK
#define _ESCAPE
#define _ROOM
#define _JESUS
#define _GOD
#define _SIR
#define _MADAM
#define _CARRIER
#define _ESTBLISHED
#define _ARRAY
#define _TREE
#define _FLOWER
#define _LAKE
#define _BEACH
#define _SEA
#define _GRASS
#define _PALM
#define _RIVER
#define _STREET
#define _PATH
#define _NARROW
#define _WIDE
#define _LOG_ON
#define _LOG_OUT
#define _SPEAKERS
#define _JESTER
#define _ICY
#define _SMILING
#define _WORDS
#define _IDENTIFIED
#define _GET_DUNKED_ON
#define _BATTERY
#define _CAMERA
#define _CHARGE
#define _CHARGING
#define _FAN
#define _GAIN
#define _INTERNET
#define _LOCKED
#define _MEMORY
#define _OUTLET
#define _POWER
#define _PRINT
#define _RADIO
#define _RECALL
#define _REFLECTED
#define _RESUME
#define _ROTATE
#define _SCAN
#define _SET
#define _TUNE
#define _VOLUME
#define _AUS
#define _CHINA
#define _UNITED
#define _STATES
#define _THINKING
#define _INDEX
#define _GROOVY
#define _RISE
#define _SET
#define _SUN_ //NOT SAME AS SUNDAY THIS IS THE BIG WHITE BALL IN SPACE
#define _BEFORE
#define _AFTER
#define _NOW
#define _WAS
#define _BELEUCHTUNG
#define _LICHT
#define _STECKDOSE
#define _WOHNZIMMER
#define _FLUR
#define _KINDERZIMMER
#define _KUCHE //NEED DOTS ABOVE U
#define _BAD
#define _ARBEITSZIMMERUNTIL //??
#define _GUST
#define _STEADY
#define _CALM
#define _CREAMY




#endif

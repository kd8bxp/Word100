/*

  This example can say a number from zero to 999999999, speaking not only the digit
  but also the value (hundreds, thousands, millions). Thanks you Matt for making it.

  The "100+ Word" Arduino Audio Shield! Speak Arduino, Speak!
  by Patrick Thomas Mitchell
  http://www.engineeringshock.com/100-word-arduino-audio-shield.html

  Example by Matt Ganis (matt.ganis@gmail.com) or @mattganis on Twitter


  Copyright (c) 2018 Matt Ganis

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
   Mar 19, 2018 - Added underscores to work with v2.1.0 of library
   -LeRoy Miller
   This will also work for the 100+ Word Shield using either chip
	Cleaned up code a little, corrected a issue that zero was being said if
  thousands or millions ended in zero.

*/

/* LBT Arduino UNO Hookup
   LBT CS to Arduino PIN 10
   LBT SC to Arduino PIN 13
   LBT DI to Arduino PIN 11
*/

/*
  The HAM chip is missing AM and PM, was setAMPM removed, and times are only
  given in 24 hour/Military style
*/
/*
   May 6, 2018 Updated Example to work with BBT

   Big Buddy Talker Arduino UNO Hookup
  BBT CS1 to Arduino PIN 7
  BBT CS2 to Arduino PIN 8
  BBT CS3 to Arduino PIN 9
  BBT CS4 to Arduino PIN 10
  BBT SC to Arduino PIN 13
  BBT DI to Arduino PIN 11
*/

//Uncomment for the device of your choice.
//#include "Word100LBT.h"; //If using a Little Buddy Talker
//#include "Word100Ham.h"; //Works with the 100+ Word Shield and Ham chip
//#include "Word100.h"; //Works with the 100+ Word Shield standard chip
#include "Word100BBT.h"; //Use for the Big Buddy Talker

#define CS_PIN 10 //CS pin of your device. (Used for 100+ Word Shield, and LBT)

//The Big Buddy Talker uses 4 CS select pins.
#define CS1_PIN 7
#define CS2_PIN 8
#define CS3_PIN 9
#define CS4_PIN 10

//Uncomment to match your device.
//Word100lbt Word100(CS_PIN); //use Word100lbt for the Little Buddy talker
//Word100ham Word100(CS_PIN); //use with 100+ Word Shield Ham chip
//Word100 Word100(CS_PIN); //use with 100+ Word Shield standard chip
Word100bbt Word100(CS1_PIN, CS2_PIN, CS3_PIN, CS4_PIN); //cs pins

void setup() {

  Serial.begin(9600);
  Word100.begin();
  delay(1000);

}

void loop() {
  long num;

  num = 95347834; //Any number from 0 to 999999999  There is no error checking
  Word100.sayNumber(num);

  delay(2000);

  Word100.setAMPM(false); //Military/24 HR times
  Word100.sayHours(13);
  Word100.sayMinutes(37);

  delay(2000);

  Word100.setAMPM(true); //AMPM
  Word100.sayHours(13);
  Word100.sayMinutes(37); //PM

  delay(1000);

  Word100.sayHours(1);
  Word100.sayMinutes(37); //AM

  while (1) {}

}

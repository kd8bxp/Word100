/*
 * This program shows an example of using a multidimensional array to set timings for each word.
 * It also repeats the sentences with the default timings of 700, so you can hear the differences.
 *
 *setDelay(int number) - only works with the Little Buddy Talker for now.
 *
 
The "100+ Word" Arduino Audio Shield! Speak Arduino, Speak!
by Patrick Thomas Mitchell
http://www.engineeringshock.com/100-word-arduino-audio-shield.html

Library version 1.0 Sept 23, 2017 by LeRoy Miller

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
 * Mar 26, 2018 - v1.0 of sketch LeRoy Miller (C) 2018 
 */

 
/* Arduino UNO Hookup
 * LBT CS to Arduino PIN 10 
 * LBT SC to Arduino PIN 13 
 * LBT DI to Arduino PIN 11
 *
 * Wemos D1 Mini and Other ESP8266 Based Devices
 * LBT CS to D0 
 * LBT SC to D5
 * LBT DI to D7
 * 
 * Some ESP8266 devices need the GPIO PIN number. 
 */

#include "Word100LBT.h"; //Notice that LBT now has it's own library

#define CS_PIN 10 // use D0 for the Wemos D1 Mini

//use Word100lbt for the Little Buddy talker
Word100lbt Word100(CS_PIN); //cs pin 

int sentence[] = {_ONE, _TWO, _THREE, _FOUR, _FIVE, _SIX, _SEVEN, _EIGHT, _NINE, _TEN};
int sentence2[] = {_ALERT, _ALERT, _INTRUDER, _IN, _ZONE, _TWO};

//In This example we have a multidensional array, with the first number being the word to be said, and the 2nd number the delay to wait for saying that word.
//This works but isn't pretty to look at. 
int timings[10][10] = {
  {_ONE, 100}, //100 is too short
  {_TWO, 500},
  {_THREE, 300}, 
  {_FOUR, 350}, //350 is too short
  {_FIVE, 700},
  {_SIX, 400},
  {_SEVEN, 700},
  {_EIGHT, 700},
  {_NINE, 100}, //100 is too short
  {_TEN, 700}
};

int timings2[6][6] = {
  {_ALERT, 400},
  {_ALERT, 400},
  {_INTRUDER, 700},
  {_IN, 200},
  {_ZONE, 650},
  {_TWO, 700}
};

//You can play around with various words and timings here.

void setup() {
  Serial.begin(9600);
Word100.begin();

}

#define arr_len( x ) ( sizeof ( x ) / sizeof (*x) )

void loop() {

Serial.println("One, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten");
Serial.println("Using Timings Multidimensional Array");
for (int i=0; i < arr_len(timings); i++) {
  Word100.setDelay(timings[i][1]);
  Word100.say(timings[i][0]);
}

delay(1000);

Serial.println("Same sentence, but using default timings of 700");
  Word100.setDelay(700); //700 is the default timing for the LBT
  //say the first sentence (Count to Ten)
  //Serial.print(arr_len(sentence));
  for (int i = 0; i < arr_len(sentence); i++) {
  Word100.say(sentence[i]);
}

delay(1000); //wait for one second
Serial.println("Alert, Alert, Intruder in zone two.");
Serial.println("Using Timings from multidimensional array.");
for (int i=0; i< arr_len(timings2); i++) {
  Word100.setDelay(timings2[i][1]);
  Word100.say(timings2[i][0]);
}

delay(1000);

Serial.println("Same sentence, but using default timings of 700");
Word100.setDelay(700); //700 is the default timing for the LBT
//say the second sentence (Alert Alert intruder in zone two)
 //Serial.println(arr_len(sentence2));
 for (int i = 0; i < arr_len(sentence2); i++) {
 Word100.say(sentence2[i]);
}

while(1) {
//yield(); //Uncomment for ESP8266 Devices, otherwise a WDT reset happens.
 }
}

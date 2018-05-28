/*
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
/* May 11, 2018 - Big Buddy Talker Example Two, compound words and
 *  timings.
 *  Word timings can be set on the fly, see the code below.
 *  This does take some trial and error, but produces some nice effects.
 *  Copyright (c) 2018 LeRoy Miller
 * Updated May 28, 2018 - LeRoy Miller
 */
 
/* Big Buddy Talker Arduino UNO Hookup
 * BBT CS1 to Arduino PIN 7 
 * BBT CS2 to Arduino PIN 8
 * BBT CS3 to Arduino PIN 9
 * BBT CS4 to Arduino PIN 10 
 * BBT SC to Arduino PIN 13 
 * BBT DI to Arduino PIN 11
 *
 *May 5, 2018 - BBT hasn't been tested with the D1 Mini yet, I believe these pins should work.
 * Wemos D1 Mini and Other ESP8266 Based Devices
 * BBT CS1 to D1
 * BBT CS2 to D2
 * BBT CS3 to D3
 * BBT CS4 to D0 
 * BBT SC to D5
 * BBT DI to D7
 * 
 * Some ESP8266 devices need the GPIO PIN number. 
 */

#include "Word100BBT.h"; 

//The Big Buddy Talker uses 4 CS select pins.
#define CS1_PIN 7
#define CS2_PIN 8
#define CS3_PIN 9
#define CS4_PIN 10

Word100bbt Word100(CS1_PIN, CS2_PIN, CS3_PIN, CS4_PIN); //cs pins 


void setup() {
Serial.begin(9600); 
Word100.begin();
Serial.println("Compound Words");

}

#define arr_len( x ) ( sizeof ( x ) / sizeof (*x) )

void loop() {

//Sounds Robotic....
Word100.say(_HELLO);
Word100.say(_BIG);
Word100.say(_BUDDY);

 /*counterclockwise
  * By Changing the timing of the 1st word
  * we can make it sound more natural.
  * Remember timings have to be set before you 
  * say the word.
  *
  * Timings are tricky and take some trial and error
  * to get right.
  * 
  * Big Buddy Talker has a default timing of 850, which is too
  * long for most words, but needed for the few really long words/sentences
  * Under most conditions a timing of 700 works pretty well, but does
  * sound a little robotic.
  */
  
  Word100.setDelay(475);
  Word100.say(_COUNTER);
  Word100.setDelay(700); //timing that works for most words
  Word100.say(_CLOCKWISE);

//lighting
 Word100.setDelay(450);
 Word100.say(_LIGHT);
 Word100.setDelay(700); //timing that works for most words
 Word100.say(_ING);

//micrometers
Word100.setDelay(450);
Word100.say(_MICRO);
Word100.setDelay(700);
Word100.say(_METERS);

//millimeters
Word100.setDelay(400);
Word100.say(_MILLI);
Word100.setDelay(700);
Word100.say(_METERS);

//kilometers (Doesn't quite sound right because of the KILO preface)
Word100.setDelay(400);
Word100.say(_KILO);
Word100.setDelay(700);
Word100.say(_METERS);

//kilogram (Doesn't quite sound right because of the KILO preface)
Word100.setDelay(400);
Word100.say(_KILO);
Word100.setDelay(700);
Word100.say(_GRAM);

//milligram
Word100.setDelay(400);
Word100.say(_MILLI);
Word100.setDelay(700);
Word100.say(_GRAM);

//escaperoom
Word100.setDelay(450);
Word100.say(_ESCAPE);
Word100.setDelay(700);
Word100.say(_ROOM);

//dozens of words can be made like this, and by adjusting
//timings, can sound quite good.

/*
 * In this example we will setup a sentance array, with
 * timings added.
 * Remember the defined words are two parts, so the array
 * is multidimisional.
 * _COLOR is defined as 0x00,1 which is location 0 on the 1st chip.
 * We are going to add some timing to this.
 */

// Word Adress, CHIP #, Timing 
// (remember _COLOR is 0x00,1 for example)

int sentance[17][3] = {
  {_COUNTER,475},
  {_CLOCKWISE,700},
  {_LIGHT, 450},
  {_ING, 700},
  {_MICRO, 450},
  {_METERS, 700},
  {_MILLI, 400},
  {_METERS, 700},
  {_KILO, 400},
  {_METERS, 700},
  {_KILO, 400},
  {_GRAM, 700},
  {_MILLI, 400},
  {_GRAM, 700},
  {_ESCAPE, 450},
  {_ROOM, 700},
};

for (int i=0; i< arr_len(sentance); i++) {
  
  Word100.setDelay(sentance[i][2]); //Timings need to be set first for each word.
  Word100.say(sentance[i][0],sentance[i][1]);
}

//We can also use the above to create more natural sounding sentances, with some trail and error for the timings.

while(1) {
//yield(); //Uncomment for ESP8266 Devices, otherwise a WDT reset happens.
 }
}

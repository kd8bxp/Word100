/*
 * BBT Alphabet Example.
Copyright (c) 2018 LeRoy Miller

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

If you find this or any of my projects useful or enjoyable please support me.  
Anything I do get goes to buy more parts and make more/better projects.  
https://www.patreon.com/kd8bxp  
https://ko-fi.com/lfmiller  

https://github.com/kd8bxp
https://www.youtube.com/channel/UCP6Vh4hfyJF288MTaRAF36w  
https://kd8bxp.blogspot.com/  
*/

/* 
 * The alphbets are stored as individual library (.h) files
 * because there are 8 different langauges included,
 * and each one uses the same "A to Z" "words".
 * if you want a different alphabet all you have to do is change
 * the library file, and don't have to make a bunch of
 * changes to your sketch.
 * This shows that as an example.
 * 
 * Big Buddy Talker Arduino UNO Hookup
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

//only the base words are included by default.
#include "Word100BBT.h"; 

//so to include an alphabet we need to include it here.
#include "BBTEnglishM.h"; //English Male 0x00 to 0x19
//#include "BBTEnglishF.h"; //English Female 0x1A to 0x33
//#include "BBTFrench.h"; //French 0x34 to 0x4D
//#include "BBTGerman.h"; //German 0x4E to 0x67
//#inlcude "BBTItalian.h"; //Italian 0x68 to 0x81
//#include "BBTPortuguese.h"; //Portuguese 0x82 to 0x9B
//#include "BBTRussian.h"; //Russian  0x9C to 0xB5
//#include "BBTSpanish.h"; //Spanish 0xB6 to 0XCF

//Only inlcude one of the Alphabets from above otherwise
//you'll get the last one included.

//The Big Buddy Talker uses 4 CS select pins.
#define CS1_PIN 7
#define CS2_PIN 8
#define CS3_PIN 9
#define CS4_PIN 10

Word100bbt Word100(CS1_PIN, CS2_PIN, CS3_PIN, CS4_PIN); //cs pins 

#define arr_len( x ) ( sizeof ( x ) / sizeof (*x) )

//Setup the Alphabet "Sentence"
int sentance[27][2] = {{_A},{_B},{_C},{_D},{_E},{_F},{_G},{_H},{_I},{_J},{_K},{_L},{_M},{_N},{_O},{_P},{_Q},{_R},{_S},{_T},{_U},{_V},{_W},{_X},{_Y},{_Z}};


void setup() {
  Serial.begin(9600); 
Word100.begin();

}

void loop() {

 //This will say the alphabet in the langauge selected above
  for (int i=0; i< arr_len(sentance); i++) {
    Word100.say(sentance[i][0],sentance[i][1]);
}

//but what if we need two langauges for some reason.
//We can still use the other alphabets, but need to know
//the location, and chip they are on (It's always chip 2)

//Here I am going to say the German alphabet using memory locations.
//The German alphabet is at location 0x4E (A) to 0x67 (Z) on chip 2.

for (int i=0x4E; i < 0x68; i++ ) {
  Word100.say(i, 2); //memory location, chip number 
}

//to say all the alphbets, no matter which one is selected
//we could do something like this

for (int i=0x00; i <=0XCF; i++) {
  Word100.say(i,2); //memory location, chip number
}

while(1) {}
}

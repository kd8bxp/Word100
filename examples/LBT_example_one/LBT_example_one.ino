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

/*
 * Mar 6, 2018 - Updated to work with the Little Buddy Talker
 * http://www.engineeringshock.com/the-little-buddy-talker-project-page.html
 * LeRoy Miller, (c) 2018
 * Mar 11, 2018 Updated words start with underscore.
 * A.M. is _am_ and P.M. is _pm_
 * Based on feedback from user jjdeprisco (Thank You)
 * LeRoy Miller, (C) 2018
 * Ver 1.5.2

Mar 19, 2018 - Cleaned up code a bit. Found a few words that didn't have underscores added and corrected. Split the libraries apart because of a problem that was found with the LBT and Orignal 100+ Word code
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

void setup() {
  
Word100.begin();

}

#define arr_len( x ) ( sizeof ( x ) / sizeof (*x) )

void loop() {
  
  //say the first sentence (Count to Ten)
  Serial.print(arr_len(sentence));
  for (int i = 0; i < arr_len(sentence); i++) {
  Word100.say(sentence[i]);
}

delay(1000); //wait for one second

//say the second sentence (Alert Alert intruder in zone two)
 Serial.println(arr_len(sentence2));
 for (int i = 0; i < arr_len(sentence2); i++) {
 Word100.say(sentence2[i]);
}

delay(1000);


//say all the words. using the words as counters
for (int i = _COLOUR; i < _ZONE+1; i++) {
  Word100.say(i);
}

delay(1000);

//we can just call say(xxx)

Word100.say(_RED);
Word100.say(_ALERT);
delay(1000);

while(1) {
//yield(); //Uncomment for ESP8266 Devices, otherwise a WDT reset happens.
 }
}

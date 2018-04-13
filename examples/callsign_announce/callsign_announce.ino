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
 * Mar 11, 2018 Updated words start with underscore.
 * A.M. is _am_ and P.M. is _pm_
 * Based on feedback from user jjdeprisco (Thank You)
 * LeRoy Miller, (C) 2018
 * Ver 1.5.1

Mar 19, 2018 - Corrected problem with library version 2.1.0.
Cleaned this code up a little.
 */

//This include is all that changed.
#include "Word100Ham.h"; //Note Changes here! Mar 19, 2018 

#define CS_PIN 10

//Use Word100ham for the secondary "ham" chip of the 100+ Word Shield
Word100ham Word100(CS_PIN); //cs pin

int sentence[] = {_K, _D, _8, _B, _X, _P};
int sentence2[] = {_KILO, _DELTA, _EIGHT, _BRAVO, _XRAY, _PAPA};

void setup() {
  // put your setup code here, to run once:
Word100.begin();

}

#define arr_len( x ) ( sizeof ( x ) / sizeof (*x) )

void loop() {

  //say the first sentence (Count to Ten)
  Serial.print(arr_len(sentence));
  for (int i = 0; i < arr_len(sentence); i++) {
  Word100.say(sentence[i]);
}

delay(1000); //wait for 1 second

  //say the second sentence
  Serial.println(arr_len(sentence2));
  for (int i = 0; i < arr_len(sentence2); i++) {
  Word100.say(sentence2[i]);
}

delay(1000);

//say all the words. using the words as counters
for (int i = _A; i < _WATTS + 1; i++) {
  Word100.say(i);
}

delay(1000);

//we can just call say(xxx)

Word100.say(_ONE);
Word100.say(_MILLION);

while(1);
}

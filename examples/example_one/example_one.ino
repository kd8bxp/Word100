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

#include "Word100.h";

Word100 Word100(10);

int sentence[] = {_one, _two, _three, _four, _five, _six, _seven, _eight, _nine, _ten};
int sentence2[] = {_alert, _alert, _intruder, _in, _zone, _two};

void setup() {
  // put your setup code here, to run once:
Word100.begin();

}

#define arr_len( x ) ( sizeof ( x ) / sizeof (*x) )

void loop() {

  //say the first sentence (Count to Ten)
  Serial.print(arr_len(sentence));
  // put your main code here, to run repeatedly:
for (int i = 0; i < arr_len(sentence); i++) {
  Word100.say(sentence[i]);
}

delay(1000);

//say the second sentence (Alert Alert intruder in zone two)
 Serial.println(arr_len(sentence2));
  // put your main code here, to run repeatedly:
for (int i = 0; i < arr_len(sentence2); i++) {
  Word100.say(sentence2[i]);
}

delay(1000);

//say all the words. using the words as counters
for (int i = _colour; i < _zone; i++) {
  Word100.say(i);
}

delay(1000);

//we can just call say(xxx)

Word100.say(_red);
Word100.say(_alert);
delay(1000);

while(1);
}

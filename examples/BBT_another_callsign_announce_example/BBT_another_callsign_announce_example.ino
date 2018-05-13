/*
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
 * Mar 11, 2018 Updated words start with underscore.
 * A.M. is _am_ and P.M. is _pm_
 * Based on feedback from user jjdeprisco (Thank You)
 * LeRoy Miller, (C) 2018
 * Ver 1.5.1

Mar 19, 2018 - Corrected problem with library version 2.1.0.
Cleaned this code up a little.

May 5, 2018 - Updated for BBT.
 */

//This include is all that changed.
#include "Word100BBT.h"; //Note Changes here! Mar 19, 2018 
#include "BBTEnglishM.h"; //Alphabet will be spoken in English in male voice.
//#include "BBTEnglishF.h"; //Uncomment if you'd like the Alphabet spoken in female voice

//The Big Buddy Talker uses 4 CS select pins.
#define CS1_PIN 7
#define CS2_PIN 8
#define CS3_PIN 9
#define CS4_PIN 10

//Use Word100ham for the secondary "ham" chip of the 100+ Word Shield
Word100bbt Word100(CS1_PIN, CS2_PIN, CS3_PIN, CS4_PIN); 

int sentence[9][2] = {{_HERE}, {_IS}, {_K}, {_D}, {_8}, {_B}, {_X}, {_P}};
int sentence2[9][2] = {{_HERE}, {_IS}, {_KILO}, {_DELTA}, {_EIGHT}, {_BRAVO}, {_XRAY}, {_PAPA}};

void setup() {
Serial.begin(9600);  
Word100.begin();

}

#define arr_len( x ) ( sizeof ( x ) / sizeof (*x) )

void loop() {

  //say the first sentence 
  Serial.print(arr_len(sentence));
 for (int i = 0; i < arr_len(sentence); i++) {
 Word100.say(sentence[i][0],sentence[i][1]);
 
}

delay(1000); //wait for 1 second

  //say the second sentence
  Serial.println(arr_len(sentence2));
  for (int i = 0; i < arr_len(sentence2); i++) {
  Word100.say(sentence2[i][0],sentence[i][1]);
}


while(1);
}

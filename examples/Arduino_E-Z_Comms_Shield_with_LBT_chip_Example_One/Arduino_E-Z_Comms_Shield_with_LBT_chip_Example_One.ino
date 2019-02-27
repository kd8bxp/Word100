/*

For use with the Arduino E-Z Comms Shield (With LBT chip) by Patrick Thomas Mitchell
http://www.engineeringshock.com/arduino-e-z-comms-project-page.html

If you find this or any of my projects useful or enjoyable please support me.  
Anything I do get goes to buy more parts and make more/better projects.  
https://www.patreon.com/kd8bxp  
https://ko-fi.com/lfmiller  

Copyright (c) 2019 LeRoy Miller

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


#include "Word100LBT.h"; //Notice that LBT now has it's own library
#include "LiquidCrystal.h" 

#define CS_PIN 10 // use D0 for the Wemos D1 Mini
#define LED1 1  // First LED controlled by GPIO1
#define LCDen 3 // LCB backlight control by GPIO3
#define LED2 2  // Second LED controlled by GPIO2

LiquidCrystal lcd(4,5,6,7,8,9); //LCD pins RS/E/D4/D5/D6/D7 connected to UNO pins 4,5,6,7,8,9 Respectively

//use Word100lbt for the Little Buddy talker
Word100lbt Word100(CS_PIN); //cs pin 

int sentence[] = {_ONE, _TWO, _THREE, _FOUR, _FIVE, _SIX, _SEVEN, _EIGHT, _NINE, _TEN};
int sentence2[] = {_ALERT, _ALERT, _INTRUDER, _IN, _ZONE, _TWO};

void setup() {
  
Word100.begin();
lcd.begin(16,02);              // 16 characters/2 lines
  lcd.clear();                   // Clear LCD
  pinMode(LCDen,OUTPUT);         // Declare I/Os
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  digitalWrite(LCDen,HIGH);      // Turn backlight on, and LEDs off
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  delay(10);
  lcd.print("* Arduino  E-Z *");
  lcd.setCursor(0,1);
  lcd.print("* Comms Shield *");
  delay(100);
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

lcd.clear();
//say all the words. using the words as counters
for (int i = _COLOUR; i < _ZONE+1; i++) {
  lcd.setCursor(0,0);
  lcd.print("Word #: ");
  lcd.setCursor(8,0);
  lcd.print(i);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, HIGH);
  Word100.say(i);
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, LOW);
  delay(100);
}

delay(1000);

digitalWrite(LED1, LOW);
digitalWrite(LED2, LOW);

//we can just call say(xxx)
lcd.clear();
lcd.setCursor(0,0);
lcd.print("RED ALERT!");
Word100.say(_RED);
Word100.say(_ALERT);
delay(1000);

lcd.clear();
int brightness = 0;
int fadeAmount = 5;
lcd.setCursor(5,0);
lcd.print("Fade!");

do {


analogWrite(LCDen, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
} while(1);

}

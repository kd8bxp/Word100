/*
Talking Time Clock Example Code.

If you find this or any of my projects useful or enjoyable please support me.  
Anything I do get goes to buy more parts and make more/better projects.  
https://www.patreon.com/kd8bxp  
https://ko-fi.com/lfmiller  

Copyright (c) 2018 LeRoy Miller
Portions of code based on saynumber example
by Matt Ganis (matt.ganis@gmail.com) or @mattganis on Twitter
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

/* D1 Mini, with a Button connected to pin D3.
 * Connect the LBT (Little Buddy Talker)   
 * D1 Mini Pin      LBT PIN
 *     D7             DI
 *     D5             SC
 *     D0             CS
 *  
 *  Use a button connected to D3 (Button Shield).
 *  Set your time zone off set in seconds, below.
 *  Set if you want Military Time/24 Hour time  or want to hear AM/PM
 *  
 *  The sketch shows time in the serial console (You can verify the offset is correct this way.
 *  hold the button until it speaks, it will announce the hours and minutes.
 *  The sketch connects to a NTP (Time Server) to grab the time. The NTPClient library is required, see below.
 *  The WiFiManager library is also required, see below.
 *  Possiable Improvement - Display Time on the 0.66" OLED.
 */
 
#include <NTPClient.h>  //https://github.com/arduino-libraries/NTPClient
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>         //https://github.com/tzapu/WiFiManager

#include "Word100LBT.h";

#define BUTTON_PIN D3
#define arr_len( x ) ( sizeof ( x ) / sizeof (*x) )
#define HUNDRED  100
#define TEN     10

#define TIMEOFFSET -14400 //Find your Time Zone off set Here https://www.epochconverter.com/timezones OFF Set in Seconds
#define AMPM 1 //1 = AM PM time, 0 = MILITARY/24 HR Time

int LBTdigits[] = {_ZERO,_ONE,_TWO,_THREE,_FOUR,_FIVE,_SIX,_SEVEN,_EIGHT,_NINE};
int LBTdecades[] = {0x00,0x00,_TWENTY,_THIRTY,_FORTY,_FIFTY};
int LBTtens[] = {_TEN,_ELEVEN,_TWELVE,_THIRTEEN,_FOURTEEN,_FIFTEEN,_SIXTEEN,_SEVENTEEN,_EIGHTEEN,_NINETEEN};
int hundreds;
int tens;



int sentence[] = {_THE, _TIME, _IS };
WiFiUDP ntpUDP;
Word100lbt Word100(D0); //cs pin

NTPClient timeClient(ntpUDP, "pool.ntp.org");

void setup(){
  Serial.begin(9600);
  Word100.begin();
  
   WiFiManager wifiManager;
   wifiManager.autoConnect("TalkingClock");
  Serial.println("connected...yeey :)");
  
  timeClient.begin();
  timeClient.setTimeOffset(TIMEOFFSET);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  
  timeClient.update();
if (digitalRead(BUTTON_PIN) == LOW) {sayTime();}
  Serial.println(timeClient.getFormattedTime());
  delay(1000);
  yield();
  
}

void sayTime() {
  for (int i = 0; i < arr_len(sentence); i++) {
  Word100.say(sentence[i]);
  
  }
  sayHours(timeClient.getHours());
  delay(50);
  sayMinute(timeClient.getMinutes());

if (AMPM) {
  if (timeClient.getHours() < 12) {
    Word100.say(_AM_); } else {
    Word100.say(_PM_);   }
 }  
}

/* The code in sayMinute and sayHours is based on saynumber code
 *  example by Matt Ganis (matt.ganis@gmail.com) or @mattganis on Twitter
 *  Copyright (c) 2018 Matt Ganis
 */
 
int sayMinute(long number) {

if (number == 0) {
  
  Word100.say(_ZERO);   //special case for zero
  return 0;
}
int period;
period = number;
  tens = period / TEN;
   if (tens == 1) {
         Word100.say(LBTtens[period-10]);                   
         period = 0; }
                 
   if (tens > 1) {
       Word100.say(LBTdecades[tens]);  
       period = period - tens*TEN; } else {
       Word100.say(_ZERO);
       }
          
   if (period == 0)  { return 0; } else {
        Word100.say(LBTdigits[period]);  }
}

int sayHours(long number) {

if (number == 0) {
  
  Word100.say(_ZERO);   //special case for zero
  return 0;
}
int period;
period = number;

if (AMPM) {
  if (period >= 13) { period = period -12;}
}

  tens = period / TEN;
   if (tens == 1) {
         Word100.say(LBTtens[period-10]);                   
         period = 0; }
                 
   if (tens > 1) {
       Word100.say(LBTdecades[tens]);  
       period = period - tens*TEN; } 
          
   if (period == 0)  { return 0; } else {
        Word100.say(LBTdigits[period]);  }
}

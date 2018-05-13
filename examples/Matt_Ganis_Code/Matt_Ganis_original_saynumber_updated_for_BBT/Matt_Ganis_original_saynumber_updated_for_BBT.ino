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
 * May 11, 2018 - Updated Code to work with the Big Buddy Talker
 * based on code from Matt Ganis (matt.ganis@gmail.com)
 * Copyright (c) 2018, LeRoy Miller & Matt Ganis
 */


/* BBT Arduino UNO Hookup
 * BBT CS1 to Arduino PIN 7
 * BBT CS2 to Arduino PIN 8
 * BBT CS3 to Arduino PIN 9
 * BBT CS4 to Arduino PIN 10 
 * BBT SC to Arduino PIN 13 
 * BBT DI to Arduino PIN 11
 */
  
  
#include "Word100BBT.h"; 

//The Big Buddy Talker uses 4 CS select pins.
#define CS1_PIN 7
#define CS2_PIN 8
#define CS3_PIN 9
#define CS4_PIN 10

Word100bbt Word100(CS1_PIN, CS2_PIN, CS3_PIN, CS4_PIN); 

void setup() {
  
Serial.begin(9600);
Word100.begin();

}

void loop() {
long num;

  num = 124564473;
  Serial.print("Saying: ");
  Serial.println(num);
  Serial.println();
  saynumber(num);

   while (1) {}
  
}

#define MILLION  1000000
#define THOUSAND 1000
#define HUNDRED  100
#define TEN     10

void sayperiod(int period)
{

int LBTdigits[11][2] = {{_ZERO},{_ONE},{_TWO},{_THREE},{_FOUR},{_FIVE},{_SIX},{_SEVEN},{_EIGHT},{_NINE}};
int LBTdecades[11][2] = {{0x00,0},{0x00,0},{_TWENTY},{_THIRTY},{_FORTY},{_FIFTY},{_SIXTY},{_SEVENTY},{_EIGHTY},{_NINETY}};
int LBTtens[11][2] = {{_TEN},{_ELEVEN},{_TWELVE},{_THIRTEEN},{_FOURTEEN},{_FIFTEEN},{_SIXTEEN},{_SEVENTEEN},{_EIGHTEEN},{_NINETEEN}};

String tenplus[] = {"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
String decades[] = {"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
String digit[] = { "zero","one","two","three","four","five","six","seven","eight","nine"};

int hundreds;
int tens;

hundreds = period / HUNDRED;

if (hundreds != 0)
                    {
                      
                      Serial.print(digit[hundreds][0]);
                      Serial.print(" ");
                      Serial.print("hundred");
                      Serial.print(" ");
                      Word100.say(LBTdigits[hundreds][0],LBTdigits[hundreds][1]);
                      Word100.say(_HUNDRED);
                      period = period - (hundreds * HUNDRED); 
                    }
                    

tens = period / TEN;
                  
  if (tens == 1) {
                  
                      // the last part of the period is eleven thru nineteen 
                      //
                      Serial.print(tenplus[period-10]);
                      Serial.print(" ");
                      Word100.say(LBTtens[period-10][0],LBTtens[period-10][1]);                   
                      period = 0;                  
                 }
                 
  if (tens > 1)
        {
                      // the tens is a twenty, thirty, forty...etc
                      //
                      Serial.print(decades[tens]);
                      Serial.print(" ");
                      Word100.say(LBTdecades[tens][0],LBTdecades[tens][1]);  
                      period = period - tens*TEN;
        }
          
          if (period == 0)  {
                            return(0);
                           }
                           else {
                                  // finally say the one's digit (one, two, three, etc)
                                  //
                                  Serial.print(digit[period]);
                                  Serial.print(" ");
                                  Word100.say(LBTdigits[period][0],LBTdigits[period][1]);
                              
                           }
                   
                   
  }



//
//
//

void saynumber(long number) {
 
//Mar 19, 2018 - added line LeRoy Miller, stopped the extra zero from being said if thousand or million ended with zero.
  
if (number == 0) {
  
  Word100.say(_ZERO);   //special case for zero
  return(0);
}

int period;

period = number / MILLION;

if (period != 0) {
                  sayperiod(period);
                  Word100.say(_MILLION);
                  Serial.print("million");
                  Serial.print(" ");
                  number = number - period*MILLION;
  
                 }

period = number / THOUSAND;

if (period != 0) {
                 sayperiod(period);
                 Word100.say(_THOUSAND);
                 Serial.print("thousand");
                 Serial.print(" ");
                 number = number - period*THOUSAND;
  
}
  sayperiod(number);
}

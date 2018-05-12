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
 * Mar 19, 2018 - Added underscores to work with v2.1.0 of library
 * -LeRoy Miller
 * This will also work for the 100+ Word Shield using either chip
	Cleaned up code a little, corrected a issue that zero was being said if 
thousands or millions ended in zero.

 */

/* LBT Arduino UNO Hookup
 * LBT CS to Arduino PIN 10 
 * LBT SC to Arduino PIN 13 
 * LBT DI to Arduino PIN 11
 */
 
 /* Mar, 25 2018 - sayNumber(), sayHours(), sayMinutes() and
  *  setAMPM have been added to the libraries. 
  *  see New_Features.txt for more information.
  *  
  *  This sketch left for historical, and learning
  *  This is a good example of how the new functions work.
  *    */
  
//Uncomment for the device of your choice.
//#include "Word100LBT.h"; //If using a Little Buddy Talker
#include "Word100Ham.h"; //Works with the 100+ Word Shield and Ham chip
//#include "Word100.h"; //Works with the 100+ Word Shield standard chip

#define CS_PIN 10 //CS pin of your device.

//Word100lbt Word100(CS_PIN); //use Word100lbt for the Little Buddy talker
Word100ham Word100(CS_PIN); //use with 100+ Word Shield Ham chip
//Word100 Word100(CS_PIN); //use with 100+ Word Shield standard chip


void setup() {
  
Serial.begin(9600);
Word100.begin();

}

void loop() {
long num;

  num = 6144;
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

int LBTdigits[] = {_ZERO,_ONE,_TWO,_THREE,_FOUR,_FIVE,_SIX,_SEVEN,_EIGHT,_NINE};
int LBTdecades[] = {0x00,0x00,_TWENTY,_THIRTY,_FORTY,_FIFTY,_SIXTY,_SEVENTY,_EIGHTY,_NINETY};
int LBTtens[] = {_TEN,_ELEVEN,_TWELVE,_THIRTEEN,_FOURTEEN,_FIFTEEN,_SIXTEEN,_SEVENTEEN,_EIGHTEEN,_NINETEEN};

String tenplus[] = {"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
String decades[] = {"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
String digit[] = { "zero","one","two","three","four","five","six","seven","eight","nine"};

int hundreds;
int tens;

hundreds = period / HUNDRED;

if (hundreds != 0)
                    {
                      
                      Serial.print(digit[hundreds]);
                      Serial.print(" ");
                      Serial.print("hundred");
                      Serial.print(" ");
                      Word100.say(LBTdigits[hundreds]);
                      Word100.say(_hundred);
                      period = period - (hundreds * HUNDRED); 
                    }
                    

tens = period / TEN;
                  
  if (tens == 1) {
                  
                      // the last part of the period is eleven thru nineteen 
                      //
                      Serial.print(tenplus[period-10]);
                      Serial.print(" ");
                      Word100.say(LBTtens[period-10]);                   
                      period = 0;                  
                 }
                 
  if (tens > 1)
        {
                      // the tens is a twenty, thirty, forty...etc
                      //
                      Serial.print(decades[tens]);
                      Serial.print(" ");
                      Word100.say(LBTdecades[tens]);  
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
                                  Word100.say(LBTdigits[period]);
                              
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




 




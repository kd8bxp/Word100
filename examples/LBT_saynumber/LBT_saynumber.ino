/*
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

 
#include "Word100.h";

Word100lbt Word100(10); //use Word100lbt for the Little Buddy talker


void setup() {
  // put your setup code here, to run once:
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

int LBTdigits[] = {zero,one,two,three,four,five,six,seven,eight,nine};
int LBTdecades[] = {0x00,0x00,twenty,thirty,forty,fifty,sixty,seventy,eighty,ninety};
int LBTtens[] = {ten,eleven,twelve,thirteen,fourteen,fifteen,sixteen,seventeen,eighteen,nineteen};

String tenplus[] = {"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
String decades[] = {"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
String digit[] = { "zero","one","two","three","four","five","six","seven","eight","nine"};

int hundreds;
int tens;



if (period == 0) {
  
  Word100.say(LBTdigits[0]);   //special case for zero
  return(0);
}

hundreds = period / HUNDRED;

if (hundreds != 0)
                    {
                      
                      Serial.print(digit[hundreds]);
                      Serial.print(" ");
                      Serial.print("hundred");
                      Serial.print(" ");
                      Word100.say(LBTdigits[hundreds]);
                      Word100.say(hundred);
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
  
int period;


period = number / MILLION;

if (period != 0) {
                  sayperiod(period);
                  Word100.say(million);
                  Serial.print("million");
                  Serial.print(" ");
                  number = number - period*MILLION;
  
                 }

period = number / THOUSAND;

if (period != 0) {
                 sayperiod(period);
                 Word100.say(thousand);
                 Serial.print("thousand");
                 Serial.print(" ");
                 number = number - period*THOUSAND;
  
}
  sayperiod(number);
}




 




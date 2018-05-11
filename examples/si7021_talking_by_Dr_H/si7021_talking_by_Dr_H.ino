/*
A script for a talking thermometer and hygrometer. 

Build for the "Little Buddy Talker" device developed by Patrick Thomas Mitchell
http://www.engineeringshock.com/

Matt Ganis script was modified and adapted to the April 2018 version of the Word100 libray by Dr. H, 
and combined with the Si7021 from Adafruit.
More Information:
https://www.instructables.com/id/A-Talking-Sensor-Si7021-and-Little-Buddy-Talker/

Example by Matt Ganis (matt.ganis@gmail.com) or @mattganis on Twitter


Copyright (c) of the say.period and say.number functions 2018 Matt Ganis

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



#include "Adafruit_Si7021.h"

Adafruit_Si7021 sensor = Adafruit_Si7021();

#include "Word100LBT.h";
Word100lbt Word100(10); //use Word100lbt for the Little Buddy talker

void setup() {
  Serial.begin(9600);

  // wait for serial port to open
  while (!Serial) {
    delay(10);
  }

  Serial.println("Si7021 test!");
  
  if (!sensor.begin()) {
    Serial.println("Did not find Si7021 sensor!");
    while (true);
  }

  Word100.begin();
}

void loop() {

  int t_int;
  int h_int;
  int humid = sensor.readHumidity();
  float temp = sensor.readTemperature();
  h_int = int(humid); //conversion in to integer 
  t_int = int(temp);
  int t_abs = abs(t_int);

// prints and speaks temperature values
  
  Serial.print("Temperature: "); Serial.print(temp, 2); Serial.print(" °C"); 
  Serial.println();

  Word100.say(_TEMPERATURE); 
  
  if (t_int <0)
  {Word100.say(_MINUS);}
  else if (t_int >0)
  {Word100.say(_PLUS);};
  
  saynumber(t_abs); // says temperature value via LBT and sends text to serial
  
  Word100.say(_DEGREES); Word100.say(_CELSIUS);
  
  Serial.println();
  
  delay(1000);

// prints and speaks humididity values
  
  Serial.print("Humidity: "); Serial.print(humid); Serial.print(" % RH");
  Serial.println();
  
  Word100.say(_HUMIDITY); 
  
  saynumber(h_int); 
  
  Word100.say(_PER); Word100.say(_CENTI);
  
  Serial.println();
  Serial.println();
  
  delay(28000); //wait 28 seconds before next measurement

 //LBT: humidity: 0x72,per: 0x81, centi: 0x66; temperature: 0x8a, plus: 0x9xc, minus: 0x99, degrees: 0x68, celsius = 0x64, 

// the following piece of code is taken from Matt Ganis code, being adapted to the April 2018 version of the word100 library

 // while (1) {}
}  

#define MILLION  1000000
#define THOUSAND 1000
#define HUNDRED  100
#define TEN     10

void sayperiod(int period)
{

int LBTdigits[] = {_ZERO, _ONE, _TWO, _THREE, _FOUR, _FIVE, _SIX ,_SEVEN, _EIGHT, _NINE};
int LBTdecades[] = {0x00, 0x00, _TWENTY, _THIRTY, _FORTY, _FIFTY, _SIXTY, _SEVENTY, _EIGHTY, _NINETY};
int LBTtens[] = {_TEN, _ELEVEN, _TWELVE, _THIRTEEN, _FOURTEEN, _FIFTEEN, _SIXTEEN, _SEVENTEEN, _EIGHTEEN, _NINETEEN};

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
                      Word100.say(_HUNDRED);
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



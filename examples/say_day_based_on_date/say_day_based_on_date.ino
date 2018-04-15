/*
 * Say the name of the day based on the date give, added
 * bonus, example of saying the name of the months just using
 * the numerical value of the month: IE: 1 = Jan, 2 = Feb, ect
 * 
 * Lots of math, see notes in sketch for how this works.
  
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

//Uncomment for the device of your choice.
//#include "Word100LBT.h"; //If using a Little Buddy Talker
//#include "Word100Ham.h"; //Works with the 100+ Word Shield and Ham chip
#include "Word100.h"; //Works with the 100+ Word Shield standard chip

#define CS_PIN 10 //CS pin of your device.

//Word100lbt Word100(CS_PIN); //use Word100lbt for the Little Buddy talker
//Word100ham Word100(CS_PIN); //use with 100+ Word Shield Ham chip
Word100 Word100(CS_PIN); //use with 100+ Word Shield standard chip

int days[] = {_SAT, _SUN, _MON, _TUE, _WED, _THR, _FRI};
int months[] = {_JAN, _FEB, _MAR, _APR, _MAY, _JUNE, _JULY, _AUG, _SEP, _OCT, _NOV, _DEC};

int day = 25; //25th day of month
int month = 3; //March
int year = 18; //last two digits of year
int baseYear = 2000; //The formula can calculate other centurys with some minor changes
int monthKey[] = {1, 4, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6};

/* Key method for determining the name of the day based on date
 *  http://mathforum.org/dr.math/faq/faq.calendar.html
 *  last 2 digits of year divide by 4 (18/4) drop remainder
 *  add day of month (18/4)+25
 *  add keyMonth (18/4)+25+4 (Mar is key a month of 4 from list above)
 *  (if your date is in January or February of a leap year, subtract 1)
 *  add century code (We only using the 2000s so 6) 
 *  (18/4)+25+4+6
 *  add the last two digits of the year (18/4)+25+4+6+18
 *  divide by 7 ((18/4)+25+4+6+18)/7
 *  find remainder
 *  8.214285714 - (wholenumber 8) = .214285714 * 7
 *  With this method Sat is the Zero and Friday is day 6
 */

double temp1;
bool leapYear;
int answer;

void setup() {
  Serial.begin(9600);
  //Serial.println(monthKey[month-1]);
  Word100.begin();
  sayDay(month, day, year);
  sayMonth(month); //Number of the Month (1 = Jan, 12 = Dec, ect)
  //Word100.say(months[month-1]); //Will also work for now
  Word100.sayNumber(day); //this is just a number
  Word100.say(_TWENTY); //probably will add a sayYear function later
  Word100.sayNumber(year); //two digit number for the year.
}

void loop() {
 
}

void sayDay(int month, int day, int year) {
 temp1 = (year/4);
 temp1 = (int)temp1 + day + monthKey[month-1] + 6 + year;

//Check leap year
checkLeapYear(year);
  if ((leapYear) && (month == 1) || (month == 2)) {
    temp1 = temp1 - 1;
  }
 
temp1 = temp1 / 7;
int integer = (int)(temp1);
float decimal = (temp1 - integer);
Serial.println(decimal);
answer = round(decimal * 7);
Serial.println(answer);
Word100.say(days[answer]);
  
}

void checkLeapYear(int y) {
  y = baseYear + y;
  //https://www.wikihow.com/Calculate-Leap-Years
    leapYear = false;
    double LYtemp1 = (float)y/(float)4;
    double LYtemp2 = (float)y/(float)100;
    double LYtemp3 = (float)y/(float)400;
    
    //if (LYtemp1 != (int)LYtemp1) {return(0);}
    if ((LYtemp1 == (int)LYtemp1) && (LYtemp2 != (int)LYtemp2)) {leapYear = true; return(0); }
    if ((LYtemp1 == (int)LYtemp1) && (LYtemp2 == (int)LYtemp2) && (LYtemp3 == (int)LYtemp3)) {leapYear = true; return(0);}
     
  }

void sayMonth(int m) {
  //No error checking yet, need to add.
  Word100.say(months[m-1]);
}


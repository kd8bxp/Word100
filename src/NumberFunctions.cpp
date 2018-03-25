#include "Arduino.h"
#include "NumberFunctions.h"

#ifdef WORD100 
	#include "Word100.h"
#endif

NumberFunctions::NumberFunctions() {
_sayDigits[] = {_zero,_one,_two,_three,_four,_five,_six,_seven,_eight,_nine};
_sayDecades[] = {0x00,0x00,_twenty,_thirty,_forty,_fifty,_sixty,_seventy,_eighty,_ninety};
_sayTens[] = {_ten,_eleven,_twelve,_thirteen,_fourteen,_fifteen,_sixteen,_seventeen,_eighteen,_nineteen};

}

void NumberFunctions::sayMinutes(long number) {
if (number == 0) {
  
  #ifdef WORD100
  Word100::Word100.say(_zero);   //special case for zero
 #endif
  return 0;
}

_period = number;
  _tens = _period / TEN;
   if (_tens == 1) {
        #ifdef WORD100
		 Word100::Word100.say(_sayTens[_period-10]);
		#endif                   
         _period = 0; }
                 
   if (_tens > 1) {
      #ifdef WORD100
		 Word100::Word100.say(_sayDecades[_tens]);
	  #endif  
       _period = _period - _tens*TEN; } else {
       #ifdef WORD100
	      Word100::Word100.say(_zero);
		#endif
       }
          
   if (_period == 0)  { return 0; } else {
        #ifdef WORD100
		   Word100::Word100.say(_sayDigits[_period]);
		#endif  }
}

void NumberFunctions::sayHours(long number) {
if (number == 0) {
  
  #ifdef WORD100
	 Word100::Word100.say(_zero);   //special case for zero
	#endif
  return 0;
}

_period = number;

if (AMPM) {
  if (_period >= 13) { _period = _period -12;}
}

  _tens = _period / TEN;
   if (_tens == 1) {
		#ifdef WORD100         
			Word100::Word100.say(_sayTens[_period-10]);
		#endif                   
         _period = 0; }
                 
   if (_tens > 1) {
       	#ifdef WORD100
			Word100::Word100.say(_sayDecades[_tens]);
		#endif  
       _period = _period - _tens*TEN; } 
          
   if (_period == 0)  { return 0; } else {
		#ifdef WORD100
        Word100::Word100.say(_sayDigits[period]);
		#endif
	  }
}

void NumberFunctions::sayPeriod(int _period) {

_hundreds = _ period / HUNDRED;

if (_hundreds != 0) {
	#ifdef WORD100	
	Word100::Word100.say(_sayDigits[_hundreds]);
	Word100::Word100.say(_hundred);
	#endif
	_period = _period - (_hundreds * HUNDRED);
	}

_tens = _period / TEN;

if (_tens == 1) {
	#ifdef WORD100
	Word100::Word100.say(_sayTens[_period-10]);
	#endif
	_period=0;
	}

if (_tens > 1) {
	#ifdef WORD100
	Word100::Word100.say(_sayDecades[_tens]);
	#endif
	_period = _period - _tens * TEN;
	}

if (_period == 0) { return(0); } else {
	#ifdef WORD100
	Word100::Word100.say(_sayDigits[_period]);
	#endif
	}

void NumberFunctions::sayNumber(long number) {

if (number == 0) {
	#ifdef WORD100
	Word100::Word100.say(_zero);
	#endif
	return(0);
	}
_period = number / MILLION;
if (_period != 0) {
	#ifdef WORD100
	Word100::Word100.say(_million);
	#endif
	number=number - _period * MILLION;
	}

_period = number / THOUSAND;
if (_period != 0) {
	#ifdef WORD100
	Word100::Word100.say(_thousand);
	#endif
	number = number - _period * THOUSAND;
}
NumberFunctions::sayPeriod(number);
}

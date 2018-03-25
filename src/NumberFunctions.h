//#ifndef NumberFunctions_h
//#define NumberFunctions_h

#include "Arduino.h"

#ifdef WORD100 
	#include "Word100.h"


#define MILLION  1000000
#define THOUSAND 1000
#define HUNDRED  100
#define TEN     10


class NumberFunctions {
private:
	void sayPeriod(int _period);
	int _sayDigits[];
	int _sayDecades[];
	int _sayTens[];
	int _hundreds;
	int _tens;
	int _number;
public:
	virtual NumberFunctions();
	virtual void sayNumber(long number);
	virtual void sayHours(long number);
	virtual void sayMinutes(long number);
void sayNumber(long number);
void sayHours(long number);
void sayMinutes(long number);
};

#endif

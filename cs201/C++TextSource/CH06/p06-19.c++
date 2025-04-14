//	P06-19 Powers function

/*	This program tests powers.
	   Written by:
	   Date      :
*/
#include <iostream>
using namespace std;

long powers (int base, int exp);

int main (void) 
{
/*	Statements */
	cout << "\n2**4: " << powers (2, 4) << endl;
	return 0;
}	// main

/* =================== powers ====================
	Raise base, to an integral power, exp. If the  
	exponent is zero, return 1.
	   Pre   base and exp are both positive integers
	   Post  return either 
	       (a) base to the exp power
	   or  (b) zero if the parameters are invalid
*/
long powers (int base, int exp)
{
	int  i;
	long result;

	if (base < 1 || exp < 0 )
	    // Error Condition
	    result = 0;
	else
	    if (exp > 0)
	        for (result = 1, i = 1; i <= exp; i++)
	             result *= base;
	    else
	        result = 1;
	return result;
}	// powers 

/*	Results:

2**4: 16

*/

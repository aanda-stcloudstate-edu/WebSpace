//	P06-24 Recursive factorial

/*	This program tests recursive factorial.
	   Written by:
	   Date      :
*/
#include <iostream.h>

/*	Prototype Statements */
	long factorial (long n);

int main (void) 
{
//	Statements
	cout << "factorial 6 is: " << factorial (6);
	return 0;
}	// main

/*	=================== factorial ====================
	Calculates factorial of a number using recursion. 
	There is no test that the result fits in sizeof long
	   Pre   num is the number being raised factorially
	   Post  result is returned
*/
long factorial (long num)
{
	if (num == 0)
		return 1;
	else
		return (num * factorial (num - 1));
}	// factorial

/*	Results:

factorial 6 is: 720

*/

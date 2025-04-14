/*	This program is a test driver for factorial.
	   Written by:
	   Date      :
*/
#include <iostream>
using namespace std;

/*	Prototype Statements */
	long factorial (int num);

int main (void) 
{
//	Statements

	cout << "factorial 6 is: " << factorial (6);

	return 0;
}	// main

/*	=================== factorial ====================
	Calculates the factorial of a number using a loop. 
	There is no test that the result fits in sizeof long
	   Pre   num is the number to be raised factorially
	   Post  result is returned
*/
long factorial (int num)
{
	long  factN = 1;
	for (int i = 1; i <= num; i++)
	     factN = factN * i;
	return factN;
}	// factorial

/*	Results:

factorial 6 is: 720

*/

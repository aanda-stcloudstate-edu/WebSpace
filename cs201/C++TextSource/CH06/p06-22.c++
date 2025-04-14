/*	This program is a test driver for allPositiveEOF.
	   Written by:
	   Date:
*/
#include <iostream>
using namespace std;

#ifndef TRUE
	#define TRUE  1
	#define FALSE 0
#endif

/*	Prototype Statements */
	bool allPositiveEOF (void);

int main (void) 
{
//	Statements
	cout << "Enter numbers <EOF> to stop:\n";
	cout << "allPositiveEOF is: " << allPositiveEOF () << endl;
	return 0;
}	// main

/*	================= allPositiveEOF ==================
	Read number series & determine if all are positive.
	   Pre   Nothing
	   Post  Returns true  if all numbers >  0
	         Returns false if any number  <= 1
*/
bool allPositiveEOF (void)
{
	bool allPositive = true;
	int  numIn;
	while ( allPositive && (cin >> numIn) )
	    allPositive = (numIn > 0);
	return allPositive;
}	// allPositiveEOF

/*
Results:
	Enter numbers <EOF to stop>:
	1
	2
	3
	^dallPositiveEOF is: 1

	Enter numbers <EOF to stop>:
	1
	2
	-3
	allPositiveEOF is: 0
*/

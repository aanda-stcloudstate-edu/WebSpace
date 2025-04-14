/*	This program is a test driver for anyPositiveEOF.
	   Written by:
	   Date:
*/
#include <iostream>
using namespace std;

#ifndef TRUE
	#define  TRUE  1
	#define  FALSE 0
#endif

//	Prototype Statements
	bool anyPositiveEOF (void);

int main (void) 
{
//	Statements
	cout << "Enter numbers <EOF> to stop:\n";
	cout << "anyPositiveEOF is: " << anyPositiveEOF () << endl;
	return 0;
}	// main

/*	================= anyPositiveEOF ==================
	Read number series & determine if any are positive.
	   Pre   Nothing
	   Post  Returns true  if any numbers >  0
	         Returns false if all numbers <= 0
*/
bool anyPositiveEOF (void)
{
	bool anyPositive = false;
	int  numIn;
	while ( !anyPositive && (cin >> numIn) )
	    anyPositive = (numIn > 0);
	return anyPositive;
} // anyPositiveEOF

/* Results:
Enter numbers <EOF> to stop:
-1
-2
3
anyPositiveEOF is: 1

Enter numbers <EOF> to stop:
-1
-2
-3
^danyPositiveEOF is: 0
*/

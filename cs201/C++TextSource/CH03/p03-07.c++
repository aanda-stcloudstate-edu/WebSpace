/*	Demonstrate implicit casts of numeric types.
	   Written by:
	   Date:
*/
#include <iostream>
using namespace std;

int main ()
{
	char   aChar   = 'A';
	int    printChar;
	int    intNum  = 200;
	double fltNum  = 245.3;
	
	cout << "aChar contains :  " << aChar  << endl;
	printChar = aChar;
	cout << "aChar numeric  :  " << printChar  << endl;
	cout << "intNum contains:  " << intNum << endl;
	cout << "fltNum contains:  " << fltNum << endl;
	
	intNum = intNum + aChar;   // aChar converted to int
	fltNum = fltNum + aChar;   // aChar converted to float

	cout << "\nAfter additions...\n";
	printChar = aChar;
	cout << "aChar numeric  :  " << printChar  << endl;
	cout << "intNum contains:  " << intNum     << endl;
	cout << "fltNum contains:  " << fltNum     << endl;
	return 0;
}	// main 

/*	Results:

aChar contains :  A
aChar numeric  :  65
intNum contains:  200
fltNum contains:  245.3

After additions...
aChar numeric  :  65
intNum contains:  265
fltNum contains:  310.3

*/

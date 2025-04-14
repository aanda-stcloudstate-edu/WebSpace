/*	Demonstrate while and do É while loops.
	   Written by:
	   Date:
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
	int loopCount = 1;
	int testCount = 0;

	cout << "while loop:       ";
	while (testCount++, loopCount <= 10) 
	    cout << setw(3) << loopCount++;
	cout << "\nLoop Count:      " << loopCount << endl;
	cout << "Number of tests: "   << testCount << endl;

	loopCount = 1;
	testCount = 0;
	cout << "\ndo...while loop:  ";
	do
	    cout << setw(3) << loopCount++;
	while (testCount++, loopCount <= 10);
	cout  << "\nLoop Count:      " << loopCount << endl;
	cout  << "Number of tests: "   << testCount << endl;

	return 0;
}	// main 

/* Results:
while loop:         1  2  3  4  5  6  7  8  9 10
Loop Count:      11
Number of tests: 11

do...while loop:    1  2  3  4  5  6  7  8  9 10
Loop Count:      11
Number of tests: 10
*/

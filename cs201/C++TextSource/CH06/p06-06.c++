/*	Demonstrate while and do...while loops.
	   Written by:
	   Date:
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
	int loopCount;

	loopCount = 5;
	cout << "while loop     : ";
	while (loopCount > 0)
	   cout << setw(3) << loopCount--;
	cout << "\n\n";

	loopCount = 5;
	cout << "do...while loop: ";
	do
	   cout << setw(3) << loopCount--;
	while (loopCount > 0);
	cout << endl;
	return 0;
}	// main 

/* Results
while loop     :   5  4  3  2  1

do...while loop:   5  4  3  2  1
*/

/*	Print number series from 1 to user limit.
	   Written by:
	   Date:
*/
#include <iostream>
using namespace std;

int main ()
{
	int limit;

	cout << "\nPlease enter a limit: ";
	cin  >> limit;
	for (int i = 1; i <= limit; i++)
	    cout << "\t" << i << endl;
	return 0;
}	// main 

/* Results:
Please enter the limit: 3
    1
    2
    3
*/

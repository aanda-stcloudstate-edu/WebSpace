/*	Demonstrate using a namespace directive.
	   Written by:
	   Date:
*/
#include <iostream>
using namespace std;

int main ()
{
	cout << "Enter an integer: ";
	int numIn;
	cin  >> numIn;
	cout << "You entered:      " << numIn << "\n";
	return 0 ;
}	// main

/*	Result:
Enter an integer: 5
You entered:      5
*/

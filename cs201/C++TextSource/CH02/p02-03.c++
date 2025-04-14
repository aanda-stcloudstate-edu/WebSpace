/*	This program demonstrates three ways to use constants.
	   Written by: 
	   Date: 
*/
#include <iostream>
using namespace std;

#define PI 3.1415926536

int main ()
{
	const double pi = 3.1415926536;

	cout << "Defined constant PI: " << PI << '\n';
	cout << "Memory constant pi:  " << pi << '\n';
	cout << "Literal constant:    " << 3.1415926536 << '\n';
	return 0;
}	// main 

/*	Results:

	Defined constant PI: 3.14159
	Memory constant pi:  3.14159
	Literal constant:    3.14159

*/
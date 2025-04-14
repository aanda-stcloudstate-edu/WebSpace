/*	This program prompts the user to enter an angle measured
	in radians and converts it into degrees.
	   Written by: 
	   Date: 
*/
#include <iostream>
using namespace std;

const int cDegreeFactor = 57.295779; 

int main ()
{
	cout << "Enter the angle in radians: ";
	double  radians;
	cin  >> radians;

	double degrees = radians * cDegreeFactor;
	
	cout << radians << " radians is " 
	     << degrees << " degrees\n";
	return 0;
}	// main 

/*	Results:
Enter the angle in radians: 1.578947
1.57895 radians is 90 degrees
*/

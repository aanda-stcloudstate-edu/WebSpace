/*	Evaluate two complex expressions.
	   Written by:
	   Date:
*/
#include <iostream>
using namespace std;

int main ()
{
	int a = 3;
	int b = 4;
	int c = 5;
	int x;
	int y;

	cout << "Initial values of the variables: \n";
	cout << "a = " << a << "   b = " << b << "   c = " 
	     << c << endl;
	cout << endl;

	x = a * 4 + b / 2 - c * b;
	cout << "Value of a * 4 + b / 2 - c * b is: " 
	     << x << endl;

	y = --a * (3 + b) / 2 - c++ * b;
	cout << "Value of --a * (3 + b) / 2 - c++ * b is: " 
	     << y << endl; 

	cout << "\nValues of the variables are now: \n";
	cout << "a = " << a << "   b = " << b << "   c = " 
	     << c << endl;

	return 0;
}	// main 

/*	Results:

Initial values of the variables:
a = 3   b = 4   c = 5

Value of a * 4 + b / 2 - c * b is: -6
Value of --a * (3 + b) / 2 - c++ * b is: -13

Values of the variables are now:
a = 2   b = 4   c = 6

*/

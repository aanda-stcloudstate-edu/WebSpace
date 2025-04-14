/*	Demonstrate use of parameter default.
	   Written by:
	   Date:
*/
#include <iostream>
using namespace std;

//	Prototype Declarations
	void printInt (int num = 0);     //Note default to 0

int main ()
{
	// Demonstrate default parameter
	cout << "Calling with no parameter\n";
	printInt ();

	// Demonstrate parameter value passed
	cout << "\nCalling with parameter 5\n";
	printInt (5);
	return 0;
}	// main
/*	=============== printInt ==============
	Prints integer value.
	   Pre  Nothing
	   Post Either 0 or parameter value printed
*/
void printInt (int num)
{
	cout << "Parameter value is: " << num << endl;
	return;
}	// printInt

/*	Results

Calling with no parameter
Parameter value is: 0

Calling with parameter 5
Parameter value is: 5

*/

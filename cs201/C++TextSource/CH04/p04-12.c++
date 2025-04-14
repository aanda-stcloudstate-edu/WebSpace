/*	This program adds and subtracts two integers read 
	from the keyboard.
	   Written by: 
	   Date:
*/
#include <iostream>
#include <iomanip>
using namespace std;

//	Prototype Declarations
	int add  (int a, int b);
	int subt (int a, int b);

int main ()
{
	// Prompt user for input and get data
	cout << "\nPlease enter two integer numbers: ";

	// Read numbers into a and b
	int a;
	int b;
	cin  >> a >> b;

	// Calculate the sum and difference
	int sum  = add  (a, b);
	int diff = subt (a, b);
	
	cout << setw(4) << a << 
	     " + "  << setw(4) << b << 
	     " = "  << setw(4) << sum << endl;


	cout << setw(4) << a 
	     << " - "  << setw(4) << b  
	     << " = "  << setw(4) << diff << endl;

	// Close program
	cout << "\nThank you for using my calculator\n";
	return 0;
}	// main
/*	===================== add =====================
	This function adds two integers and returns the sum.
	   Pre   Parameters a and b
	   Post  Returns a + b
*/
int add (int a, int b)
{
	return (a + b);
}	// add
/*	=================== subt ====================
	Return the difference of two integers
	   Pre   Parameters a and b
	   Post  Returns a - b
*/
int subt (int a, int b)
{
	return (a - b);
}	// subt

/*	Results:

Please enter two integer numbers: 5 10
   5 +   10 =   15
   5 -   10 =   -5

Thank you for using my calculator

*/

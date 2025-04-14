/*	This program demonstrates the use of the numeric 
	manipulator.
	   Written by:
	   Date:
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
	int    d123   = 123;

	cout << "Values in decimal: \t";
	cout << setw(5) << d123 << setw(5) << d123 << endl;

	cout << "Values in hexadecimal: \t";
	cout << hex;
	cout << setw(5) << d123 << setw(5) << d123 << endl;
	
	cout << "Values in octal: \t";
	cout << oct;
	cout << setw(5) << d123 << setw(5) << d123 << endl;
	
	cout << "Values in decimal: \t";
	cout << dec;
	cout << setw(5) << d123 << setw(5) << d123 << endl;
		
	return 0;
}  // main 

/*	Results:
Values in decimal:        123  123
Values in hexadecimal:     7b   7b
Values in octal:          173  173
Values in decimal:        123  123

*/

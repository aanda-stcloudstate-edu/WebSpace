/*	Demonstrates the generation of random numbers in 
	three different ranges:
	   03 through 07
	   20 through 50
	   -6 through 15
	After generating three numbers, it prints them.
	The seed for the series is 997, which is set by srand. 
	   Written by:
	   Date:
*/
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main ()
{
	srand (997);
	// range is 3 through 7
	int a = rand () % 5 + 3;               // 8 - 3 = 5 
	// range is 20 through 50
	int b = rand () % 31 + 20;          // 51 - 20 = 31 
	// range is -6 through 15
	int c = rand () % 22 - 6;         // 16 - (-6) = 22 

	cout << "Range  3 to  7: ";
	cout << setw(3) << a << endl;
	cout << "Range 20 to 50: ";
	cout << setw(3) << b << endl;
	cout << "Range -6 to 15: ";
	cout << setw(3) << c << endl;
	
	return 0;
}	// main 

/*	Results:

Range  3 to  7:   5
Range 20 to 50:  27
Range -6 to 15:  -2

*/

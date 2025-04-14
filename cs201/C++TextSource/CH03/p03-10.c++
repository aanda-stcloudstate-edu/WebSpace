/*	Print rightmost digit of an integer.
	   Written by:
	   Date:
*/
#include <iostream>
using namespace std;

int main ()
{
	int intNum;
	cout << "Enter an integral numbers: ";
	cin  >> intNum;
	
	int oneDigit = intNum % 10;
	cout << "\nThe right digit is: " << oneDigit << endl;
	return 0;
}	// main 

/*	Results:

Enter an integral numbers: 185

The right digit is: 5

*/

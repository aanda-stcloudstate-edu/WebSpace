/*	Calculate and print quotient and remainder of two numbers.
	   Written by:
	   Date:
*/
#include <iostream>
using namespace std;

int main ()
{
	int  intNum1;
	int  intNum2;
	int  intCalc;
	
	cout << "Enter two integral numbers: ";
	cin  >> intNum1 >> intNum2;
	
	intCalc = intNum1 / intNum2;
	cout << intNum1 << " / " << intNum2 << " is " << intCalc;

	intCalc = intNum1 % intNum2;
	cout << " with a remainder of: " << intCalc << endl;
	return 0;
}	// main 

/*	Results:

Enter two integral numbers: 13 2
13 / 2 is 6 with a remainder of: 1

*/

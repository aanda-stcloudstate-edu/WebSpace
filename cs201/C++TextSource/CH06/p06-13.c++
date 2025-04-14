/*	Print the number and sum of digits in an integer.
	   Written by:
	   Date:
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
	cout << "Enter an integer: ";
	int number;
	cin  >> number;
	cout << "Your number is:   " << number << endl;

	int count = 0;
	int sum   = 0;
	while (number != 0)
	  {
	     count++;
	     sum +=  number % 10;
	     number /= 10;
	  }  // while 

	cout << "\nThe number of digits is : " 
	     << setw(3) << count << endl;
	cout << "The sum of the digits is: " 
	     << setw(3) << sum   << endl;

	return 0;
}	// main 

/* Results:
Enter an integer: 12345
Your number is:   12345

The number of digits is:    5
The sum of the digits is:  15
*/

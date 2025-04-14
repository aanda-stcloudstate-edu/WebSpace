/*	Use a loop to print a number backward.
	   Written by: 
	   Date: 
*/
#include <iostream>
using namespace std;

int main ()
{
	long num;
	
	cout << "Enter a number and I'll print it backward: ";
	cin  >> num;
	
	while (num > 0)
	   {
	    int  digit;

	    digit = num % 10;
	    cout << digit;
	    num   = num / 10;
	   } // while 
	cout << "\nHave a good day.\n";
	return 0;
}	// main 

/* Results:

Enter a number and I'll print it backward: 12345678
87654321
Have a good day.

*/

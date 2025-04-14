/*	This program prints the first digits of an integer 
	read from the keyboard.
	   Written by: 
	   Date:
*/
#include <iostream>
using namespace std;

//	 Prototype Declarations
	int firstDigit (int num);

int main ()
{
	cout << "Enter an integer: ";
	int  number;
	cin  >> number;

	int digit = firstDigit (number);
	cout << "Least significant digit is: " << digit << endl;
	return 0;
}	// main 

/* ================== firstDigit =================== 
	This function extracts the least significant digit 
	of an integer.
	   Pre  num contains an integer
	   Post Returns least significant digit
*/
int firstDigit (int num)
{
	return (num % 10);
}	// firstDigit

/*	Results:
Enter an integer: 27
Least significant digit is: 7
*/

/*	This program extracts and adds the two least 
	significant digits of an integer.
	   Written by:
	   Date:
*/
#include <iostream>
using namespace std;

//	Prototype Declarations 
	int addTwoDigits (int num);
	int firstDigit   (int);
	int secondDigit  (int);

int main ()
{
	cout << "Enter an integer: ";
	int  number;
	cin  >> number;

	int sum  =  addTwoDigits (number);
	cout << "\nSum of last two digits is: " << sum;
	return 0;
}	// main
/* =================== addTwoDigits ================== 
	Adds the first two digits of an integer.
	   Pre  num contains an integer
	   Post Returns sum of two least significant digits
*/
int addTwoDigits (int number)
{
	int result = firstDigit(number) + secondDigit(number);
	return result;
}	// addTwoDigits

/* ================== firstDigit =================
	Extracts the least significant digit of an integer.
	    Pre  num contains an integer
	    Post Returns least significant digit
*/
int firstDigit (int num)
{
	return (num % 10);
}	// firstDigit

//   ================= secondDigit =================
/*	Extracts second least significant (10s) digit.
	   Pre  num is an integer
	   Post Returns digit in 10s position
*/
int secondDigit (int num)
{
	int result = (num / 10) % 10;
	return result;
}	// secondDigit

/*	Results:
Run 1
   Enter an integer: 23

   Sum of last two digits is: 5
Run 2
   Enter an integer: 8

   Sum of last two digits is: 8
*/

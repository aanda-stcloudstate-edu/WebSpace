/*	This program reads long integers from the keyboard 
	and prints them with leading zeros in the form 
	123,456 with a comma between the 3rd & 4th digit.
	   Written by:
	   Date:
*/
#include <iostream>
#include <iomanip>
using namespace std;

//	Prototype Declarations
void printWithComma (long num);

int main ()
{
	cout << "Enter a number with up to 6 digits: ";
	long number;
	cin  >> number;
	printWithComma (number);
	return 0;
}	// main
/* ================= printWithComma ==================
	This function divides num into two three-digit 
	numbers and prints them with a comma inserted.
	   Pre  num is a six-digit number
	   Post num has been printed with a comma inserted
*/
void printWithComma (long num)
{
	float thousands = num / 1000;
	float hundreds  = num % 1000;

	cout << "\nThe number you entered is \t";
	cout << setw(3) << thousands << ",";
	cout << setfill('0');
	cout << setw(3) << hundreds;
	return;
}	// printWithComma

/*	Results:

Run 1
   Enter a number with up to 6 digits: 123456

   The number you entered is   123,456
Run 2
   Enter a number with up to 6 digits: 1012

   The number you entered is     1,012
*/

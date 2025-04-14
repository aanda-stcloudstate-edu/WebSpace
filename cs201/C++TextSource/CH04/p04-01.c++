/*	This program demonstrates function calls by calling a 
	small function to multiply two numbers.
	   Written by:
	   Date:
*/
#include <iostream>
using namespace std;

//	Prototype Declarations
	int multiply (int num1, int num2);

int main ()
{
	int multiplier;
	int multiplicand;
	cout << "Enter two integers: ";
	cin  >> multiplier >> multiplicand;

	int product = multiply (multiplier, multiplicand);

	cout << "Product of " << multiplier
	     << " & "         << multiplicand
	     << " is "        << product;
	return 0;
}	// main
/* ===================== multiply ===================== 
	Multiply two numbers and return product.
	   Pre  num1 & num2 contain values to be multiplied
	   Post product returned
*/
int multiply (int num1, int num2)
{
	return (num1 * num2);
}	// multiply

/*	Results:
Enter two integers: 17 21
Product of 17 & 21 is 357
*/

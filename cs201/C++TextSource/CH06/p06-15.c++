/*	Convert a binary number to a decimal number.
	   Written by:
	   Date:
*/
#include <iostream>
using namespace std;

	long getNum          (void);
	long binaryToDecimal (long binary);
	bool validateBinary  (long binary);
	long powerTwo        (long num);
	long firstDigit      (long num);

int main ()
{
	long binary  =  getNum ();
	long decimal =  binaryToDecimal (binary);
	cout    << "\nThe binary number was: " << binary;
	cout    << "\nThe decimal number is: " << decimal;
	return 0;
}	// main 

/*	==================== getNum =====================
	This function reads and validates a binary number 
	from the keyboard.
	   Pre   Nothing
	   Post  A valid binary number is returned
*/
long getNum (void) 
{
	long  binary;
	bool  isValid;

	do
	   {
	    cout    << "Enter binary number (0's & 1's): ";
	    cin     >> binary;
	    isValid =  validateBinary (binary);
	    if (!isValid)
	       cout << "\a\aNot binary. 0's/1's only.\n\n";
	 } while (!isValid);

	return binary;
}	// getNum
/*	================ binaryToDecimal =================
	Change a binary number to a decimal number.
	   Pre   binary contains number with only 0's & 1's
	   Post  Returns the decimal number
*/
long binaryToDecimal (long binary)
{
	long decimal = 0;
	for (int i = 0; binary != 0; i++)
	    {
	     decimal += firstDigit (binary) * powerTwo (i);
	     binary  /= 10;
	    }
	return decimal;
}	// binaryToDecimal
/*	================= validateBinary =================
	Check the digits in a binary number for only 0 and 1.
	   Pre   binary is a number to be validated
	   Post  Returns 1 if valid; 0 otherwise
*/
bool validateBinary (long binary)
{
	while (binary != 0)
	    {
	     if (!(binary % 10 == 0 || binary % 10 == 1))
	         return false;
	     binary /= 10;
	    }  // while
	return true;
}	// validateBinary
/*	==================== powerTwo ====================
	This function raises 2 to the power num 
	   Pre   num is exponent
	   Post  Returns 2 to the power of num
*/
long powerTwo (long num)
{
	long power = 1;
	for (int i = 1; i <= num; i++) 
	    power *= 2;
	return power;
}	// powerTwo
/*	=================== firstDigit ===================
	This function returns the rightmost digit of num 
	   Pre   the integer num
	   Post  The right digit of num
*/
long firstDigit (long num) 
{
	return (num % 10);
}	// first Digit
//	================== End of Program =================

/*	Results
Run 1:
	Enter binary number (0Õs & 1Õs): 11111111

	The binary number was: 11111111
	The decimal number is: 255

Run 2:
	Enter binary number (0Õs & 1Õs): 1010101010

	The binary number was: 1010101010
	The decimal number is: 682
*/

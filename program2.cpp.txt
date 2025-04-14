// program to convert from decimal to other power of two bases
// A. Anda
// Fall '02
// cs102
// program 2

#include <iostream.h>
#include <iomanip.h>

int main (void)
{
//  Local declarations

    int b1, b2, b3, b4, b5, b6, b7, b8; // low to high order bits
    int dec_val, dec_temp; // initial and intermediate decimal values

// Statements

    cout << "\nEnter an integer between 0 and 255 (inclusive) "
         << endl << endl;

    cin >> dec_val;

    dec_temp = dec_val;               // initialize the running quotient

    b1 = dec_temp % 2; dec_temp /= 2; // compute value of each binary digit
    b2 = dec_temp % 2; dec_temp /= 2;
    b3 = dec_temp % 2; dec_temp /= 2;
    b4 = dec_temp % 2; dec_temp /= 2;
    b5 = dec_temp % 2; dec_temp /= 2;
    b6 = dec_temp % 2; dec_temp /= 2;
    b7 = dec_temp % 2; dec_temp /= 2;
    b8 = dec_temp % 2; dec_temp /= 2;

    cout << "\nThe decimal integer " << dec_val
	 << " is represented by" << endl;

    cout << "   *) the eight digit binary value " 
         << setw(1) << b8  // print the high order bit
	 << setw(1) << b7  // append each successive next lower order bit
	 << setw(1) << b6  // ...
	 << setw(1) << b5
	 << setw(1) << b4
	 << setw(1) << b3
	 << setw(1) << b2
	 << setw(1) << b1
	 << ",\n"

         << "   *) the octal value " 
	 << oct << dec_val
	 << ",\n"

         << "   *) and the hexadecimal value " 
	 << hex << dec_val
	 << ".\n"

	 << endl;

    return 0;
} // main

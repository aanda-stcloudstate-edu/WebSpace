/*	This program dispslays the values of floating-point numbers in CW.
	   Written by:
	   Date:
*/
#include <iostream>
#include <iomanip>
#include <climits>
using namespace std;

int main ()
{
	cout << "Bits in char:       " << setw(11) << CHAR_BIT  << endl;
	cout << "Short char Min:     " << setw(11) << SCHAR_MIN << endl;
	cout << "Short char Max:     " << setw(11) << SCHAR_MAX << endl;
	cout << "Unsigned char Max:  " << setw(11) << UCHAR_MAX << endl;
	cout << "char Max:           " << setw(11) << CHAR_MIN  << endl;
	cout << "char Max:           " << setw(11) << CHAR_MAX  << endl;
	cout << "short Max:          " << setw(11) << SHRT_MIN  << endl;
	cout << "short Max:          " << setw(11) << SHRT_MAX  << endl;
	cout << "Unsigned short Max: " << setw(11) << USHRT_MAX << endl;
	
	cout << "int Max:            " << setw(11) << INT_MIN   << endl;
	cout << "int Max:            " << setw(11) << INT_MAX   << endl;
	cout << "Unsigned int Max:   " << setw(11) << UINT_MAX  << endl;
	
	cout << "long Max:           " << setw(11) << LONG_MIN  << endl;
	cout << "long Max:           " << setw(11) << LONG_MAX  << endl;
	cout << "Unsigned long Max:  " << setw(11) << ULONG_MAX << endl;
	return 0;
}	// main

/*	Results
Bits in char:                 8
Short char Min:            -128
Short char Max:             127
Unsigned char Max:          255
char Max:                  -128
char Max:                   127
short Max:               -32768
short Max:                32767
Unsigned short Max:       65535
int Max:            -2147483648
int Max:             2147483647
Unsigned int Max:    4294967295
long Max:           -2147483648
long Max:            2147483647
Unsigned long Max:   4294967295
*/

/*	This program dispslays the values of floating-point numbers in CW.
	   Written by:
	   Date:
*/
#include <iostream>
#include <iomanip>
#include <cfloat>
using namespace std;

int main ()
{
	cout << "Digits of Precision:\n";
	cout << "float:     " << setw(10) << FLT_DIG  << endl;
	cout << "double:    " << setw(10) << DBL_DIG  << endl;
	cout << "long dbl:  " << setw(10) << LDBL_DIG << endl;

	cout << "\nSize of Mantissa:\n";
	cout << "float   :  " << setw(10) << FLT_MANT_DIG  << endl;
	cout << "double  :  " << setw(10) << DBL_MANT_DIG  << endl;
	cout << "long dbl:  " << setw(10) << LDBL_MANT_DIG << endl;

	cout << "\nLargest Integer for Negative Exponent (Float Radix):\n";
	cout << "float   :  " << setw(10) << FLT_MIN_EXP  << endl;
	cout << "double  :  " << setw(10) << DBL_MIN_EXP  << endl;
	cout << "long dbl:  " << setw(10) << LDBL_MIN_EXP << endl;

	cout << "\nLargest Integer for Negative Exponent (Base 10):\n";
	cout << "float   :  " << setw(10) << FLT_MIN_10_EXP  << endl;
	cout << "double  :  " << setw(10) << DBL_MIN_10_EXP  << endl;
	cout << "long dbl:  " << setw(10) << LDBL_MIN_10_EXP << endl;

	cout << "\nLargest Integer for Positive Exponent (Float Radix):\n";
	cout << "float   :  " << setw(10) << FLT_MAX_EXP  << endl;
	cout << "double  :  " << setw(10) << DBL_MAX_EXP  << endl;
	cout << "long dbl:  " << setw(10) << LDBL_MAX_EXP << endl;

	cout << "\nLargest Integer for Positive Exponent (Base 10):\n";
	cout << "float   :  " << setw(10) << FLT_MAX_10_EXP  << endl;
	cout << "double  :  " << setw(10) << DBL_MAX_10_EXP  << endl;
	cout << "long dbl:  " << setw(10) << LDBL_MAX_10_EXP << endl;

	cout << "\nLargest Possible Real Number:\n";
	cout << "float   :  " << setw(10) << FLT_MAX  << endl;
	cout << "double  :  " << setw(10) << DBL_MAX  << endl;
	cout << "long dbl:  " << setw(10) << LDBL_MAX << endl;

	cout << "\nSmallest Possible Real Number:\n";
	cout << "float   :  " << setw(10) << FLT_MIN  << endl;
	cout << "double  :  " << setw(10) << DBL_MIN  << endl;
	cout << "long dbl:  " << setw(10) << LDBL_MIN << endl;

	cout << "\nSmallest Possible Fraction:\n";
	cout << "float   :  " << setw(10) << FLT_EPSILON  << endl;
	cout << "double  :  " << setw(10) << DBL_EPSILON  << endl;
	cout << "long dbl:  " << setw(10) << LDBL_EPSILON << endl;
	return 0;
}	// main

/*	Results
Digits of Precision:
float:              6
double:            15
long dbl:          15

Size of Mantissa:
float   :          24
double  :          53
long dbl:          53

Largest Integer for Negative Exponent (Float Radix):
float   :        -125
double  :       -1021
long dbl:       -1021

Largest Integer for Negative Exponent (Base 10):
float   :         -37
double  :        -308
long dbl:        -308

Largest Integer for Positive Exponent (Float Radix):
float   :         128
double  :        1024
long dbl:        1024

Largest Integer for Positive Exponent (Base 10):
float   :          38
double  :         308
long dbl:         308

Largest Possible Real Number:
float   :  3.40282e+38
double  :  1.79769e+308
long dbl:  1.79769e+308

Smallest Possible Real Number:
float   :  1.17549e-38
double  :  2.22507e-308
long dbl:  2.22507e-308

Smallest Possible Fraction:
float   :  1.19209e-07
double  :  2.22045e-16
long dbl:  2.22045e-16
*/

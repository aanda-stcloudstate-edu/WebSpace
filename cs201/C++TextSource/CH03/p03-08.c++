/*	Demonstrate casting of numeric types.
	   Written by:
	   Date:
*/
#include <iostream>
using namespace std;

int main ()
{
	int    intNum1  = 100;
	int    intNum2  =  45;
	double fltNum3;
	fltNum3 = static_cast<double> (intNum1 / intNum2);
	cout << "<double> (intNum1 / intNum2) : "
	     << fltNum3 << endl;
	
	fltNum3 = static_cast<double> (intNum1) / intNum2;
	cout << "<double>  intNum1 / intNum2  : " 
	     << fltNum3 << endl;
	return 0;
}	// main 

/*	Results:
<double> (intNum1 / intNum2) : 2
<double>  intNum1 / intNum2  : 2.22222
*/

/*	Print report showing value of investment.
	   Written by:
	   Date:
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{

	cout << "Enter value of investment:   ";
	double presVal;
	cin  >> presVal;
	cout << "Enter rate of return (nn.n): ";
	double rate;
	cin  >> rate;
	cout << "Enter number of years:       ";
	int  years;
	cin  >> years;

	cout << "\nYear\t   Value\n";
	cout <<   "====\t========\n";
	cout << fixed << showpoint << setprecision(2);
	double futureVal =  presVal;
	for (int looper = 1; looper <= years; looper++)
	    {
	     futureVal = futureVal * (1 + rate/100.0);
	     cout << setw(3) << looper    << " \t";
	     cout << setw(8) << futureVal << endl;
	    } // for 
	return 0;
}	// main 

/*	Results:
Enter value of investment:   10000
Enter rate of return (nn.n): 7.2
Enter number of years:       5

Year      Value
====    ========
  1     10720.00
  2     11491.84
  3     12319.25
  4     13206.24
  5     14157.09
*/

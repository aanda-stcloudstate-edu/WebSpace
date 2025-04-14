/*	Demonstrate floating-point manipulators.
	   Written by:
	   Date:
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
	cout << "Demonstrate float manipulators\n\n";
	
	float  f1         = 1.0;
	float  f1234      = 1.234;
	float  f123456789 = 1234567.875;

	cout << f1 << "\t\t\t\tWith no manipulators\n";
	cout << f1234 << endl;
	cout << f123456789 << endl << endl;
	
	cout << fixed;
	cout << f1 << "\t\tWith fixed added\n";
	cout << f1234 << endl;
	cout << f123456789 << endl << endl;
	
	cout << setprecision(2);
	cout << f1 << "\t\t\tWith setprecision added\n";
	cout << f1234 << endl;
	cout << f123456789 << endl << endl;

	cout << setprecision(0);
	cout << f1234 << "\t\t\t\tWith setprecision(0)\n";
	cout << setprecision(0) << showpoint
	     << f1234 << "\t\t\t\tWith showpoint\n";
}  // main 

/*	Results:
Demonstrate float manipulators

1               With no manipulators
1.234
1.23457e+06

1.000000        With fixed added
1.234000
1234567.875000

1.00            With setprecision added
1.23
1234567.88

1               With setprecision(0)
1.              With showpoint
*/

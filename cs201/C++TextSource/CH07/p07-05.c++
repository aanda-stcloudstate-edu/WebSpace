/*	Demonstrate internal flag.
	   Written by:
	   Date:
*/
#include <iostream>
using namespace std; 

int main ()
{
	cout.fill ('*');
	cout << "Internal default   : |"; 
	cout.width(10);
	cout << -12345 << "|\n";
	cout.setf (ios::internal);
	cout << "Internal set on    : |"; 
	cout.width(10);
	cout << -12345 << "|\n";
	cout << "Display w/o width  : |" 
	     << -12345 << "|\n";
	cout.unsetf (ios::internal);
	return 0;
}	// main

/*	Results:
	Internal default   : |****-12345|
	Internal set on    : |-****12345|
	Display w/o width  : |-12345|

*/

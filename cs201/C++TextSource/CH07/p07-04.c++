/*	Demonstrate left and right justification
	   Written by:
	   Date:
*/
#include <iostream>
using namespace std; 

int main ()
{
	cout << "Default justification: |"; 
	cout.width(10);
	cout << 12345 << "|\n";
	cout.setf (ios::left, ios::adjustfield);
	cout << "Left justification   : |"; 
	cout.width(10);
	cout << 12345 << "|\n";
	
	cout.setf (ios::right, ios::adjustfield);
	cout << "Right justification  : |"; 
	cout.width(10);
	cout << 12345 << "|\n";
	return 0;
}	// main

/*	Results:
	Default justification: |     12345|
	Left justification   : |12345     |
	Right justification  : |     12345|
*/

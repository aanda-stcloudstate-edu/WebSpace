/*	Demonstrate testing I/O status
	   Written by:
	   Date:
*/
#include <iostream>
using namespace std;

int main ()
{
	cout << "Enter a number: ";
	bool status;
	int  dataIn = -2;
	status = (cin >> dataIn);
	
	cout << "status: " << boolalpha << status << endl
	     << "dataIn: " << dataIn << endl;

	if (cin.fail())
	    cout << "Input fail flag set.\n";
	else if (cin.bad())
	    cout << "Input bad flag set.\n";
	return 0;
}	// main 

/*	Results:
First run:
Enter a number: 7 
status: true 
dataIn: 7 
	
Second Run: 
Enter a number: x 
status: false 
dataIn: -2 
Input fail flag set.
*/

/*	Print a number series from 1 to a user-specified  
	limit in the form of a right triangle.
	   Written by:
	   Date:
*/
#include <iostream>
using namespace std;

int main ()
{
	int limit;

	// Read limit 
	cout << "Please enter a number between 1 and 9: ";
	cin  >> limit;

	for (int lineCtrl = 1; lineCtrl <= limit; lineCtrl++)
	    {
	     for (int numCtrl = 1;
	              numCtrl <= lineCtrl;
	              numCtrl++)
	        cout << numCtrl;
	     cout << endl;
	   } // for lineCtrl
	return 0;
}	// main 

/* Results

Please enter a number between 1 and 9: 5
1
12
123
1234
12345
123456
*/

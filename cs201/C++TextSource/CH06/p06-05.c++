/*	Print numbers on a line.
	   Written by:
	   Date:
*/
#include <iostream>
/*	Print numbers on a line.
	   Written by:
	   Date:
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
	for (int i = 1; i <= 3; i++)
	   {
	    cout << "Row " << i << ":";
	    for (int j = 1; j<= 5; j++)
	         cout << setw(3) << j;
	    cout << endl;
	   } // for i 
	return 0;
}	// main 

/* Results:
Row 1:   1  2  3  4  5
Row 2:   1  2  3  4  5
Row 3:   1  2  3  4  5
*/

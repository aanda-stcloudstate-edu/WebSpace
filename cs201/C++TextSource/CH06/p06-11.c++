/*	Print number series 1 to a user-specified limit 
	in the form of a rectangle.
	   Written by:
	   Date:
*/
#include <iostream>
using namespace std;

int main ()
{
	int limit;

	// Read limit
	cout << "\nEnter a number between 1 and 9: ";
	cin  >> limit;

	for (int row = 1; row <= limit; row++)
	   {
	    for (int col = 1; col <= limit; col++)
	         if (row >= col)
	             cout << col;
	         else
	             cout << '*';
	    cout << endl;
	   } // for row ... 
	return 0;
}	// main 

/* Results
Enter a number between 1 and 9: 5
1****
12***
123**
1234*
12345*
123456
*/

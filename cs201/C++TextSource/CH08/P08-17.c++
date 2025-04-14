/*	This program fills the diagonal of a matrix (square 
	array) with 0, the lower left triangle with -1 and the 
	upper right triangle with 1.
	   Written by:
	   Date:
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main (void)
{
	int table [6][6];

	for (int row = 0; row < 6; row++)
	   for (int column = 0; column < 6; column++)
	      if (row == column)
	         table [row][column] = 0;
	      else if (row > column)
	         table [row][column] = -1;
	      else
	         table [row][column] = 1;

	for (int row = 0; row < 6; row++)
	   {
	    for (int column = 0; column < 6; column++)
	         cout << setw(4) << table[row][column];
	    cout << endl;
	   } // for row 
	return 0;
}	// main 

/*	Results:

   0   1   1   1   1   1
  -1   0   1   1   1   1
  -1  -1   0   1   1   1
  -1  -1  -1   0   1   1
  -1  -1  -1  -1   0   1
  -1  -1  -1  -1  -1   0

*/

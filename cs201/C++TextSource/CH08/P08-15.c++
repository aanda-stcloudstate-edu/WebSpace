/*	This program is a test driver for "Fill Two-Dimensional Array."
	   Written by:
	   Date written:
*/

#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_ROWS = 4;
const int MAX_COLS = 5;

//	Prototype Declarations 
	void fillArray (int table[][MAX_COLS], int numCols);

int main () 
{
	int ary[MAX_ROWS][MAX_COLS];
	 
	fillArray (ary, MAX_ROWS);
	 
	cout << setfill('0');
	for (int row = 0; row < MAX_ROWS; row++)
	 	{
	 	 for (int col = 0; col < MAX_COLS; col++)
	 	 	cout << setw(2) << ary[row][col] << " ";
	 	 cout << endl;
		} // for 
		
	return 0;
}  // main 


/*	This function fills an array such that each array  
	element contains a number that, when viewed as a 
	two-digit integer, the first digit is the row number 
	and the second digit is the column number.
	   Pre   table is array in memory
	         numRows is number of rows in array
	   Post  array has been initialized
*/
void fillArray (int table[][MAX_COLS], int numRows)
{
	for (int row = 0; row < numRows; row++)
	   {
	    table [row][0] = row * 10;
	    for (int col = 1; col < MAX_COLS; col++)
	      table[row][col] = table[row][col - 1] + 1;
	   } // for 
}	// fillArray 

/*	================= End of Program ================= */

/*	Results:
00 01 02 03 04
10 11 12 13 14
20 21 22 23 24
30 31 32 33 34
*/

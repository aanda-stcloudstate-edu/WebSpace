/*	Demonstrate dynamic two-dimensional creating the 
	array and printing the element addresses.
	   Written by:
	   Date:
*/
#include <iostream>
#include <new>
using namespace std;

const int cNumCols = 4;

int main ()
{
	int numRows = 3;
	int (*p2dAry)[cNumCols] = new int[numRows][cNumCols];

	// Now print array addresses
	for (int row = 0; row < numRows; row++)
	    {
	     for (int col = 0; col < cNumCols; col++)
	          cout << &p2dAry[row][col] << " ";
	     cout << endl;
	    } // for row

	// Now demonstrate size of each row
	cout << "Row 1 Address: " << p2dAry     << endl;
	cout << "Row 2 Address: " << p2dAry + 1 << endl;
	cout << "Row 3 Address: " << p2dAry + 2 << endl;
	return 0;
}	// main

/*	Results:
0x80499d0 0x80499d4 0x80499d8 0x80499dc
0x80499e0 0x80499e4 0x80499e8 0x80499ec
0x80499f0 0x80499f4 0x80499f8 0x80499fc
Row 1 Address: 0x80499d0
Row 2 Address: 0x80499e0
Row 1 Address: 0x80499f0
*/

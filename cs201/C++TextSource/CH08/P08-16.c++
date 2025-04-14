/*	This program changes a two-dimensional array to the 
	corresponding one-dimensional array.
	   Written by: 
	   Date: 
*/
#include <iostream>
#include <iomanip>
using namespace std;

const int cROWS = 2;
const int cCOLS = 5;

int main ()
{
	int table [cROWS] [cCOLS] =
			{
			 { 00, 01, 02, 03, 04 },
			 { 10, 11, 12, 13, 14 }
			};
	int line [cROWS * cCOLS];

	for (int row = 0; row < cROWS; row++)
	   for (int column = 0; column < cCOLS; column++)
	       line[row * cCOLS + column] = table[row][column]; 

	cout << setfill ('0');
	for (int row = 0; row < cROWS * cCOLS; row++)
	   cout << setw(2) << line[row] << " ";
	return 0;
}	// main

/*	Results:
00  01  02  03  04  10  11  12  13  14 
*/

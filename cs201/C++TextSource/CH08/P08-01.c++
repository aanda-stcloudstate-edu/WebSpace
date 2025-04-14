//	P08-01 Print ten numbers per line

/*	Test driver for print ten numbers per line
	   Written by:
	   Date written:
*/
#include <iostream>
#include <iomanip>
using namespace std;

const int cPER_LINE = 12;

int main (void)
{
	int list[cPER_LINE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	
//	A program fragment
	for (int i = 0, numPrinted = 0; i < cPER_LINE; i++)
		{
		 cout << setw(3) << list[i];
		 if (numPrinted < 9)
			numPrinted++;
		 else
			{
			 cout << endl;
			 numPrinted = 0;
			}	// else 
		}	// for 
		
	return 0 ;
}	/* main */

/*	Results:

  1  2  3  4  5  6  7  8  9 10
 11 12

*/

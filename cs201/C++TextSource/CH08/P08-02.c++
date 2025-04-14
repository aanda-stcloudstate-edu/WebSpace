/*	Initialize array with square of index and print it.
	   Written by:
	   Date:
*/
#include <iostream>
#include <iomanip>
using namespace std;

const int cARY_SIZE = 5;

int main ()
{
	int sqrAry[cARY_SIZE];
	for (int i = 0; i < cARY_SIZE; i++) 
	   sqrAry[i] = i * i;

	cout << "Element\tSquare\n";
	cout << "=======\t======\n";
	for (int i = 0; i < cARY_SIZE; i++)
	   {
	    cout << setw(5) << i << "\t";
	    cout << setw(5) << sqrAry[i] << endl;
	   } // for i 
	return 0;
}	// main 

/*	Results:

Element Square
======= ======
    0      0
    1      1
    2      4
    3      9
    4     16

*/

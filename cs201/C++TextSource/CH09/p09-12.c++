/*	Read integers from keyboard & print them multiplied by 2.
	   Written by:
	   Date:
*/
#include <iostream>
#include <iomanip>
using namespace std;

const short cSIZE = 5;

void multiply (int* pAry, int cSIZE);

int main () 
{
	int  ary [cSIZE];

	int* pLast = ary + cSIZE - 1;
	for (int* pWalk = ary; pWalk <= pLast; pWalk++)
	    {
	     cout << "Please enter an integer: ";
	     cin  >> *pWalk;
	    } // for pWalk

	multiply (ary, cSIZE);

	cout << "Doubled size is: \n";
	for (int* pWalk = ary; pWalk <= pLast; pWalk++)
	    cout << setw(4) << *pWalk << endl;
	return 0;
}	// main 
/*	================== multiply =================== 
	Multiply elements in an array by 2.
	   Pre  pAry is pointer to full array 
	        size indicates number of elements in array
	   Post Values in array doubled
*/
void multiply (int* pAry, int  size)
{
	int* pLast = pAry + size - 1;
	for (int* pWalk = pAry; pWalk <= pLast; pWalk++)
	    *pWalk = *pWalk * 2;
	 return;
}	// multiply 

/*	Results:

Please enter an integer: 2
Please enter an integer: 7
Please enter an integer: 12
Please enter an integer: 3
Please enter an integer: 6
Doubled size is: 
   4
  14
  24
   6
  12

*/

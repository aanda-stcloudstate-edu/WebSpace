
/*	This program tests searches.
	   Written by:  
	   Date:		
	
*/
#include <iostream>
#include <iomanip>
using namespace std;

const int SIZE = 9;

bool seqSearch (int  list[ ], int  last, int  target,
                int& locn);
	
int main (void)
{
	/* Local Definitions */
	int i;
	int locn;
	int ary[ SIZE ] = {19, 13, 58, 10, 14, 1, 21, 64, 9};
	
	cout << "\nIndexes  : ";
	for (i = 0; i < SIZE; i++) 
		cout << setw(3) << i;

	cout << "\nList data: ";
 	for (i = 0; i < SIZE; i++) 
		cout << setw(3) << ary[i];
	cout << endl;
 	
 	
 	if (seqSearch (ary, SIZE - 1,  9, locn)) 	
 		cout << "Found  9 at location " << locn << endl;
 	else
 		cout << " 9 Not Found at      " << locn << endl;
   	
 	if (seqSearch (ary, SIZE - 1, 19, locn)) 	
 		cout << "Found 19 at location " << locn << endl;
 	else
 		cout << "19 Not Found at      " << locn << endl;

 	
 	if (seqSearch (ary, SIZE - 1, 10, locn)) 	
 		cout << "Found 10 at location " << locn << endl;
 	else
 		cout << "10 Not Found at      " << locn << endl;

  	
 	if (seqSearch (ary, SIZE - 1, 0, locn)) 	
 		cout << "Found 0 at location  " << locn << endl;
 	else
 		cout << "0 Not Found at       " << locn << endl;
	 
	cout << endl;
   	
	return 0;
}  /* main */

/*	Locate the target in an unordered list of size elements.
	   Pre   list must contain at least one item 
	         last is index to last element in list
	         target contains data to be located
	   Post  FOUND: matching index stored in locn 
	                return true
	         NOT FOUND: last stored in locn 
	                    return false
*/
bool seqSearch (int  list[], int  last, int  target,
                int& locn)
{
	int looker = 0; 
	while (looker < last && target != list[looker])
	   looker++; 
	locn = looker;
	return (target == list[looker]);
}	// seqSearch 

/*	================= End of Program ================= */

/*	Results:

	Indexes  :   0  1  2  3  4  5  6  7  8
	List data:  19 13 58 10 14  1 21 64  9
	Found  9 at location 8
	Found 19 at location 0
	Found 10 at location 3
	0 Not Found at       8

*/

/*	This program tests the binary search.
	   Written by:
	   Date written:
*/
#include <iostream>
#include <iomanip>
using namespace std;

const int SIZE = 9;

bool binarySearch (int list[], int end, int target, int& locn);

int main (void)
{
	int ary[ SIZE ] = {1, 9, 10, 13, 14, 19, 21, 58, 64};
	
	cout << "\nIndexes  : ";
	for (int i = 0; i < SIZE; i++) 
		cout << setw(3) << i;

	cout << "\nList data: ";
 	for (int i = 0; i < SIZE; i++) 
		cout << setw(3) << ary[i];
	cout << endl;
 	 	
	int locn;
 	if (binarySearch (ary, SIZE - 1,  1, locn)) 	
		cout << "Found  1 at location " << locn << endl;
 	else
 		cout << " 1 Not Found at      " << locn << endl;
   	
 	if (binarySearch (ary, SIZE - 1,  9, locn)) 	
		cout << "Found  9 at location " << locn << endl;
 	else
 		cout << " 9 Not Found at      " << locn << endl;
 	
 	if (binarySearch (ary, SIZE - 1, 64, locn)) 	
		cout << "Found 64 at location " << locn << endl;
 	else
 		cout << "64 Not Found at      " << locn << endl;

 	if (binarySearch (ary, SIZE - 1, -4, locn)) 	
		cout << "Found -4 at location " << locn << endl;
 	else
 		cout << "-4 Not Found at      " << locn << endl;

 	if (binarySearch (ary, SIZE - 1, 33, locn)) 	
		cout << "Found 33 at location " << locn << endl;
 	else
 		cout << "33 Not Found at      " << locn << endl;

 	if (binarySearch (ary, SIZE - 1, 93, locn)) 	
		cout << "Found 93 at location " << locn << endl;
	else
 		cout << "93 Not Found at      " << locn << endl;

	 return 0;
}  // main 

/*	Search an ordered list using binary search. 
	   Pre  list must contain at least one element
	        end--index to the largest element in list
	        target is value of element being sought
	   Post  FOUND--locn = index to target 
	                return true
	         NOT FOUND--locn = element < or > target 
	                    return false
*/
bool binarySearch (int  list[], int end, int target,
                   int& locn)
{
	int first = 0;
	int last  = end;
	int mid;
	while (first <= last)
	   {
	    mid = (first + last) / 2;
	    if (target > list[mid])
	       // look in upper half 
	       first = mid + 1;
	    else if (target < list[mid])
	       // look in lower half 
	       last = mid - 1;
	    else
	       // found equal: force exit 
	       first = last + 1;
	   } // end while 
	locn = mid;
	return target == list [mid];
}	// binarySearch 

//	================= End of Program ================= 


/*
Results:
	Indexes  :   0  1  2  3  4  5  6  7  8
	List data:   1  9 10 13 14 19 21 58 64
	Found  1 at location 0
	Found  9 at location 1
	Found 64 at location 8
	-4 Not Found at      0
	33 Not Found at      7
	93 Not Found at      8
*/

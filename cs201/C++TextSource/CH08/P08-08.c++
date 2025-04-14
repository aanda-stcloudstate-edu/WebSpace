/*	Test driver for sorting. 
	   Written by:
	   Date written:
*/
#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_ARY_SIZE = 15;

//	Prototype Declarations 
	void bubbleSort	(int list [ ], int last);
	void bubbleUp (int list[ ], int first, int last); 
	
int main (void) 
{
//	Local Declarations 
	int i;
	int	ary[ MAX_ARY_SIZE ] = { 89, 72, 3,  15, 21, \
								57, 61, 44, 19, 98, \
							    5,  77, 39, 59, 61 };

//	Statements 
	printf("Unsorted array: ");
	for (i = 0; i < MAX_ARY_SIZE; i++)
		printf("%3d", ary[ i ]);
		
	bubbleSort (ary, MAX_ARY_SIZE - 1);

	printf("\nSorted array:   ");
	for (i = 0; i < MAX_ARY_SIZE; i++)
		printf("%3d", ary[ i ]);
	printf("\n");
	return 0;
}	// main 


/*	Sort list using bubble sort. Adjacent elements are 
	compared and exchanged until list is completely ordered.
	   Pre  The list must contain at least one item
	        last is index to last element in list
	   Post List sorted low to high
*/
void bubbleSort (int list [], int last)
{
	 for(int current = 0; current < last; current++)
	    bubbleUp (list, current, last);
	return;
}	// bubbleSort 

/*	Move the lowest element in unsorted portion of an 
	array to the current element in the unsorted portion.
	   Pre  list must contain at least one element
	        current is start of unsorted data
	        last is end of the unsorted data
	   Post Array segment rearranged so that lowest 
	        element at beginning of unsorted portion
*/ 
void bubbleUp (int list[], int current, int last)
{
	for (int walker = last; walker > current; walker--)
	   if (list[walker]  < list[walker - 1])
	     {
	      int temp         = list[walker];
	      list[walker]     = list[walker - 1];
	      list[walker - 1] = temp;
	      } // if 
	return;
}	// bubbleUp 

/*	Results:

	Unsorted array:  89 72  3 15 21 57 61 44 19 98  5 77 39 59 61
	Sorted array:     3  5 15 19 21 39 44 57 59 61 61 72 77 89 98

*/

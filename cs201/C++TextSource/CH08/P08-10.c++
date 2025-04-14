/*	Test driver for sorting. 
	   Written by:
	   Date written:
*/
#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_ARY_SIZE = 15;
#ifndef TRUE
const int TRUE         =  1;
const int FALSE        =  0;
#endif

/*	Prototype Declarations */
	void insertionSort (int list[ ], int last);
	void insertOne     (int list[ ], int first);
	
int main (void) 
{
/*	Local Declarations */
	int i;
	int	ary[ MAX_ARY_SIZE ] = { 89, 72, 3,  15, 21, \
								57, 61, 44, 19, 98, \
							    5,  77, 39, 59, 61 };

/*	Statements */
	printf("Unsorted array: ");
	for (i = 0; i < MAX_ARY_SIZE; i++)
		printf("%3d", ary[ i ]);
		
	insertionSort (ary, MAX_ARY_SIZE - 1);

	printf("\nSorted array:   ");
	for (i = 0; i < MAX_ARY_SIZE; i++)
		printf("%3d", ary[ i ]);
	printf("\n");
	return 0;
}	/* main */

/*	Sort list using Insertion Sort. The list is divided 
	into sorted and unsorted list. With each pass, first  
	element in unsorted list is inserted into sorted list.
	   Pre   List must contain at least one element
	         last is index to last element in the list
	   Post  List has been rearranged
*/
void insertionSort (int list[], int last)
{
	for (int current = 1; current <= last; current++)
	   insertOne(list, current);
	return;
}	// insertionSort 

/*	Sorts current element in unsorted list into its proper
	location in sorted portion of the list--one sort pass.
	   Pre   list must contain at least one element
	         current is beginning of unsorted list
	   Post  next element in its proper location
*/
void insertOne (int list[], int current)
{
	bool located = false;
	int  temp    = list[current];
	int  walker;
	for (walker = current - 1; walker >= 0 && !located;)
	{
	   if (temp < list[walker])
	      {
	       list[walker + 1] = list[walker];
	       walker--;
	      } // if 
	   else
	      located = true;
	} // for loop
	list [walker + 1] = temp;
	return;
}	// insertOne 

/*
Results:
	Unsorted array:  89 72  3 15 21 57 61 44 19 98  5 77 39 59 61
	Sorted array:     3  5 15 19 21 39 44 57 59 61 61 72 77 89 98
*/

/*	Test driver for sorting. Includes Program 8-5, exchangeSmallest 
	   Written by:
	   Date written:
*/
#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_ARY_SIZE = 15;

/*	Prototype Declarations */
	void selectionSort	  (int list[], int last);
	void exchangeSmallest (int list[], int current, int last); 
	
int main (void) 
{
/*	Local Declarations */
	int i;
	int	ary[ MAX_ARY_SIZE ] = { 89, 72, 3,  15, 21, \
								57, 61, 44, 19, 98, \
							    5,  77, 39, 59, 61 };

/*	Statements */
	cout << "Unsorted array: ";
	for (i = 0; i < MAX_ARY_SIZE; i++)
		cout << setw(3) << ary[i];
		
	selectionSort (ary, MAX_ARY_SIZE - 1);

	cout << "\nSorted array:   ";
	for (i = 0; i < MAX_ARY_SIZE; i++)
		cout << setw(3) << ary[i];
	cout << endl;
	return 0;
}	/* main */

/*	Sorts by selecting smallest element in unsorted portion 
	of array and exchanging it with element at the beginning 
	of the unsorted list.
	   Pre   list must contain at least one item
	         last contains index to last element
	   Post  list sorted smallest to largest
*/
void selectionSort (int list[], int last)
{
	for (int current = 0; current < last; current++)
	     exchangeSmallest (list, current, last);
	return;
}	// selectionSort 

/*	Given array of integers, place smallest element into 
	position in array.
	   Pre   list: must contain at least one element
	         current: beginning of unsorted portion
	         last: last element--Must be > current 
	   Post  smallest moved to beginning of unsorted
*/
void exchangeSmallest (int list[], int current, int last)
{
	int smallest = current;
	for (int walker = current + 1; walker <= last; walker++)
	   if (list[walker] < list[smallest])
	       smallest = walker;

	// Smallest selected: exchange with current element 
	int tempData   = list[current];
	list[current]  = list[smallest];
	list[smallest] = tempData;
	return;
}	// exchangeSmallest 

/*
Results:
	Unsorted array:  89 72  3 15 21 57 61 44 19 98  5 77 39 59 61
	Sorted array:     3  5 15 19 21 39 44 57 59 61 61 72 77 89 98
*/

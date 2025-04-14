/*	Test driver for insertion sort. 
	   Written by: 
	   Date: 
*/
#include <iostream>
#include <iomanip>
using namespace std;

#define cMAX_ARY_SIZE 15

void insertionSort (int list[], int last);

int main () 
{
	int ary[cMAX_ARY_SIZE] = { 89, 72,  3, 15, 21, 
	                           57, 61, 44, 19, 98, 
	                            5, 77, 39, 59, 61 };

	cout << "Unsorted array: ";
	for (int i = 0; i < cMAX_ARY_SIZE; i++)
	     cout << setw(3) << ary[i];
	
	insertionSort (ary, cMAX_ARY_SIZE - 1);

	cout << "\nSorted array:   ";
	for (int i = 0; i < cMAX_ARY_SIZE; i++)
	     cout << setw(3) << ary[i];
	cout << endl;
	return 0;
}	// main 

/*	================== insertionSort ===================
	Sort list using Insertion Sort. The list is divided 
	into sorted and unsorted list. With each pass, first  
	element in unsorted list is inserted into sorted list.
	   Pre   list must contain at least one element 
	         last contains index to last element in list
	   Post  list has been rearranged 
*/
void insertionSort (int list[], int last)
{

	for (int current = 1; current <= last; current++)
	   {
	    int walker;
	    int located = false;
	    int temp    = list[current];
	    for  (walker = current - 1; walker >= 0 && !located;)
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
	   } // for 
	return;
}	// insertionSort 

/*	================= End of Program ================= */

/*	Results:
Unsorted:  89 72  3 15 21 57 61 44 19 98  5 77 39 59 61
Sorted  :   3  5 15 19 21 39 44 57 59 61 61 72 77 89 98
*/

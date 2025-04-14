//	P06-20 smallestEOF function

/*	This program tests smallestEOF.
	   Written by:
	   Date written:
*/
#include <iostream>
#include <limits>
using namespace std;

int smallestEOF (void);

int main (void) 
{
	cout << "\n\nSmallest is: " << smallestEOF ( ) << endl;
	return 0;
}	// main

/*	================ smallestEOF ================= 
	Read a series of positive numbers terminated by
	EOF and pass smallest to the calling program
	   Pre   Nothing
	   Post  Data read and smallest returned
*/
int smallestEOF (void)
{
	int smallest = INT_MAX;        //requires limits lib
	int numIn;
	cout << "\nPlease enter an integer: ";
	while (cin >> numIn)
	   {
	    if (numIn < smallest)
	        smallest = numIn;
	    cout << "Enter next integer <EOF> to stop: ";
	   } // while
	return smallest;
}	 // smallestEOF

/*
Results:
	Please enter an integer: 11
	Enter next integer <EOF> to stop: 8
	Enter next integer <EOF> to stop: 17
	Enter next integer <EOF> to stop: 3
	Enter next integer <EOF> to stop: 0
	Enter next integer <EOF> to stop: -5
	Enter next integer <EOF> to stop:

	Smallest is: -5
*/

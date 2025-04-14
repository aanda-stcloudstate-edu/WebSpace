//	P06-18 sumEOF function

/*	This program tests sumEOF.
	   Written by:
	   Date:
*/
#include <iostream>
using namespace std;

int sumEOF (void);
	
int main (void) 
{
	cout << "\n\nThe sum is: " << sumEOF () << endl;
	return 0;
}	// main

/*	Read a series of numbers, terminated by EOF, and  
	return their sum to the calling program.
	   Pre   Nothing
	   Post  Data read from keyboard and sum returned
*/
int sumEOF (void)
{
	int sum = 0;
	int  nmbr;
	cout << "\nEnter first integer <EOF> to stop: ";
	while (cin >> nmbr)
	   {
	    sum  += nmbr;
	    cout << "Next integer <EOF> to stop: ";
	   } // while
	return sum;
}	// sumEOF

/*	Results:
	Enter first integer <EOF> to stop: 2
	Next integer <EOF> to stop: 3
	Next integer <EOF> to stop: 4
	Next integer <EOF> to stop: 5
	Next integer <EOF> to stop: 6
	Next integer <EOF> to stop: ^d
	
	The sum is: 20
*/

//	PD-01.cp  Demonstrate integer numbers

/*	Demonstrate circular nature of unsigned integer numbers.

	Written by: 
	Date: 
*/

#include <iostream.h>
#include <limits.h>

int main (void)
{
	// Local Declarations 
	unsigned int x = UINT_MAX;
	
	// Statements 
	cout << "Maximum value:       " << x << endl;
	
	x++ ;
	cout << "Maximum value + 1:   " << x << endl;
	
	x++;
	cout << "Maximum value + 1:   " << x << endl;

	return 0;
}	// main 

/*	Results:
	Maximum value:      65535 
	Maximum value + 1:  0 
	Maximum value + 1:  1 
*/

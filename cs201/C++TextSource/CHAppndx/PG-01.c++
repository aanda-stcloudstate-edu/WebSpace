/*	This program tests string directives.
	   Written by: 
	   Date: 
*/
#include <iostream>
using namespace std;
	
#define PRINT_INT(a) \
	cout << "Variable '" #a "' contains: " << a << endl
	 
int main () 
{
	int legalAge = 21;
	
	PRINT_INT (legalAge);
	 
	return 0;
}	// main

/*	Results:
Variable 'legalAge' contains: 21
*/

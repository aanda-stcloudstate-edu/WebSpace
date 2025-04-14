/*	This program demonstrates that one function can be called
	multiple times.
	   Written by: 
	   Date: 
*/
#include <iostream>
using namespace std;

/*	Prototype Declarations */
	void printOne (int x);

int main ()
{
	// First call 
	int a = 5;
	printOne (a);
	
	// Second call 
	a = 33;
	printOne (a);

	// Done. Return to operating system. 
	return 0;
}	// main 

/*	=================== printOne ===================
	Print one integer value.
	   Pre   x contains number to be printed 
	   Post  value in x printed 
*/
void printOne (int x)
{
	cout << x << endl;
	return;
}	// printOne 

/*	Results:
5
33
*/

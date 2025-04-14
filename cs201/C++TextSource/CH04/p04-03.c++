/*	This program reads a number and prints its square.
	   Written by: 
	   Date: 
*/
#include <iostream>
using namespace std;

//	Prototype Declarations 
int  getNum   (void);
int  sqr      (int x);
void printOne (int x);

int main ()
{
	// Get number and square it 
	int a = getNum ();

	// Square the number just read 
	int b = sqr (a);
	
	// Now print it 
	printOne(b);

	// Done. Return to operating system. 
	return 0;
}	// main 

/*	=================== getNum ===================
	Read number from keyboard and return it.
	   Pre   nothing
	   Post  number read and returned
*/
int getNum (void)
{
	cout << "Enter a number to be squared: ";
	int numIn;
	cin >>  numIn;
	return numIn;
}	// getNum 

/*	=================== sqr ===================
	Return the square of the parameter.
	   Pre   x contains number to be squared
	   Post  squared value returned
*/
int sqr (int x)
{
	return (x * x);
}	// sqr 

/*	=================== printOne ===================
	Print one integer value.
	   Pre   x contains number to be printed
	   Post  value in x printed
*/
void printOne (int x)
{
	cout << "The value is: " << x << endl;
	return;
}	// printOne 

/*	Results:
Enter a number to be squared: 81
The value is: 6561
*/

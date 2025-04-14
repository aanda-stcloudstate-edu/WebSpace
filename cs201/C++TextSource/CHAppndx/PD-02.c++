//	PD-02.cp  Demonstration of two’s complement

/*	This program demonstrates the two’s complement values.
	Written by: 
	Date: 
*/
#include <iostream.h>

int main (void)
{
//	Local Declarations 
	int a = +13422;
	int b = -768;
	int ca;
	int cb;

//	Statements 
	ca = ~ a;
	cb = ~ b;
	cout << "The complement of " << a << " is " << ca << endl;
	cout << "The complement of " << b << " is " << cb << endl;
	return 0;
}	// main 

/*	Results:
	The complement of  13422 is -13423
	The complement of   -768 is    767
*/

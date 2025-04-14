/*	This program shows how we can use different pointers 
	to point to the same data variable. 
	   Written by:
	   Date:
*/
#include <iostream>
using namespace std;

int main () 
{
	int  a;
	int* p = &a; 
	int* q = &a; 
	int* r = &a; 

	cout << "Enter a number: ";
	cin  >> a;
	 
	cout << *p << endl; 
	cout << *q << endl; 
	cout << *r << endl; 

	return 0;
}	// main 

/*	Results:

Enter a number: 16
16
16
16

*/

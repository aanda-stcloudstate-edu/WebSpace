/*	Demonstrate pointer use.
	   Written by:
	   Date:
*/
#include <iostream>
using namespace std;

int main () 
{
	int  a;
	int* p;


	a = 14;
	p = &a;

	cout << a << " " << &a << endl;
	cout << p << " " << *p << " " << a << endl;

	return 0;
}	// main 

/*	Results:

14 0x00135760
0x00135760 14 14

*/

/*	Examine the effect of precedence on an expression.
	   Written by:
	   Date:
*/
#include <iostream>
using namespace std;

int main ()
{
	int a = 10;
	int b = 20;
	int c = 30;

	cout << "a *  b + c  is: " << a *  b + c  << endl;
	cout << "a * (b + c) is: " << a * (b + c) << endl;
	return 0;
}	// main 

/*	Results:

a *  b + c  is: 230
a * (b + c) is: 500

*/

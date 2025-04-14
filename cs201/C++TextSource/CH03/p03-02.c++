/*	Demonstrate examples of compound assignments.
	   Written by:
	   Date:
*/
#include <iostream>
using namespace std;

int main ()
{
	int x = 10;
	int y = 5;
	cout << "x: " << x << "  |  " << "y: " << y << "  |  "
	     << "x *= y: " <<  (x *= y);
	cout << "  |  x is now: " << x << endl;
	        
	x = 10;
	cout << "x: " << x << "  |  " << "y: " << y << "  |  "
	     << "x /= y:  " <<  (x /= y);
	cout << "  |  x is now:  " << x << endl;

	x = 10;
	cout << "x: " << x << "  |  " << "y: " << y << "  |  "
	     << "x %= y:  " <<  (x %= y);
	cout << "  |  x is now:  " << x << endl;

	return 0;
}	// main

/*	Results:

x: 10  |  y:  5   |  x *= y: 50   |  x is now: 50
x: 10  |  y:  5   |  x /= y:  2   |  x is now:  2
x: 10  |  y:  5   |  x %= y:  0   |  x is now:  0

*/

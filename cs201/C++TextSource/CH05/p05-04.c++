/*	Nested if in two-way selection.
	   Written by:
	   Date:
*/
#include <iostream>
using namespace std;

int main ()
{
	cout << "Please enter two integers: ";
	int  a;
	int  b;
	cin  >> a >> b;

	if (a <= b)
	    if (a < b)
	        cout << a << " < " << b << endl;
	    else  // equal
	        cout << a << " == " << b << endl;
	else  // greater than
	    cout << a << " > " << b << endl;

	return 0;
}	// main

/*	Results:
Please enter two integers: 10 5
10 > 5

Please enter two integers: 10 10
10 == 10

Please enter two integers: 5 10
5 < 10
*/

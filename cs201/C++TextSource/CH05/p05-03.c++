/*	Two-way selection.
	   Written by:
	   Date:
*/
#include <iostream>
using namespace std;

int main ()
{
	cout <<"Please enter two integers: ";
	int  a;
	int  b;
	cin  >> a >> b;

	if (a <= b)
	    cout << a << " <= " << b << endl;
	else
	    cout << a << " > " << b << endl;
	return 0;
}	// main 

/*	Results:
Please enter two integers: 10 15
10 <= 15

Please enter two integers: 15 10
15 > 10
*/

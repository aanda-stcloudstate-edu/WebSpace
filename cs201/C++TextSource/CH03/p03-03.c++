/*	Example of postfix increment.
	   Written by:
	   Date:
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
	int a = 4;

	cout << "value of a    : " << setw(2) << a   << endl;
	cout << "value of a++  : " << setw(2) << a++ << endl;
	cout << "new value of a: " << setw(2) << a   << endl;
	return 0;
}	// main 

/*	Results:

value of a    :  4
value of a++  :  4
new value of a:  5

*/

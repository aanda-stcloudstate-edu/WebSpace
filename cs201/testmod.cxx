/* Program to demonstrate the integer division operators
 * Prof. Anda
 * csci 201
*/
#include <iostream>
#include <iomanip>
using namespace std;
int main ()
{
    int dividend, divisor;

    cout << "Demonstration of the integer division operators:\n\n";
    for (;;)
    {
	cout << "Enter a signed integer DIVIDEND "
	     << "(<EOF>[^D] to stop): ";
	if (!(cin  >> dividend))
	    break;
	cout << endl;
	cout << "Enter a signed integer DIVISOR: "
	     << "(<EOF>[^D] to stop): ";
	if (!(cin  >> divisor))
	    break;
	cout << endl;
	cout << endl;
	cout << dividend << " / " << divisor << " --> " << (dividend / divisor)
	     << " & "
	     << dividend << " % " << divisor << " --> " << (dividend % divisor)
	     << endl << endl;
    }
    return 0;
}

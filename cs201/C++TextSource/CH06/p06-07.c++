/*	Adds a list of integers from the standard input unit. 
	   Written by:
	   Date:
*/
#include <iostream>
using namespace std;

int main ()
{
	int num;
	int sum;

	num = sum = 0; 
	cout << "Enter your numbers: <EOF> to stop.\n";
	cin >> num;
	do
	   {
	    sum += num;
	   } while (cin >> num);
	cout << "Total: " << sum << endl;
	return  0;
}	// main 

/* Results:
Run 1:
	Enter your numbers: <EOF> to stop.
	10 15 20 25
	^dTotal: 70

Run 2:
	Enter your numbers: <EOF> to stop.
	^dTotal: 0
*/

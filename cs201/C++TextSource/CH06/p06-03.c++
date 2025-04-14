/*	Add a list of integers from the standard input unit 
	   Written by: 
	   Date: 
*/
#include <iostream>
using namespace std;

int main ()
{
	int x;
	int sum = 0;

	cout << "Enter your numbers: <EOF> to stop.\n";
	while (cin >> x)
	   sum += x;
	cout << "\nThe total is: " << sum << endl;
	return  0;
}	// main 

/* Results:
Enter your numbers: <EOF> to stop
15
22
3^d
The total is: 40
*/

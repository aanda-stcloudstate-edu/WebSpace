/*	This program reads two integer numbers from the 
	keyboard and prints their product.
	   Written by:
	   Date:
*/ 
#include <iostream>
using namespace std;

int main (void)
{
//	Local Definitions 
	int number1;
	int number2;
	int result;

//	Statements 
	cin >> number1;
	cin >> number2;
	result = number1 * number2;
	cout << result;
	return 0;
}	// main 

/*	Results

8 5
40

*/
/*	Show how pointer to pointer can be used by different 
	input functions to read data to the same variable.
	   Written by:
	   Date:
*/
#include <iostream>
using namespace std;

int main () 
{
	int    a; 
	int*   p; 
	int**  q; 
	int*** r;

	p = &a;
	q = &p; 
	r = &q;

	cout << "Enter a number: ";
	cin  >> a; 
	cout << "Your number is: " << a << endl;

	cout << "\nEnter a number: ";
	cin  >> *p; 
	cout << "Your number is: " << a << endl;

	cout << "\nEnter a number: ";
	cin  >> **q;
	cout << "Your number is: " << a << endl; 

	cout << "\nEnter a number: ";
	cin  >> ***r; 
	cout << "Your number is: " << a << endl; 
	cout << "That's all folks!";
	return 0;
}	// main 

/*	Results:

Enter a number: 1
Your number is: 1

Enter a number: 2
Your number is: 2

Enter a number: 3
Your number is: 3

Enter a number: 4
Your number is: 4
That's all folks!

*/

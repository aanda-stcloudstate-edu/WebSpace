/*	This program adds two numbers using pointers, to 
	demonstrate the concept of pointers.
	   Written by:
	   Date:
*/
#include <iostream>
using namespace std;

int main () 
{
	int  a;
	int  b;
	int  r;
	int* pa = &a;
	int* pb = &b;
	int* pr = &r;

	cout << "\nEnter the first number: "; 
	cin  >> *pa; 
	cout << "\nEnter the second number: "; 
	cin  >> *pb;
	
	*pr = *pa + *pb; 
	
	cout << endl; 
	cout << *pa << " + " << *pb << " is " << *pr << endl; 
	return 0;
}	// main 

/*	Results:


Enter the first number: 5

Enter the second number: 8

5 + 8 is 13

*/

/*	This program tests the reuseability of dynamic memory.
	   Written by:
	   Date:
*/
#include <iostream>
using namespace std;

int main ()
{
	char* ptr1 = new char[16];
	cout << "Memory allocated at 1: " << &ptr1 << endl;

	char* ptr2 = new char[16];
	cout << "Memory allocated at 2: " << &ptr2 << endl;

	delete[] ptr1;

	char* ptr3 = new char[16];
	cout << "Memory allocated at 3: " << &ptr3 << endl;
	return 0;
}	// main

/*	Results

Results in Personal Computer:
Memory allocated at 1: 0x244da350
Memory allocated at 2: 0x244da34c
Memory allocated at 3: 0x244da348

Results in UNIX system: 

*/

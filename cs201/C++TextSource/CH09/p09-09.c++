/*	Demonstrate writing pointer values
	   Written by:
	   Date:
*/
#include <iostream>
using namespace std;

int main ()
{
	int   anInt = 1234;
	int*  pInt  = &anInt;
	cout << "anInt is located at:   " << &anInt << endl;
	cout << "pInt's value is:       " << pInt   << endl;

	char* pChar = "Hello";        // Pointer to C-string
	cout << "pChar points to:       " << pChar  << endl;
	cout << "pChar's value is:      " 
	     << static_cast<void*> (pChar) << endl;
	return 0;
}	// main

/*	Results
anInt is located at:   0xbffffb20
pInt's value is:       0xbffffb20
pChar points to:       Hello
pChar's value is:      0x001cde5e
*/

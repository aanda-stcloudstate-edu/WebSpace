/*	Deomonstrate use of skip white space
	   Written by:
	   Date:
*/
#include <iostream>
using namespace std;

int main ()
{
	char aChar;
	
	// Read Characters
	cout << "Enter <space z>      : ";
	cin  >> aChar;
	cout << "Character read is    : " << aChar;
	cin.unsetf (ios::skipws);
	cin  >> aChar;					                          // read \n 
	cout << "\nCharacter read is    : " << (int)aChar;
	cout << "\nEnter <space z> again: ";
	cin  >> aChar; 
	cout << "Character read is    : " << (int)aChar;
	cin  >> aChar;
	cout << "\nCharacter read is    : " << (int)aChar;
	cin  >> aChar;
	cout << "\nCharacter read is    : " << (int)aChar;
	return 0;
}	// main

/* Results:
Enter <space z>      :  z
Character read is    : z
Character read is    : 10
Enter <space z> again:  z
Character read is    : 32
Character read is    : 122
Character read is    : 10

*/

//	P05-08 Multivalued case statements
//	This code fragment modified to main for testing

#include <iostream>
using namespace std;

int main (void)
{
//	Local Definitions
	int printFlag = 1;

//	Statements
	switch (printFlag)
	   {
	    case 1:
	    case 3:  cout << "Good Day\n";
	             cout << "Odds have it!\n";
	             break;
	    case 2:
	    case 4:  cout << "Good Day\n";
	             cout << "Evens have it!\n";
	             break;
	    default: cout << "Good Day, I'm confused!\n";
	             cout << "Bye!\n";
	             break;
	   }  // switch
	return 0 ;
} //  main

/*
Results:

Test 1:
	Good Day
	Evens have it!
Test 2:
	Good Day, I'm confused!
	Bye!
*/

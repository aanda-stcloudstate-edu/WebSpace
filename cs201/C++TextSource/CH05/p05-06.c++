//	P05-07 This code fragment modified to main for syntax checking.
//	It will not execute.

#include <iostream>
using namespace std;

//	Prototype Declarations
	void doCase1   (void);
	void doCase2   (void);
	void doDefault (void);

int main (void)
{
//	Local Definitions
	int printFlag;
	
//	Statements
	cout << "Please enter ...: ";
	cin  >> printFlag;
	
	switch (printFlag)
	   {
	    case 1:  cout << "do case 1\n";
	             doCase1 ();
	    case 2:  cout << "do case 2\n";
	             doCase2 ();
	    default: cout << "do default";
	             doDefault ();
	   }  // switch
	return 0 ;
} //  main


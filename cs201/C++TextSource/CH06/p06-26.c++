/*	Test driver for Towers of Hanoi
	   Written by:
	   Date:
*/
#include <iostream>
using namespace std;

//	Prototype Statements
	void towers (int n, char source, char dest, char auxiliary);
	
int main (void)
{
//	Local Declarations
	int numDisks;
	
//	Statements
	cout << "Please enter number of disks: ";
	cin  >> numDisks;
	
	cout << "Start Towers of Hanoi.\n\n";

	towers (numDisks, 'A', 'C', 'B');
	
	cout << "\nI Hope you didn't select 64 and end the world!\n";
	
	return 0;
}	// main

/*	Move one disk from source to destination through
	the use of recursion.
 	Pre   The tower consists of numDisks disks
 	      Source, destination, and auxiliary towers given
 	Post  Steps for moves printed 
*/
void towers (int  numDisks, char source,
             char dest,     char auxiliary)
{
	static int step = 0;

	cout << "Towers (" << numDisks  << ", "
	                   << source    << ", "
	                   << dest      << ", "
	                   << auxiliary << ")\n";
	if (numDisks == 1)
 	    cout << "\t\t\t\t\tStep "  << ++step 
 	         << ": Move from "     << source
 	         << " to "             << dest << endl;
	else
	    {
	     towers (numDisks - 1, source, auxiliary, dest);
 	     cout << "\t\t\t\t\tStep " << ++step 
 	          << ": Move from "    << source
 	          << " to "            << dest << endl;
	     towers (numDisks - 1, auxiliary, dest, source);
	    } // if � else
	return;
}	// towers 

/*
Results:
	Please enter number of disks: 3
	Start Towers of Hanoi.
	
	Towers (3, A, C, B)
	Towers (2, A, B, C)
	Towers (1, A, C, B)
	                    Step 1: Move from A to C
	                    Step 2: Move from A to B
	Towers (1, C, B, A)
	                    Step 3: Move from C to B
	                    Step 4: Move from A to C
	Towers (2, B, C, A)
	Towers (1, B, A, C)
	                    Step 5: Move from B to A
	                    Step 6: Move from B to C
	Towers (1, A, C, B)
	                    Step 7: Move from A to C
	
	I Hope you didn't select 64 and end the world!
*/

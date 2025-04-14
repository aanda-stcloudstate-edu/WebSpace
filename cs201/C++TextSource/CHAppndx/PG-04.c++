/*	PG-04.cp  Demonstrate multiple includes.
	   Written by:
	   Date:
*/
#include <iostream>
using namespace std;

#include "PG-05.h"    // Contains include for PG-06.h
#include "PG-06.h"

int main ()
{
	cout << "Begin mainline PG-04.cp\n";
	
	printMsgA ("mainline");
	printMsgB ("mainline");
	
	cout << "End mainline PG-04.cp\n";
	return 0;
}	// main

/*	Results:
Begin mainline PG-04.cp
**PG-05 called from: mainline
**PG-06 called from: PG-05
**PG-06 called from: mainline
End mainline PG-04.cp
*/

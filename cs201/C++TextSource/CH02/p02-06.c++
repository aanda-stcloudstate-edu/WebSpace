/*	Demonstrate fill character.
	   Written by:
	   Date:
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
	float  amount = 123.45;

	cout << "Demonstrate fill characters\n\n";
	
	cout << setw(10) << amount 
	     << "\tAmount with space fill\n";
	
	cout << setw(10) << setfill('*') << amount 
	     << "\tAmount with check protection fill\n";
	     
	cout << setw(10) << setfill(' ') << amount 
	     << "\tand again with space fill\n";
	
	return 0;
}  // main 

/*	Results:
Demonstrate fill characters

    123.45      Amount with space fill
****123.45      Amount with check protection fill
    123.45      and again with space fill

*/

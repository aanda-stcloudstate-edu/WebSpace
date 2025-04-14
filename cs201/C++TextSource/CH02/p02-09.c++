/*	Demonstrate the extraction operator.
	   Written by:
	   Date:
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
	char   aChar;
	int    integer;
	float  dlrAmnt;

	cout << "Please enter an integer, "
	     << "a dollar amount and a character.\n";
	cin >> integer >> dlrAmnt >> aChar;
	    
	cout << "\nThank you. You entered:\n";
	cout << setw(6)         << integer << "  "
	     << setfill('*')    << setprecision(2) << fixed
	     << '$' << setw(10) << dlrAmnt
	     << setfill(' ')    << setw(3) << aChar << endl;
	
	return 0;
}  // main 

/*	Results:
Please enter an integer, a dollar amount and a character.
12 123.45 G

Thank you. You entered:
    12  $****123.45  G

*/

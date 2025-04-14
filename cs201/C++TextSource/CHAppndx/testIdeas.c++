/*	Demonstrate use of declarations for multiple namespaces.
	   Written by:
	   Date
*/
#include <iostream>
using namespace std;

namespace numNames 
{
	int i;
	
	namespace shrt
	   {
	    short shJ;
	   } // namespace shrt

	namespace lng
	{
	  long lnK;
	}	// long namespace
}	// numNames namespace

//using purchasing::i;
//using purchasing::inventory::j;
using namespace numNames;

int main ()
{
	i = 5;
	cout << "numNames::i is:         " 
	     << numNames::i << endl;

	shrt::shJ = 12;
	cout << "numNames::shrt::shJ is: " 
	     << numNames::shrt::shJ << endl;
	
	using lng::lnK;
	lnK = 12345;
	cout << "numNames::shrt::lnK is: " 
	     << numNames::lng::lnK << endl;
	return 0 ;
}	// main

/*	Results:
numNames::i is:         5
numNames::shrt::shJ is: 12
numNames::shrt::lnK is: 12345
*/

/*	Results
Purchasing i is: 5
Inventory  j is: 12
*/

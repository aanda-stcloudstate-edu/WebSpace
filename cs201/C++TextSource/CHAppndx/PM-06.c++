/*	Demonstrate use of declarations for multiple namespaces.
	   Written by:
	   Date
*/
#include <iostream>
using namespace std;

namespace purchasing 
{
	int i;
	int j;
  // ...
}	// purchasing namespace

namespace inventory
{
  int i;
  int j;
  // ...
}	// inventory namespace

using purchasing::i;
using inventory::j;

int main ()
{
	i = 5 ;                                 // purchasing::i
	cout << "Purchasing i is: " << purchasing::i << endl;

	j = 12;                                 // inventory::j
	cout << "Inventory  j is: " << inventory::j << endl;
	return 0 ;
}	// main

/*	Results
Purchasing i is: 5
Inventory  j is: 12
*/

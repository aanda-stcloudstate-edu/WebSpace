/*	Scientific and fixed point flags
	   Written by:
	   Date:
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
	cout.setf   (ios::scientific); 
	cout << "...scientific format  : " << 3141.59 << endl;
	cout.unsetf (ios::scientific);

	cout.setf (ios::fixed);
	cout << "...with fixed point   : " << 3141.59 << endl;
	return 0;
}	// main

/*	Results
...scientific format  : 3.141590e+03
...with fixed point   : 3141.590000
*/

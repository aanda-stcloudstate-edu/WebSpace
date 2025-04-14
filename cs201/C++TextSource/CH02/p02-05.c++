/*	Demonstrate the use of the set width manipulator.
	   Written by:
	   Date:
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
	int    d123   = 123;
	float  f123   = 1.23;
	char   chA    = 'A';

	cout << "Demonstrate set width manipulator\n";
	
	cout << "0...0....1....1" << endl;
	cout << "1...5....0....5" << endl;
	cout << d123 << f123 << chA << "\t     | no width" << endl;
	cout << setw(1) << d123 
	     << setw(1) << f123 
	     << setw(1) << chA
	     << "\t     | width too small" << endl;
	cout << setw(5) << d123 
	     << setw(5) << f123 
	     << setw(5) << chA
	     << "\t | width 5 space each" << endl;
	cout << setw(10) << "Hello" 
	     << "\t     | string width 10" << endl;
	cout << setw(3) << "Hello" 
	     << "       \t | string width 3" << endl;
		
	return 0;
}  // main 

/*	Results:

Demonstrate set width manipulator
0...0....1....1
1...5....0....5
1231.23A         | no width
1231.23A         | width too small
  123 1.23    A  | width 5 space each
     Hello       | string width 10
Hello            | string width 3

*/

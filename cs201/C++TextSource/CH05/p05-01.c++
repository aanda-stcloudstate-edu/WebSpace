/*	Demonstrate the results of logical operators.
	   Written by:
	   Date:
*/
#include <iostream>
using namespace std;

int main ()
{
	cout << " 5 && -3 is: " << ( 5 && -3) << endl;
	cout << " 5 &&  0 is: " << ( 5 &&  0) << endl;
	cout << " 0 &&  5 is: " << ( 0 &&  5) << endl;
	cout << " 5 ||  0 is: " << ( 5 ||  0) << endl;
	cout << " 0 ||  5 is: " << ( 0 ||  5) << endl;
	cout << " 0 ||  0 is: " << ( 0 ||  0) << endl;
	cout << "!5 && !0 is: " << (!5 && !0) << endl;
	cout << "!5 && !0 is: " << (!5 && !0) << endl;
	cout << "!5 &&  0 is: " << (!5 &&  0) << endl;
	cout << " 5 && !0 is: " << ( 5 && !0) << endl;
	return 0;
}	// main 

/*	Results:

 5 && -3 is: 1
 5 &&  0 is: 0
 0 &&  5 is: 0
 5 ||  0 is: 1
 0 ||  5 is: 1
 0 ||  0 is: 0
!5 && !0 is: 0
!5 && !0 is: 0
!5 &&  0 is: 0
 5 && !0 is: 1

*/

/*	Test driver to verify dec5p2 manipulator
	Written by: 
	Date: 
*/
#include <iostream>
#include <iomanip>
using namespace std;

/*	Manipulator to print 5.2 floating-point numbers.
	   Pre  the file stream is open
	   Post width and precision flags set
*/
ostream& dec5p2 (ostream& fs)
{
 fs.setf      (ios :: fixed);
 fs.width     (5);
 fs.precision (2);
 return fs;
}	// ostream dec5p2

int main (void)
{
	float num = 452.323457;
	cout << "dec5p2 output: " << dec5p2 << num << endl;
	return 0;
}	// main 

/*	Results
dec5p2 output: 452.32
*/

/*	Deomonstrate three control variables.
	   Written by:
	   Date:
*/
#include <iostream>
#include <cstdlib>
using namespace std;
int main ()
{
	cout << "Test control variables\n";
	cout << "Print with default settings\n";
	cout << 'a' << 'B' << 'c' << endl;
	
	cout << "Print with width 10\n";
	cout.width (10);
	cout << 'a' << 'B' << 'c' << endl;
	
	cout << "\nTest fill character with * char\n";
	cout.width(5); cout.fill ('*');
	cout << 'a'; 
	cout.width(5); cout << 'B';
	cout.width(5); cout << 'c';
	
	cout << "\nResetting default fill char\n";
	cout.fill (' ');
	cout.width(5);
	cout << 'a' << 'B' << 'c' << endl;
	     
	cout << "\nTest precision\n";
	cout.setf (ios::fixed, ios::floatfield);
	cout << "Print without precision\n";
	cout  << 123.45678 << endl;

	cout << "Print with precision 0\n";
	cout.precision(0);
	cout  << 123.45678 << endl;

	cout << "Print with precision 3\n";
	cout.precision(3);
	cout  << 123.45678 << endl;

	cout << "Print without precision\n";
	cout  << 123.45678 << endl;
	return 0;
}	// main

/*	Results
Test control variables
Print with default settings
aBc
Print with width 10
         aBc

Test fill character with * char
****a****B****c
Resetting default fill char
    aBc

Test precision
Print without precision
123.456780
Print with precision 0
123
Print with precision 3
123.457
Print without precision
123.457
*/

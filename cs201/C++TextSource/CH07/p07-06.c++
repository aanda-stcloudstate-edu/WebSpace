/*	Demonstrate numeric flags.
	   Written by:
	   Date:
*/
#include <iostream>
using namespace std; 

int main ()
{
	cout << "\nNumbers with showbase and uppercase off\n";
	cout.setf (ios::dec, ios::basefield);
	cout << "93 as decimal     :";
	cout.width(5);
	cout << 93 << endl;
	cout.setf (ios::oct, ios::basefield);
	cout << "93 as octal       :";
	cout.width(5);
	cout << 93 << endl;
	cout.setf (ios::hex, ios::basefield);
	cout << "93 as hexadecimal :";
	cout.width(5);
	cout << 93 << endl;

	cout << "\nNumbers with showbase and uppercase on\n";
	cout.setf (ios::showbase);
	cout.setf (ios::dec, ios::basefield);
	cout << "93 as decimal     :";
	cout.width(5);
	cout << 93 << endl;
	cout.setf (ios::oct, ios::basefield);
	cout << "93 as octal       :" ;
	cout.width(5);
	cout << 93 << endl;
	cout.setf (ios::hex, ios::basefield);
	cout.setf (ios::uppercase);
	cout << "93 as upper hex   :";
	cout.width(5);
	cout << 93 << endl;
	cout.unsetf (ios::hex);          // reset to default
	cout.unsetf (ios::uppercase);    // reset to default
	cout.setf (ios::dec);            // reset to default
	return 0;
}	// main

/*	Results:
Numbers with showbase and uppercase off
93 as decimal     :   93
93 as octal       :  135
93 as hexadecimal :   5d

Numbers with showbase and uppercase on
93 as decimal     :   93
93 as octal       : 0135
93 as upper hex   : 0X5D
*/

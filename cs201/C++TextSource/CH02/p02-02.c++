/*	This program calculates and prints the sum of 
	three numbers input by the user at the keyboard.
	   Written by:
	   Date:
*/
#include <iostream>
using namespace std;

int  main  (void) 
{
	int  a;
	int  b;
	int  c;
	int  sum;

	 cout << "Welcome. This program adds\n";
	 cout << "three numbers. Enter three numbers\n";
	 cout << "in the form: nnn nnn nnn <return>\n";

	 cin >> a >> b >> c;

	 // Numbers are now in a, b, and c. Add them.
	 sum = a + b + c;

	 cout << "\nThe total is: " << sum << "\n";
	 cout << "\nThank you. Have a good day.\n";
	 return 0;
}	//  main  

/*	Results:
Welcome. This program adds
three numbers. Enter three numbers
in the form: nnn nnn nnn <return>
11 22 33

The total is: 66

Thank you. Have a good day.
*/
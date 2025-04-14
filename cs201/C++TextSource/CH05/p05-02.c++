/*	Demonstrates the results of relational operators.
	   Written by:
	   Date written:
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
	int a =  5;
	int b = -3;

	cout << setw(2) <<  a << " <  " 
	     << setw(2) <<  b << " is " 
	     << setw(2) << (a <  b) << endl;
	cout << setw(2) <<  a << " == "
	     << setw(2) <<  b << " is " 
	     << setw(2) << (a == b) << endl;
	cout << setw(2) <<  a << " != " 
	     << setw(2) <<  b << " is " 
	     << setw(2) << (a != b) << endl;
	cout << setw(2) <<  a << " >  " 
	     << setw(2) <<  b << " is " 
	     << setw(2) << (a >  b) << endl;
	cout << setw(2) <<  a << " <= " 
	     << setw(2) <<  b << " is " 
	     << setw(2) << (a <= b) << endl;
	cout << setw(2) <<  a << " >= " 
	     << setw(2) <<  b << " is " 
	     << setw(2) << (a >= b) << endl;
	return 0;
}	// main 

/*	Results:
  5 <  -3 is  0
  5 == -3 is  0
  5 != -3 is  1
  5 >  -3 is  1
  5 <= -3 is  0
  5 >= -3 is  1
*/

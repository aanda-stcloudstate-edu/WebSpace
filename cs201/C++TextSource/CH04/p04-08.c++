/*	This program reads two integers and then prints the 
	quotient and remainder of the first number divided
	by the second.
	   Written by:
	   Date: 
*/
#include <iostream>
#include <iomanip>
using namespace std;

//	Prototype Declarations
	void getData  (int& divnd, int& divsr);
	void divide   (int  divnd, int  divsr, 
	               int& quot,  int& rem);
	void print    (int  quot,  int  rem);

int main ()
{
	int a;
	int b;
	getData (a, b);

	int c;
	int d;
	divide  (a, b, c, d);
	print   (c, d);
	return 0;
}	// main
/*	=============== getData ===============
	This function reads two numbers into variables
	specified in the parameter list.
	   Pre    Nothing
	   Post   Data read and placed in calling function
*/
void getData (int& divnd, int& divsr)
{
	cout << "Enter two integers and return: ";
	cin  >> divnd >> divsr;
	return;
}	// getData
/*	=============== divide =============== 
	This function divides two integers and places the
	quotient/remainder in calling program variables.
	   Pre    dividend & divisor contain integer values
	   Post   quotient & remainder calc'd
*/
void divide (int  divnd, int  divsr,
             int& quot,  int& rem)
{
	quot   = divnd / divsr;
	rem    = divnd % divsr;
	return;
}	// divide
/*	====================== print ====================== 
	This function prints the quotient and the remainder.
	   Pre    quot contains the quotient
	          rem contains the remainder
	   Post   Quotient and remainder printed
*/
void print (int quot, int rem)
{
	cout << "Quotient : ";
	cout << setw(3) << quot << endl;
	cout << "Remainder: ";
	cout << setw(3) << rem << endl;
	return;
}	// print 

/*	Results
Enter two integers and return: 17 3
Quotient :   5
Remainder:   2
*/

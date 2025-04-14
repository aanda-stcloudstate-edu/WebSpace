/*	Test driver for program 7-15
	   Written by:
	   Date:
*/
#include <iostream>
#include <ctype>
using namespace std;

//	Prototype Statements
	int getUnitsSold (void);

int main (void)
{
//	Statements
	cout << "Start test driver\n";
	
	cout << "Units sold are: " << getUnitsSold () << endl;
	
	cout << "\nEnd of test driver\n";
	return 0;
}	// main

/*	This function reads the units sold from the keyboard and 
	verifies it with the user.
	   Pre  Nothing
	   Post Units Sold read, verified, and returned
*/
int getUnitsSold ()
{
	int  unitsSold;
	bool valid;
	char aCh;

	do
		{
		 cout << "\nPlease enter Number of Units Sold: ";
		 while (!(cin >> unitsSold))
		   {
		    cin.clear();
		    while (cin.get(aCh) && aCh != '\n')      //flush
		       ;
		    cout << "\aInvalid units. Re-enter: ";
		   } // while 
		 cout << "\nVerify Units Sold: " << unitsSold;
		 cout << "\n<Y> for correct: <N> for not correct: ";
	
		 while (cin.get(aCh) && aCh != '\n')         //flush
		       ;
		 cin.get(aCh);
		 if (toupper(aCh) == 'Y')
		    valid = true;
		 else
		    {
		     while (cin.get(aCh) && aCh != '\n')     //flush
		       ;
		     cout << "\nYou responded 'no.' ";
		     cout << "Please re-enter Units Sold\n";
		     valid = false;
		    }	 // else 
		} while (!valid);
	return unitsSold;
} // getUnitsSold 

/*	Results:

Start test driver

Please enter Number of Units Sold: a12
Invalid units. Re-enter: 14

Verify Units Sold: 14

<Y> for correct: <N> for not correct: n

You responded 'no.' Please re-enter Units Sold

Please enter Number of Units Sold: 12

Verify Units Sold: 12

<Y> for correct: <N> for not correct: y
Units sold are: 12

End of test driver
*/

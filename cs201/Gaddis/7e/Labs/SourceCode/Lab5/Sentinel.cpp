// This program illustrates the use of a sentinel in a while loop.
// The user is asked for monthly rainfall totals until a sentinel
// value of -1 is entered. Then the total rainfall is displayed

// PLACE YOUR NAME HERE

#include <iostream>
using namespace std;

int main()
{
	// Fill in the code to define and initialize to 1 the variable month 
	float total = 0, rain;

	cout << "Enter the total rainfall for month " << month << endl;
	cout << "Enter -1 when you are finished" << endl;
	// Fill in the code to read in the value for rain

	
	// Fill in the code to start a while loop that iterates 
	// while rain does not equal -1
	{
		// Fill in the code to update total by adding it to rain
		// Fill in the code to increment month by one
		
	    cout << "Enter the total rainfall in inches for month "
	         << month << endl;
		cout << "Enter -1 when you are finished" << endl;
		// Fill in the code to read in the value for rain
		
	}

	if (month == 1)
		cout << "No data has been entered" << endl;

	else
		cout << "The total rainfall for the " << month-1 
		     << " months is "<< total << " inches." << endl;

	
   return 0;	
}
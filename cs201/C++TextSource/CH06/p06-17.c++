//	P06-17 continue example

/*	This program tests the readAverage functions that
	demonstrate the continue statement. Change the call
	in the third statement to call either readAverage 1 or 2.
	   Written by:
	   Date:
*/

#include <iostream>
#include <iomanip>
using namespace std;

float readAverage1 (void);
float readAverage2 (void);
	
int main (void)
{
	cout << fixed << showpoint << setprecision(2);
	cout << "Enter numbers to average <EOF to stop>:\n";
	
	// Modify call in next statement to execute on or the other average
	cout << "The average is: " << setw(2) << readAverage1 () << endl;

	return 0;
}	// main 

// ========== readAverage with Continue ========== 
float readAverage1 (void)
{
int count = 0;

int   n;
float sum = 0;

while(cin >> n)
	{
	 if (n == 0)
	    continue;
	 sum   += n;
	 count ++;

	} // while
return (sum / count);
}	// readAverage

// ========== readAverage withOUT Continue ========== 
float readAverage2 (void)
{
	int count = 0;

	int   n;
	float sum = 0;

	while(cin >> n)
	     {
	    if (n != 0)
	       {
	        sum += n;
	        count++;
	       } // if
	      } // while 
return (sum / count);
}	// readAverage

/*
Results (Two runs):
 1. Run with continue (readAverage1)
	Enter numbers to average <EOF to stop>:
	1 2 3 4 5 6
	The average is: 3.50
	
 2. Run without continue (readAverage2)
	Enter numbers to average <EOF to stop>:
	1 2 3 4 5 6
	The average is: 3.50
*/

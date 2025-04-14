/*	Simple while loop that prints numbers 10 per line.
	   Written by:
	   Date: 
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
	cout << "Enter an integer between 1 and 100: ";
	int num;
	cin  >>  num;
	
	// Test number 
	if (num > 100)
	    num = 100;
	    
	int lineCount = 0;
	while (num > 0)
	   {
	    if (lineCount < 10)
	        lineCount++;
	    else
	       {
	        cout << endl;
	        lineCount = 1;
	       } // else 
	    cout << setw(4) << num--;
	   } // while 
	return 0;
}	// main 

/* Results:
Enter an integer between 1 and 100: 15
  15  14  13  12  11  10   9   8   7   6
   5   4   3   2   1
*/

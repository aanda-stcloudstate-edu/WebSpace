/*	Read a number series and print it reversed.
	   Written by: 
	   Date: 
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
	int numbers[50];

	cout << "You may enter up to 50 integers:\n";
	cout << "How many would you like to enter? ";
	int readNum;
	cin  >> readNum;
	
	if (readNum > 50)
	    readNum = 50;
	
	// Fill the array 
	cout << "\nEnter your numbers: \n";
	for (int i = 0; i < readNum; i++)
	     cin >> numbers[i];
	     
	// Print the array 
	cout << "\nYour numbers reversed are: \n";
	int numPrinted = 0;
	for (int i = readNum - 1; i >= 0; i--) 
	   {
	    cout << setw(3) << numbers[i];
	    if (numPrinted < 9)
	        numPrinted++;
	    else
	       {
	        printf("\n");
	        numPrinted = 0;
	       } // else 
	   } // for 
	return 0;
}	// main 

/*	Results:

You may enter up to 50 integers:
How many would you like to enter? 12

Enter your numbers: 
1 2 3 4 5 6 7 8 9 10 11 12

Your numbers reversed are: 
 12 11 10  9  8  7  6  5  4  3
  2  1

*/

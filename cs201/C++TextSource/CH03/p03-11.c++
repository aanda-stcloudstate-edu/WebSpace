/*	Calculate the average of four integers and print
	the numbers and their deviation from the average.
	   Written by:
	   Date:
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
	cout << "\nEnter the first number  : ";
	int num1;
	cin  >> num1;
	cout << "Enter the second number : ";
	int num2;
	cin  >> num2;
	cout << "Enter the third  number : ";
	int num3;
	cin  >> num3;
	cout << "Enter the fourth number : ";
	int num4;
	cin  >> num4;

	int   sum     = num1 + num2 + num3 + num4;
	float average = sum / 4.0;
	cout << fixed;
	cout << showpoint;
	cout << setprecision (2);
	cout << "\n ******** average is " 
	     << average << " ******** \n";
	cout << "\nfirst no:  " << num1 << " -- deviation: " 
	     << setw(8) << (num1 - average);
	cout << "\nsecond no: " << num2 << " -- deviation: " 
	     << setw(8) << (num2 - average);
	cout << "\nthird no:  " << num3 << " -- deviation: " 
	     << setw(8) << (num3 - average); 
	cout << "\nfourth no: " << num4 << " -- deviation: " 
	     << setw(8) << (num4 - average);    
	return 0;
}	// main 

/*	Results:

Enter the first number  : 23
Enter the second number : 12
Enter the third number  : 45
Enter the fourth number : 23

 ******** average is 25.75 ********

first no:  23 -- deviation:    -2.75
second no: 12 -- deviation:   -13.75
third no:  45 -- deviation:    19.25
fourth no: 23 -- deviation:    -2.75

*/

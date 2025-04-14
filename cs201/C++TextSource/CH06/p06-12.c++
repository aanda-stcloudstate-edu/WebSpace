/*	Test driver for function to print a calendar month.
	   Written by:
	   Date: 
*/
#include <iostream>
#include <iomanip>
using namespace std;

void printMonth (int startDay, int days);

int main ()
{
	printMonth (2, 29);              // Day 2 is Tuesday
	return 0;
}	// main 

/*	================= printMonth =================
	Print one calendar month.
	   Pre   startDay is day of week relative 
	            to Sunday (0)
	         days is number of days in month
	   Post  Calendar printed
*/
void printMonth (int startDay, int days)
{
	// print day header 
	cout << "Sun Mon Tue Wed Thu Fri Sat\n";
	cout << "--- --- --- --- --- --- ---\n";
	
	// position first day 
	for (int skipDay = 0; skipDay < startDay; skipDay++)
	    cout << "    ";
	    
	int weekDay = startDay;
	for (int dayCount = 1; dayCount <= days; dayCount++)
	    {
	     if (weekDay > 6)
	        {
	         cout << endl;
	         weekDay = 1;
	        } // if 
	     else
	         weekDay++;
	     cout << setw(3) << dayCount << " ";
	    } // for 
	cout << "\n--- --- --- --- --- --- ---\n";
	return;
}	// printMonth 
 
/* Results:
Sun Mon Tue Wed Thu Fri Sat
--- --- --- --- --- --- ---
          1   2   3   4   5 
  6   7   8   9  10  11  12 
 13  14  15  16  17  18  19 
 20  21  22  23  24  25  26 
 27  28  29 
--- --- --- --- --- --- ---
*/

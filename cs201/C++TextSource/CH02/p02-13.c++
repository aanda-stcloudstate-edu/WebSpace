/*	This program prints four lines of Inventory data 
	on an Inventory report to give the user an idea of 
	what a new report will look like. Since this is 
	not a real report, no input is required. The data 
	are all specified as constants.
	   Written by:
	   Date:
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
	// Print captions 
	cout <<  "\tPart Number\tQty On Hand";
	cout <<  "\tQty On Order\tPrice\n";
	// Print data 
	cout   << fixed   << setprecision(2); 
	cout   << "\t  "  << setfill('0')
	       << setw(6) << 31235   << "\t"
	       << setfill(' ')
	       << setw(7) <<    22   << "\t\t"
	       << setw(7) <<    86   << "\t\t"
	       << '$'     << setw(7) <<  45.62  << endl;
	cout   << "\t  "  << setfill('0') 
	       << setw(6) <<   321    << "\t"
	       << setfill(' ')
	       << setw(7) <<    55    << "\t\t"
	       << setw(7) <<    21    << "\t\t"
	       << '$'     << setw(7)  <<  122.   << endl;
	cout   << "\t  "  << setfill('0') 
	       << setw(6) << 28764    << "\t"
	       << setfill(' ')
	       << setw(7) <<     0    << "\t\t"
	       << setw(7) <<    24    << "\t\t"
	       << '$'     << setw(7)  <<  .75    << endl;
	cout   << "\t  "  << setfill('0') 
	       << setw(6) <<  3232    << "\t"
	       << setfill(' ')
	       << setw(7) <<    12    << "\t\t"
	       << setw(7) <<     0    << "\t\t"
	       << '$'     << setw(7)  <<  10.91  << endl;
	// Print end message 
	cout << "\n\tEnd of Report\n";
	return 0;
}	// main 

/*	Results

    Part Number Qty On Hand Qty On Order    Price
      031235         22          86     $  45.62
      000321         55          21     $ 122.00
      028764          0          24     $   0.75
      003232         12           0     $  10.91

    End of Report
*/

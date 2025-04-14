/*	Test for open and close errors.
	   Written by:
	   Date:
*/
#include <iostream>
#include <fstream>
using namespace std;

int main (void)
{
	cout << "Start open/close error test\n";
	ifstream fsDailyTemps;
	fsDailyTemps.open ("ch7TEMPS.DAT");
	if (!fsDailyTemps)
	   {
	    cerr << "\aERROR 100 opening ch7TEMPS.DAT\n";
	    exit (100);
	   } // if open
//	 É 
	fsDailyTemps.close();
	if (fsDailyTemps.fail())
	   {
	    cerr << "\aERROR 102 closing ch7TEMPS.DAT\n";
	    exit (102);
	   } // if close
	cout << "End open/close error test\n";
	return 0;
}	// main 

/*	Results:
Without file:
	Start open/close error test
	ERROR 100 opening ch7TEMPS.DAT

With file:
	Start open/close error test
	End open/close error test
*/

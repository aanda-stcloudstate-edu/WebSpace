/*	This program copies one text file into another.
	   Written by:
	   Date:
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main () 
{
	ifstream fsInFile;
	ofstream fsOutFile;
	cout << "Begin file copy\n";
	
	fsInFile.open ("ch7FILE9.DAT");
	if (!fsInFile)
		{
	     cerr << "\aError 100 opening ch7FILE9.DAT\n";
	     exit (100);
	    }  // if 
	fsOutFile.open ("ch7FILE10.DAT");
	if (!fsOutFile)
	    {
	     cerr << "\aError 102 opening ch7FILE10.DAT\n";
	     exit (102);
	    }  // if

	char     aChar;
	while (fsInFile.get  (aChar))
	       fsOutFile.put (aChar);

	fsInFile.close  ();
	fsOutFile.close ();
	
	cout << "\nEnd file copy\n";
	return 0;
}	// main 

/*	Results
Begin file copy

End file copy

Input:
Now is the time
For all good students
To come to the aid
Of their college.

Anonymous

Output:
Now is the time
For all good students
To come to the aid
Of their college.

Anonymous
*/

/* This program creates a text file. 
	   Written by:
	   Date:
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
int main ()
{
	ofstream sfTextFile;
	cout << "Begin file creation\n";
	sfTextFile.open ("ch7FILE9.DAT");
	if (!sfTextFile)
	   {
	    cerr << "Error 100 opening output FILE9.DAT";
	    exit (100);
	   } // if

	char     aChar;
	while (cin.get(aChar))
	   sfTextFile.put (aChar);

	sfTextFile.close ();
	cout << "\nEnd file creation\n";
	
	return 0;
}	// main 

/*	Results
Begin file creation
Now is the time
For all good students
To come to the aid
Of their college.

Anonymous
^d
End file creation

Output:
Now is the time
For all good students
To come to the aid
Of their college.

Anonymous
*/

/*	This program counts the number of characters and
	lines in a text file.
	   Written by:
	   Date:
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;
int main ()
{

	ifstream fsInFile;
	fsInFile.open ("ch7FILE9.DAT");
	if (!fsInFile)
	   {
	    cerr << "Error 100 opening ch7FILE9.DAT";
	    exit (100);
	   } // if

	char curCh;
	char preCh;
	int  countLn = 0;
	int  countCh = 0;
	while (fsInFile.get (curCh))
	   {
	    if (curCh != '\n')
	        countCh++;
	    else
	        countLn++;
	    preCh = curCh;
	   }  // while

	if (preCh != '\n')
	   countLn++;

	cout << "\nNumber of characters: " 
	     << setw(4) << countCh;
	cout << "\nNumber of lines     : " 
	     << setw(4) << countLn;

	fsInFile.close ();

	return 0;
}  // main 

/*	Results

Number of characters: 80
Number of lines     :  6

Input:
Now is the time
For all good students
To come to the aid
Of their college.

Anonymous
*/

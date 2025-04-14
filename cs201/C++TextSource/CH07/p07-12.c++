/*	Count number of words in file. Words are separated by 
	whitespace characters: space, tab, and newline.
	   Written by:
	   Date:
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

#define WHT_SPC (cur == ' ' || cur == '\n' || cur == '\t')

int main ()
{
	ifstream fsInFile;
	fsInFile.open ("ch7FILE9.DAT");
	if (!fsInFile)
		{
		 cerr << "Error 100 opening ch7FILE9.DAT";
		 exit (100);
		} // if

	char cur;
	char word    = 'O';       // O out of word: I in word
	int  countWd = 0;
	while (fsInFile.get (cur))
		{
		if (WHT_SPC)
			word = 'O';
		else
			if (word == 'O')
				{
				 countWd++;
				 word = 'I';
				} // if
		} // while

	cout << "\nThe number of words is " << countWd;
	fsInFile.close ();
	return 0;
}	// main 

/*	Results

The number of words is 17

Input:
Now is the time
For all good students
To come to the aid
Of their college.

Anonymous
*/

/*	This program appends two binary files of integers.
	   Written by:
	   Date:
*/
#include <iostream>
#include <fstream>
using namespace std;

int main (int   argc, char* argv[])
{
	cout << "\nThis program appends two files.\n";
	if (argc != 3) 
	   {
	    printf("\aTwo file names required\n"); 
	     exit(100);
	   } // if

	ofstream fsAp;
	fsAp.open (argv[1], ios::out | ios::app | ios::binary);
	if (!fsAp)
	   {
	    cout << "\aCanÕt open " << argv[1] << endl;
	    exit (100);
	   } // if
	   
	// Position primary file at end
	fsAp.seekp (0, ios::end);

	ifstream fsIn;
	fsIn.open (argv[2],  ios::in | ios:: binary);
	if (!fsIn)
	   {
	    cout << "\aCanÕt open " << argv[2] << endl;
	    exit (110);
	   } // if file at end
	   
	long apndCnt = 0;
	int       data;
	while (fsIn.read ((char *)&data, sizeof(int)))
	   {
	    fsAp.write ((char *)&data, sizeof(int));
	    apndCnt++;
	   } // while 
	   
	// Test for read failure rather than eof
	if (!fsIn.eof())
	   {
	    cout << "\aRead Error 120. No output.\n"; 
	    exit (120);
	   } // if
	fsAp.close ();
	fsIn.close ();

	cout << "Append complete:  "
	     << apndCnt << " appended to file\n";
	return 0;
} // main 

/*	Results

This program appends two files.
Two file names required
*/

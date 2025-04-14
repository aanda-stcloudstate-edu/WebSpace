/*	Test handling errors
	   Written by:
	   Date:
*/
#include <iostream>
#include <cstdlib>
using namespace std;

int main ()
{
	int badRead;
	int unitsSold;
	cout << "\nPlease enter Number of Units Sold: ";
	do
	   {
	    badRead = 0;
	    cin >> unitsSold;
	    if ( !(cin.good() ) )
	       {
	        // number not read correctly
	        cerr << "\a\nInvalid number. ";
	        cerr << "Error status is " << hex  
	             <<  cin.rdstate() << dec << endl;
	        if (cin.eof())
	           {
	            cerr << "End of file detected.\n"
	                 << "You must restart program\n";
	            exit (200);
	           } // if eof
	        else if (cin.fail())
	           {
	            cerr << "Only digits (0..9) allowed\n"
	                 << "Please try again: ";
	            badRead = 1;
	            
	            // Clear error & Flush invalid characters
	            cin.clear();
	            char aCh;
	            while ( (aCh = cin.get ()) != '\n' )
	               ;
	           } // if fail
	        else if (cin.bad())
	           {
	            cerr << "Keyboard is not working.\n";
	            exit (201);
	           } // bad transmission
	        else
	           {
	            cerr << "Hard Error. Call programmer.\n";
	            exit (202);
	           } // Program error
	       }  // if
	   } while (badRead);
	
	cout << "You entered " << unitsSold << endl;
	   
	return 0;
}	// main 

/*	Results:
First Test
Please enter Number of Units Sold: a12

Invalid number. Error status is 4
Only digits (0..9) allowed
Please try again: 12
You entered 12

Second Test
Results:
Please enter Number of Units Sold: a12

Invalid number. Error status is 4
Only digits (0..9) allowed
Please try again: ^d
Invalid number. Error status is 6
End of file detected.
You must restart program
*/

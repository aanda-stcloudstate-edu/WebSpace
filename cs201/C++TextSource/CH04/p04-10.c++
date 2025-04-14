/*	Demonstrates the use of srand to generate random numbers 
	in different series. The user is asked to input a seed, and 
	the program then generates four random numbers. The process  
	is repeated three times.
	   Written by:
	   Date:
*/
#include <iostream>
#include <cstdlib>
using namespace std;

int main ()
{
	cout << "Enter random number seed:  ";
	int seed;
	cin  >> seed;
	srand ( seed );

	cout << "Random numbers with seed   " << seed << ": "
	     << rand () << " " << rand () << " "
	     << rand () << " " << rand ()  << endl << endl;
	
	cout << "Enter another random seed:  ";
	cin  >> seed;
	srand ( seed );

	cout << "Random numbers with seed   " << seed << ": "
	     << rand () << " " << rand () << " "
	     << rand () << " " << rand ()  << endl << endl;
	
	cout << "Enter another random seed:  ";
	cin  >> seed;
	srand ( seed );

	cout << "Random numbers with seed   " << seed << ": "
	     << rand () << " " << rand () << " "
	     << rand () << " " << rand ()  << endl << endl;
	
	cout << "Hope you found these numbers interesting.\n";
	return 0;
}	// main 

/*	Results

Enter random number seed:  255
Random numbers with seed   255: 28381 9283 13267 1160

Enter another random seed: 511
Random numbers with seed   511: 30044 8703 22126 19158

Enter another random seed: 997
Random numbers with seed   997: 21937 4276 22303 10575

Hope you found these numbers interesting.

*/

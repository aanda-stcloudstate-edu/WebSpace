/*	This program prints out a Fibonacci series.
	   Written by:
	   Date:
*/
#include <iostream>
#include <iomanip>
using namespace std;

long fib (long num);

int main ()
{
	cout << "This program prints a Fibonacci series.\n";
	cout << "How many numbers do you want? ";
	int seriesSize;
	cin  >> seriesSize;
	if (seriesSize < 2)
	    seriesSize = 2;

	cout << "First " << seriesSize 
	     << " Fibonacci numbers:\n";
	for (int looper = 0; looper < seriesSize; looper++)
	    {
	     if (looper % 5)
	         cout << ", " << setw(8) << fib (looper);
	     else
	         cout << endl << setw(8) << fib (looper);
	    } // for
	    
	cout << endl;
	return 0;
}	// main 
/*	================= fib ================= 
	Calculates the nth Fibonacci number. 
	   Pre   num identifies Fibonacci number
	   Post  returns nth Fibonacci number
*/
long fib (long num)
{
	if (num == 0 || num == 1)
		// Base Case
		return num;
	
	return fib  (num - 1) + fib (num - 2);
}	// fib

/* Results:
This program prints a Fibonacci series.
How many numbers do you want? 33
First 33 Fibonacci numbers:

       0,        1,        1,        2,        3
       5,        8,       13,       21,       34
      55,       89,      144,      233,      377
     610,      987,     1597,     2584,     4181
    6765,    10946,    17711,    28657,    46368
   75025,   121393,   196418,   317811,   514229
   832040,  1346269,  2178309
*/

//	PG-02.cp  Driver for Debug example

#include <iostream>
using namespace std;

#define DEBUG 1
#define PRINT_INT(a) \
	cout << "Variable '" #a "' contains: " << a << endl

int main ()
{
	int	 totalScore = 0;
	
#if (DEBUG)
	PRINT_INT (totalScore);
#endif
	return 0;
}	// main

/*	Results when DEGUG contains 1

	Variable 'totalScore' contains: 0
*/

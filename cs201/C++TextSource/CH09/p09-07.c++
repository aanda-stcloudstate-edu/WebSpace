/*	Demonstrate size of pointers.
	   Written by:
	   Date:
*/
#include <iostream>
using namespace std;

int main ()
{
	char  c;
	char* pc;
	int   sizeofc      = sizeof(c);
	int   sizeofpc     = sizeof(pc);
	int   sizeofStarpc = sizeof(*pc);
	
	int  a;
	int* pa;
	int  sizeofa       = sizeof(a);
	int  sizeofpa      = sizeof(pa);
	int  sizeofStarpa  = sizeof(*pa);
	
	double  x;
	double* px;
	int     sizeofx      = sizeof(x);
	int     sizeofpx     = sizeof(px);
	int     sizeofStarpx = sizeof(*px);

	cout << "sizeof(c): "   << sizeofc      << " | ";
	cout << "sizeof(pc): "  << sizeofpc     << " | ";
	cout << "sizeof(*pc): " << sizeofStarpc << endl;
		
	cout << "sizeof(a): "   << sizeofa      << " | ";
	cout << "sizeof(pa): "  << sizeofpa     << " | ";
	cout << "sizeof(*pa): " << sizeofStarpa << endl;

	cout << "sizeof(x): "   << sizeofx      << " | ";
	cout << "sizeof(px): "  << sizeofpx     << " | ";
	cout << "sizeof(*px): " << sizeofStarpx << endl;

	return 0;
}	// main 

/*	Results:

sizeof(c): 1 | sizeof(pc): 4 | sizeof(*pc): 1
sizeof(a): 4 | sizeof(pa): 4 | sizeof(*pa): 4
sizeof(x): 8 | sizeof(px): 4 | sizeof(*px): 8

*/

/*	Fun with pointers 
	   Written by: 
	   Date: 
*/
#include <iostream>
using namespace std;

int main ()
{
	int  a = 6;
	int  b = 2;
	int  c;
	int* p = &b;
	int* q;
	int* r;

	q = p;
	r = &c;


	p  = &a;
	*q = 8;
	*r = *p;


	*r = a + *q + *&c;

	cout << a << " " << b 
	     << " " << c << endl; 
	cout << *p  << " " << *q  
	     << " " << *r  << endl;
	return 0;
}	// main

/*	Results:
6 8 20 
6 8 20
*/

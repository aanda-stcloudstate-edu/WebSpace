/*	This program calculates the area and circumference 
	of a circle.
	   Written by: 
	   Date: 
*/
#include <iostream> 
using namespace std;

int main ()
{
	float circ;
	float area;
	float radius;

	cout << "\nPlease enter the value of the radius: ";
	cin  >> radius;

	circ  = 2  * 3.1416 * radius;
	area  = 3.1416 * radius * radius;

	cout << "\nRadius is :        " << radius;
	cout << "\nCircumference is : " << circ;
	cout << "\nArea is :          " << area;

	return 0;
}	// main 

/*	Results:

Please enter the value of the radius: 23
Radius is :              23
Circumference is :       144.514
Area is:                 1661.91

*/

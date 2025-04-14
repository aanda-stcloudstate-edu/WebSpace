/*	This program shows how to change a temperature in 
	Fahrenheit to Celsius.
	   Written by:
	   Date:
*/
#include <iostream>
#include <iomanip>
using namespace std;

const float cConversionFactor = 100.0 / 180.0;

int main ()
{
	cout << "Enter the temperature in Fahrenheit: ";
	float fareh;
	cin  >> fareh;
	float cel =  cConversionFactor * ( fareh - 32 );
	
	cout << fixed;
	cout << setprecision(1);
	cout << showpoint;
	cout << "Fahrenheit temperature: " << fareh << endl;
	cout << "Celsius temperature:    " << cel   << endl;
	return 0;
}	// main 

/*	Results:
Enter the temperature in Fahrenheit: 98.6
Fahrenheit temperature: 98.6
Celsius temperature:    37.0
*/

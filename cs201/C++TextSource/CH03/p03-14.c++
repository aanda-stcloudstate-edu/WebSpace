/*	Calculates the total sale given the unit price, 
	quantity, discount, and tax rate.
	   Written by:
	   Date written:
*/
#include <iostream>
#include <iomanip>
using namespace std;

const float cTaxRate = 8.50;

int main ()
{
	cout << "\nEnter number of items sold:        ";
	int  quantity;
	cin  >> quantity;
	cout << "Enter the unit price:              ";
	float unitPrice;
	cin  >> unitPrice;
	cout <<  "Enter the discount rate (percent): ";
	float discountRate; 
	cin  >>  discountRate;

	float subTotal    = quantity   * unitPrice;
	float discountAm  = subTotal   * discountRate / 100.0;
	float subTaxable  = subTotal   - discountAm;
	float taxAm       = subTaxable * cTaxRate     / 100.0;
	float total       = subTaxable + taxAm;
	
	cout << fixed;
	cout << setprecision(2);
	cout << showpoint;
	
	cout << "\nQuantity sold:       " 
	     << setw(6) << quantity   << endl;
	cout << "Unit Price of items: " 
	     << setw(9) << unitPrice  << endl;
	cout << "                       --------\n";
	cout << "Subtotal :           " 
	     << setw(9) << subTotal   << endl;
	cout << "Discount:           -" 
	     << setw(9) << discountAm << endl;
	cout << "Discounted total:    " 
	     << setw(9) << subTaxable << endl;
	cout << "Sales tax:          +" 
	     << setw(9) << taxAm      << endl;
	cout << "Total sale:          " 
	     << setw(9) << total      << endl;
	return 0;
}	// main 

/*	Results:

Enter number of items sold:        34
Enter the unit price:              12.89
Enter the discount rate (percent): 7

Quantity sold:           34
Unit Price of items:     12.89
                       --------
Subtotal :              438.26
Discount:           -    30.68
Discounted total:       407.58
Sales tax:          +    34.64
Total sale:             442.23

*/

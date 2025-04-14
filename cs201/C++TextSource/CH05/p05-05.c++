/*	Calculate the tax due or the refund for a family based
	on the following imaginary formula.
	1. For each dependent, deduct $1,000 from income.
	2. Determine tax rate from the following brackets:
	   bracket taxable income       tax rate
	      1          < 10001            2%
	      2            10001-20000      5%
	      3            20001-30000      7%
	      4            30001-50000     10%
	      5          > 50001           15%
	Then print the amount of tax or the refund.
	
	   Written by:
	   Date:
*/
#include <iostream>
#include <iomanip>
using namespace std;

const double LOWEST  = 0000000.00;
const double HIGHEST = 1000000.00;

const double LIMIT1  = 10000.00;
const double LIMIT2  = 20000.00;
const double LIMIT3  = 30000.00;
const double LIMIT4  = 50000.00;

const double RATE1   = 02;
const double RATE2   = 05;
const double RATE3   = 07;
const double RATE4   = 10;
const double RATE5   = 15;

const double DEDN_PER_DPNDNT = 1000.00;

void getData   (double& totalIncome,  double& taxPaid,
                int&    numOfDpndnts);

void calcTaxes (double  totalIncome,  double  taxPaid,
                int     numOfDpndnts, double& taxableInc,
                double& totalTax,     double& taxDue);

void printInfo (double totalIncome,  double taxableInc,
                int    numOfDpndnts, double totalTax,
                double taxPaid,      double taxDue);

double bracketTax (double taxableInc, double startLimit,
                   double stopLimit,  int    rate);

int main ()
{
	int    numOfDpndnts;
	double taxDue;
	double taxPaid;
	double totalIncome;
	double taxableInc;
	double totalTax;

	getData   (totalIncome,   taxPaid,  numOfDpndnts);
	calcTaxes (totalIncome,   taxPaid,  numOfDpndnts,
	           taxableInc,    totalTax, taxDue);
	printInfo (totalIncome,   taxableInc,
	           numOfDpndnts,  totalTax,
	           taxPaid,       taxDue);
	return 0;
}	// main

/*	===================== getData ======================
	This function reads tax data from the keyboard.
	   Pre    Nothing
	   Post   totalIncome, taxPaid, & numOfDpndnts read
*/
void getData (double& totalIncome,  double& taxPaid,
              int&    numOfDpndnts)
{
	cout << "Enter your total income for last year: ";
	cin  >> totalIncome;

	cout << "Enter total of payroll deductions:     ";
	cin  >> taxPaid;

	cout << "Enter the number of dependents:        ";
	cin  >> numOfDpndnts;
	return;
}// getData
/*	===================== calcTaxes ======================
	This function calculates the taxes due.
	   Pre    Given-income, numOfDpndnts, & taxPaid
	   Post   taxableInc, totTax, taxDue, calculated and 
	          returned by reference
*/
void calcTaxes (double  totalIncome,  double  taxPaid,
                int     numOfDpndnts, double& taxableInc,
                double& totalTax,     double& taxDue)
{
	taxableInc = 
	     totalIncome - (numOfDpndnts * DEDN_PER_DPNDNT);

	totalTax = 
	     bracketTax (taxableInc, LOWEST, LIMIT1, RATE1)
	   + bracketTax (taxableInc, LIMIT1, LIMIT2, RATE2)
	   + bracketTax (taxableInc, LIMIT2, LIMIT3, RATE3)
	   + bracketTax (taxableInc, LIMIT3, LIMIT4, RATE4)
	   + bracketTax (taxableInc, LIMIT4, HIGHEST, RATE5);

	taxDue = totalTax - taxPaid;
	return;
}// calcTaxes
/*	====================== printInfo =====================
	This function prints a table showing all information.
	   Pre    The parameter list
	   Post   Prints the table
*/
void printInfo (double totalIncome,  double taxableInc,
                int    numOfDpndnts, double totalTax,
                double taxPaid,      double taxDue)
{
	cout << fixed << showpoint << setprecision(2);
	cout << "\nTotal income           : " 
	     << setw(10) << totalIncome;
	cout << "\nNumber of dependents   : " 
	     << setw( 7) << numOfDpndnts;
	cout << "\nTaxable income         : " 
	     << setw(10) << taxableInc;
	cout << "\nTotal tax              : " 
	     << setw(10) << totalTax;
	cout << "\nTax already paid       : " 
	     << setw(10) << taxPaid;

	if (taxDue > 0.0)
	    cout << "\nTax due                : " 
	         << setw(10) << taxDue;
	else
	    cout << "\nRefund                 : " 
	         << setw(10) << -taxDue;
	return;
}	// printInfo
/*	===================== bracketTax =====================
	Calculates the tax for a particular bracket.
	   Pre    The taxableInc
	   Post   Returns the tax for a particular bracket
*/
double bracketTax (double taxableInc, double startLimit,
                   double stopLimit,  int    rate)
{
	double tax;

	if (taxableInc <= startLimit)
	   tax = 0.0;
	else
	   if (taxableInc > startLimit 
	      && taxableInc <= stopLimit)
	      tax = (taxableInc - startLimit) * rate / 100.00;
	   else
	      tax = (stopLimit  - startLimit) * rate / 100.00;

	return tax;
}	// bracketTax

/*	Results

Enter your total income for last year: 80000
Enter total of payroll deductions:     5000
Enter the number of dependents:        4

Total income           :   80000.00
Number of dependents   :       4
Taxable income         :   76000.00
Total tax              :    7300.00
Tax already paid       :    5000.00
Tax due                :    2300.00

*/

/*	This program prints the tuition at Strange College. 
	Strange charges $10 for registration, plus $10 per 
	unit and a penalty of $50 for each 12 units, or
	fraction of 12, over 12. 
	   Written by:
	   Date:
*/
#include <iostream>
using namespace std;

const int regFee    = 10;
const int unitFee   = 10;
const int excessFee = 50;
	
//	Prototype Declarations
int calculateFee (int firstTerm, 
                  int secondTerm,
                  int thirdTerm);
int termFee (int units);
	
int main ()
{
	
	cout << "Enter units for first term:  ";
	int  firstTerm;
	cin  >> firstTerm;
	
	cout << "Enter units for second term: ";
	int  secondTerm;
	cin  >> secondTerm;
	
	cout << "Enter units for third term:  ";
	int  thirdTerm;
	cin  >> thirdTerm;
	
	int  totalFee;
	totalFee = calculateFee 
                 (firstTerm, secondTerm, thirdTerm);
	cout << "\nThe total tuition is :\t" << totalFee;
	
	return 0;
}	// main 
/*	================ calculateFee ================
	Calculate the total fees for the year.
	   Pre  The number of units to be taken each term
	   Post Returns the annual fees
*/
int calculateFee (int firstTerm,
                  int secondTerm,
                  int thirdTerm)
{
	int fee = termFee (firstTerm)
	        + termFee (secondTerm)
	        + termFee (thirdTerm);
	return fee;
}	// calculateFee
	
/*	================== termFee ================== 
	Calculate the tuition for one term. 
	   Pre   units contains units to be taken in the term
	   Post  The fee is calculated and returned
*/
int termFee (int units)
{
	int totalFees = regFee
	          + ((units - 1) / 12 * excessFee)
	          +  (units * unitFee);
	return (totalFees);
}	// termFee

/*	Results:
Enter units for first term:  10
Enter units for second term: 20
Enter units for third term:  30

The total tuition is :  780
*/

/*	************************** NOTE ************************
*	The previously written add, subtract, multiply, and    *
*	divide functions have been added to this program.      *
*	********************************************************
*/
/*	This program adds, subtracts, multiplies, and divides
	two integers.
	   Written by:
	   Date:
*/
#include <iostream>
#include <iomanip>
using namespace std;

int   getOption  (void);
float add        (float num1,   float num2);
float sub        (float num1,   float num2);
float mul        (float num1,   float num2);
float dvd        (float num1,   float num2);
void printResult (float num1,   float num2,
                  float result, int   option);

int main ()
{
	int option;

	do 
	   {
	    option = getOption ();
	    if (option != 5)
	       {
	        float num1;
	        float num2;
	        float result;

	        do
	           {
	            cout << "\n\nEnter two numbers: ";
	            cin  >> num1 >> num2;
	            if (option == 4 && num2 == 0)
	               {
	                cout << "\a\n *** Error *** Second";
	                cout << " number cannot be 0!\n";
	               }  // if
	           } while (option == 4 && num2 == 0);
	           
	        switch (option)
	           {
	            case 1   : result = add (num1, num2);
	                       break;
	            case 2   : result = sub (num1, num2);
	                       break;
	            case 3   : result = mul (num1, num2);
	                       break;
	            case 4   : result = dvd (num1, num2); 
	           } // switch
	           
	        printResult (num1, num2, result, option);
	       }  // else option != 5
	   } while (option != 5);
	cout << "\nThank you for using Calculator.\n";
	return 0;
}	// main 
/*	================== getOption ================== 
	This function shows a menu and reads user option.
	   Pre   Nothing
	   Post  Returns a valid option
*/
int getOption (void)
{	
	int option;

	do
	   {
	    cout << "\n*******************";
	    cout << "\n*       MENU      *";
	    cout << "\n*                 *";
	    cout << "\n*  1. ADD         *";
	    cout << "\n*  2. SUBTRACT    *";
	    cout << "\n*  3. MULTIPLY    *";
	    cout << "\n*  4. DIVIDE      *";
	    cout << "\n*  5. QUIT        *";
	    cout << "\n*                 *";
	    cout << "\n*******************";

	    cout << "\n\n\nPlease type your choice ";
	    cout << "and press the return key : ";
	    cin  >> option;

	    if (option < 1 || option > 5)
	        cout << "\a\nInvalid option. "
	             << "Please re-enter.\n";

	   } while (option < 1 || option > 5);
	return option;
}	// getOption

/*	===================== add =====================
	This function adds two numbers. 
	   Pre  The two numbers are given as parameters
	   Post Return the results
*/
float add (float num1, float num2)
{
//	Local Definitions
	float res;

//	Statements
	res = num1 + num2;
	return res;
}	// add
/*	===================== sub ====================
	This function subtracts two numbers.
	   Pre    The two numbers are given as parameters
	   Post   Return the results
*/
float sub (float num1, float num2)
{
//	Local Definitions
	float res;

//	Statements
	res = num1 - num2;
	return res;
}	// sub
/*	===================== mul ====================
	This function multiplies two numbers.
	   Pre    The two numbers are given as parameters
	   Post   Return the results
*/
float mul (float num1, float num2)
{
//	Local Definitions
	float res;

//	Statements
	res = num1 * num2;
	return res;
}	// mul
/*	===================== dvd ====================
	This function divides two numbers
	   Pre    The two numbers are given as parameters
	   Post   Return the results
*/
float dvd (float num1, float num2)
{
//	Local Definitions
	float res;

//	Statements
	res = num1 / num2;
	return res;
}	// dvd
/*	==================== printResult ===================
	This function prints the result of calculation.
	   Pre    The two numbers, result, and option are given
	   Post   Prints the numbers and the result
*/
void printResult (float num1, float num2,
                  float res,  int   option)
{
//	Statements
	cout << fixed << setprecision(2);
	cout << "\n\n" << num1;
	switch (option)
	    {
	     case 1 : cout <<" + ";
	              break;
	     case 2 : cout <<" - ";
	              break;
	     case 3 : cout <<" * ";
	              break;
	     case 4 : cout <<" / ";
	              break;
	    }  // switch option
	cout << num2 << " = " << res << endl;

	return;
}	// printResults
//	================== End of Program ==================

/*	Results
Please type your choice and press the return key : 4


Enter two numbers: 2 4


2.00 / 4.00 = 0.50

*******************
*       MENU      *
*                 *
*  1. ADD         *
*  2. SUBTRACT    *
*  3. MULTIPLY    *
*  4. DIVIDE      *
*  5. QUIT        *
*                 *
*******************


Please type your choice and press the return key : 5

Thank you for using Calculator.
*/

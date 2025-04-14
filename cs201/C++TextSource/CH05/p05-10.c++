/* This program uses a menu to allow the user to add, 
	multiply, subtract, or divide two integers. 
	   Written by:
	   Date:
*/
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

void  getData     (float &num1,   float &num2); 
void  printResult (float  num1,   float  num2,
                   float  result, int    option);
int   getOption   (void);
float calc        (int option, float num1, float num2);
float add         (float num1, float num2);
float sub         (float num1, float num2);
float mul         (float num1, float num2);
float dvd         (float num1, float num2);

int main ()
{
	int option = getOption();

	float   num1;
	float   num2;
	getData (num1, num2);

	float result = calc (option, num1, num2);
	printResult (num1, num2, result, option);
	return 0;
}	// main
/*	===================== getOption ====================
	This function shows a menu and reads the user option.
	   Pre    Nothing
	   Post   Returns the option
*/
int getOption (void)
{
	cout << "\n\n\n";
	cout << "\n\t**********************************";
	cout << "\n\t*              MENU              *";
	cout << "\n\t*                                *";
	cout << "\n\t*  1. ADD                        *";
	cout << "\n\t*  2. SUBTRACT                   *";
	cout << "\n\t*  3. MULTIPLY                   *";
	cout << "\n\t*  4. DIVIDE                     *";
	cout << "\n\t*                                *";
	cout << "\n\t**********************************";

	cout << "\n\nPlease type your choice "
	     << "and press the return key : ";
	int  option;
	cin  >> option;
	return option;
}	// getOption
/* ==================== getData ==================== 
   This function reads two numbers from the keyboard.
	   Pre  Nothing
	   Post Two numbers read into variables in main
*/
void getData (float &num1, float &num2)
{
	cout << "\nEnter two numbers separated by a space: ";
	cin  >> num1 >> num2;
	return;
}	// getData
/*	==================== calc ====================
	This function determines the type of operation
	and calls a function to perform it. 
	   Pre  option contains the operation
	        num1 & num2 contain data
	   Post Returns the results
*/
float calc (int option, float num1, float num2)
{
	float result;
	switch (option)
	    {
	     case 1 : result = add (num1, num2);
	              break;
	     case 2 : result = sub (num1, num2);
	              break;
	     case 3 : result = mul (num1, num2);
	              break;
	     case 4 : if (num2 == 0.0) 
	                 {
	                  cout << "\n\a\aError: ";
	                  cout << "division by zero ***\n";
	                  exit (1);
	                 }
	              else
	                  result = dvd (num1, num2);
	              break;

	    /* Better structured programming would validate the  
	       option in getOption. However, we have not yet 
	       introduced the technique required to put it there.
	    */
	     default : cout <<"\aOption not available\n";
	               exit (1);
	    } // switch
	return result;
}	// calc
/*	===================== add =====================
	This function adds two numbers. 
	   Pre  The two numbers are given as parameters
	   Post Return the results
*/
float add (float num1, float num2)
{
	return num1 + num2;
}	// add
/*	===================== sub ====================
	This function subtracts two numbers.
	   Pre    The two numbers are given as parameters
	   Post   Return the results
*/
float sub (float num1, float num2)
{
	return num1 - num2;
}	// sub
/*	===================== mul ====================
	This function multiplies two numbers.
	   Pre    The two numbers are given as parameters
	   Post   Return the results
*/
float mul (float num1, float num2)
{
	return num1 * num2;
}	// mul
/*	===================== dvd ====================
	This function divides two numbers
	   Pre    The two numbers are given as parameters
	   Post   Return the results
*/
float dvd (float num1, float num2)
{
	return num1 / num2;
}	// dvd
/*	==================== printResult ===================
	This function prints the result of calculation.
	   Pre    The two numbers, result, and option are given
	   Post   Prints the numbers and the result
*/
void printResult (float num1, float num2,
                  float res,  int   option)
{
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

/*	Results





    **********************************
    *              MENU              *
    *                                *
    *  1. ADD                        *
    *  2. SUBTRACT                   *
    *  3. MULTIPLY                   *
    *  4. DIVIDE                     *
    *                                *
    **********************************

Please type your choice and press the return key : 1

Enter two numbers separated by a space: 2 7


2.00 + 7.00 = 9.00
*/

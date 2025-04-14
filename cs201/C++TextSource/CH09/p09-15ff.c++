/*	Demonstrate concept of storing arrays in the heap.  
	Program builds and manipulates a variable number of  
	ragged arrays. It then calculates minimum, maximum,
	and average of the numbers in the arrays.
	   Written by:
	   Date:
*/
#include <iostream>
#include <climits>
using namespace std;

int** buildTable   (void);
void  fillTable    (int** table); 
void  processTable (int** table); 

int   rowMinimum   (int*  rowPtr);
int   rowMaximum   (int*  rowPtr);
float rowAverage   (int*  rowPtr);
int   smaller      (int   first, int second); 
int   larger       (int   first, int second);

int main ()
{
	int** table = buildTable(); 

	fillTable    (table); 
	processTable (table); 
	return 0; 
}	// main 

/*	==================== buildTable ====================
	Create backbone of the table by creating an array of
	pointers, each pointing to an array of integers.
	   Pre   Nothing
	   Post  It returns a pointer pointing to the table
*/
int** buildTable (void) 
{
	cout << "\nEnter the number of rows in the table: ";
	int rowNum;
	cin  >> rowNum; 

	int** table;
	table = new int* [rowNum + 1];
	
	int row;
	for (row = 0; row < rowNum; row++) 
	   {
	    int   colNum;
	    cout << "Enter number of integers in row " 
	         << row + 1 << ": ";
	    cin  >> colNum; 
	    table[row]    = new int [colNum + 1];
	    table[row][0] = colNum; 
	   } // for 
	table[row] = 0;
	return table;
}	// buildTable 

/* =================== fillTable ==================== 
	This function fills the rows. 
	   Pre   An array of pointers
	   Post  The filled-up table
*/
void fillTable (int** table) 
{
	cout << "\n =============================";
	cout << "\n Now we fill the table.\n";
	cout << "\n For each row enter the data";
	cout << "\n and press return: ";
	cout << "\n =============================\n";

	int row = 0;
	while (table[row] != NULL)
	  {
	   cout << "\n row " << row + 1
	          << " (" << table[row][0] << " integers) =====> ";
	   for (int column = 1; column <= table[row][0]; column++)
	      cin >> table[row][column];
	   row++;
	  } // while 
	return;
}// fillTable 

/*	================== processTable ==================
	Process the table to create the statistics.
	   Pre   Table
	   Post  Statistics (min, max, and average) for each row
*/
void processTable (int** table)
{
int   row = 0;
int   rowMin;
int   rowMax;
float rowAve;

	while (table[row] != 0)
	    {
	      rowMin = rowMinimum (table[row]);
	      rowMax = rowMaximum (table[row]);
	      rowAve = rowAverage (table[row]);
	      cout << "\n\nStatistics for row " << row + 1;
	      cout << "\nThe minimum: " << rowMin; 
	      cout << "\nThe maximum: " << rowMax; 
	      cout << "\nThe average: " << rowAve;
	      row++;
	    } // while
	return;
}	// processTable 

/*	=================== rowMinimum =================== 
	Calculates the minimum of the data in a row.
	   Pre   A pointer to the row
	   Post  Returns the minimum for that row
*/
int rowMinimum (int* rowPtr)
{
	int rowMin = INT_MAX;
	for (int column = 1; column <= *rowPtr; column++)
	   rowMin = smaller (rowMin, *(rowPtr + column));
	return rowMin;
}	//rowMinimum 

/*	================== rowMaximum ================== 
	Calculates the maximum of the data in a row.
	   Pre   A pointer to the row
	   Post  Returns the maximum for that row
*/
int rowMaximum (int* rowPtr) 
{
	int rowMax = INT_MIN;
	for (int column = 1; column <= *rowPtr; column++) 
		rowMax = larger  (rowMax, *(rowPtr + column)); 
	return rowMax;
}	// rowMaximum 

/*	====================== rowAverage ====================== 
	This function calculates the average of the data in a row.
	   Pre   A pointer to the row
	   Post  Returns the average for that row
*/
float  rowAverage (int* rowPtr) 
{
	float  total = 0;
	for (int column = 1; column <= *rowPtr; column++)
	   total += *(rowPtr + column);

	float  rowAve;
	rowAve = total / *rowPtr;
	return rowAve;
}	//rowAverage 

/*	=================== smaller ==================== 
	This function returns the smaller of two numbers.
	   Pre   two numbers
	   Post  Returns the smaller
*/
int  smaller (int first, int second) 
{
	return (first < second ? first : second);
}	// smaller 

/*	 =================== larger =================== 
	This function returns the larger of two numbers.
	   Pre   two numbers
	   Post  Returns the larger
*/
int  larger  (int first, int second)
{
	return (first > second ? first : second);
}	// larger 

/*	Results
Enter the number of rows in the table: 3
Enter number of integers in row 1: 5
Enter number of integers in row 2: 4
Enter number of integers in row 3: 3

 =============================
 Now we fill the table.

 For each row enter the data
 and press return: 
 =============================

 row 1 (5 integers) =====> 1 2 3 4 5

 row 2 (4 integers) =====> 21 22 23 24

 row 3 (3 integers) =====> 31 32 33


Statistics for row 1
The minimum: 1
The maximum: 5
The average: 3

Statistics for row 2
The minimum: 21
The maximum: 24
The average: 22.5

Statistics for row 3
The minimum: 31
The maximum: 33
The average: 32
*/

/*	This program reads values of a two-dimensional array 
	from the keyboard and creates two one-dimensional 
	arrays, which are the averages of rows and columns.
	   Written by:
	   Date:
*/
#include <iostream>
#include <iomanip>
using namespace std;

const int cMAX_ROWS = 5;
const int cMAX_COLS = 6;

void getData       (int   table[][cMAX_COLS]);
void columnAverage (const int   table[][cMAX_COLS], 
                    float colAvrg []);
void rowAverage    (const int   table[][cMAX_COLS],
                    float rowAvrg []);
void printTables   (const int   table[][cMAX_COLS], 
                    const float rowAvrg[], 
                    const float colAvrg[]);

int main ( )
{
	int table [cMAX_ROWS][cMAX_COLS];

	float rowAve [cMAX_ROWS]    = { 0 };
	float columnAve [cMAX_COLS] = { 0 };

	getData       (table);
	columnAverage (table, columnAve);
	rowAverage    (table, rowAve);
	printTables   (table, rowAve, columnAve);

	return 0;
}	// main 
/*	================== getData ================== 
	This function receives data for two-dimensional array.
	   Pre   table is array to be filled with integers 
	   Post  The array is filled
*/
void getData (int table[][cMAX_COLS]) 
{
	for (int row = 0; row < cMAX_ROWS; row++)
	   for (int col = 0; col < cMAX_COLS; col++)
	      {
	       cout << "Enter integer and key <return>: ";
	       cin >> table[row][col];
	      } // for col
	return;
} // getData 
/* ================== columnAverage ================== 
	This function calculates the average for each column.
	   Pre   table filled with integer values
	   Post  Average calculated and in average array
*/
void columnAverage (const int   table [][cMAX_COLS],
                          float colAvrg[])
{
	for (int col = 0; col < cMAX_COLS; col++)
	   {
	    for (int row = 0; row < cMAX_ROWS; row++)
	       colAvrg [col] += table [row] [col];
	    colAvrg [col] /=  cMAX_ROWS;
	   } // for
	return;
}	// columnAverage 
/* ================== rowAverage ================== 
	This function calculates the row averages for a table.
	   Pre  table has been filled with values
	   Post Averages calculated & in the average array
*/
void rowAverage (const int   table[][cMAX_COLS],
                       float rowAvrg [])
{
	for (int row = 0; row < cMAX_ROWS; row++)
	   {
	    for (int col = 0; col < cMAX_COLS; col++)
	       rowAvrg[row] += table [row] [col];
	    rowAvrg [row] /=  cMAX_COLS;
	   } // for row 
	return;
}	// rowAverage 
/*	================== printTables ================== 
	Print data table, with average of rows at end of each 
	row and average of columns below each column.
	   Pre   each table has been filled with its data
	   Post  the tables have been printed
*/
void printTables (const int   table[][cMAX_COLS],
                  const float rowAvrg[], 
                  const float colAvrg[])
{ 
	cout.setf (ios::fixed);
	cout << setprecision (2);
	for (int row = 0; row < cMAX_ROWS; row++)
	   {
	    for (int col = 0; col < cMAX_COLS; col++)
	       cout << setw(6) << table[row][col];
	    cout << "   | " << rowAvrg [row] << endl;
	   } // for row

	cout << "---------------------------------------\n";
	for (int col = 0; col < cMAX_COLS; col++)
		cout << setw(6) << colAvrg[col];
	return;
}	// printTables 
//	================ End of Program ================= 

/*	Results:
    10    12    14    16    18    20   |  15.00
    22    24    26    28    30    23   |  25.50
    25    27    29    31    33    35   |  30.00
    39    41    43    45    47    49   |  44.00
    51    53    55    57    59    61   |  56.00
---------------------------------------
 29.40 31.40 33.40 35.40 37.40 37.60

*/

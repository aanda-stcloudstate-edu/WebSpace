/*	Demonstrate pointers with selection sort.
	   Written by:
	   Date:
*/
#include <iostream>
#include <iomanip>
using namespace std;

const int cSIZE = 25; 

int* getData    (int* pAry,    int  arySize);
void selectSort (int* pAry,    int* last);
void printData  (int* pAry,    int* last);
int* smallest   (int* pAry,    int* pLast); 
void exchange   (int* current, int* smallest);

int main ()
{
	int  ary[cSIZE];
	int* pLast = getData (ary, cSIZE);
	selectSort (ary, pLast);
	printData  (ary, pLast);

	return 0;
}	// main 
/*	================== getData ================== 
	Reads data from keyboard and places in sort array.
	Pre   pAry is a pointer to an array to be filled
	      arySize is integer for maximum array size
	Post  Array filled. Returns last element address
*/
int* getData (int* pAry, int  arySize)
{
	int readCnt = 0;
	int* pFill = pAry;

	cout << "\nPlease enter first number: ";
	do
	   {
	    cin  >> *pFill;
	    if (cin.good())
	       {
	        pFill++;
	        readCnt++;
	        cout << "Enter next number or <EOF>: ";
	       } // if 
	   } while (cin.good() && readCnt < arySize);

	cout << "\n\n" << readCnt << " numbers read.\n";
	return (--pFill);
}	// getData 
/*	=================== selectSort =================== 
	Sort by selecting smallest element in unsorted part
	of the array and exchanging it with element at the 
	beginning of the unsorted list.
	Pre  array must contain at least one item 
	     pLast is pointer to last element in array
	Post The array rearranged smallest to largest
*/
void selectSort (int* pAry, int* pLast)
{
	for (int* pWalker = pAry; pWalker < pLast; pWalker++) 
	   {
	    int* pSmallest = smallest (pWalker, pLast);
	    exchange (pWalker, pSmallest);
	   } // for
	return;
}	// selectSort 
/*	================== smallest ================== 
	Find smallest element starting at current pointer.
	Pre   pAry points to first unsorted element
	Post  smallest element identified and returned
*/
int* smallest (int* pAry, int* pLast)
{
	int* pSmallest = pAry;
	for (int* pLooker = pAry + 1;
	     pLooker <= pLast;
	     pLooker++)
	   if (*pLooker < *pSmallest) 
	       pSmallest = pLooker;
	return pSmallest;
}	// smallest 
/*	=================== exchange ================= 
	Given pointers to two array elements, exchange them
	Pre  p1 & p2 are pointers to values to be exchanged
	Post The exchange is completed
*/
void exchange (int* p1, int* p2)
{
	int temp  =  *p1;
	    *p1   =  *p2;
	    *p2   =  temp;

	return;
}	// exchange 
/*	================== printData ================== 
	Given a pointer to an array, print the data.
	Pre  pAry points to the array to be filled
	     pLast identifies last element in the array
	Post The data have been printed.
*/
void printData (int* pAry, int* pLast)
{
	int  nmbrPrt;
	int* pPrint;

	cout << "\nYour data sorted are: \n";
	for (pPrint = pAry, nmbrPrt = 0;
	     pPrint <= pLast;
	     nmbrPrt++, pPrint++)
	   cout << setw(2) << nmbrPrt 
	        << setw(4) << *pPrint << endl; 
	cout << "\nEnd of List\n";
	return;
}	// PrintData 
//	================= End of Program ================


/*	Results:

Please enter first number: 1
Enter next number or <EOF>: 3
Enter next number or <EOF>: 17
Enter next number or <EOF>: 7
Enter next number or <EOF>: 31
Enter next number or <EOF>: 11
Enter next number or <EOF>: 13
Enter next number or <EOF>: 19
Enter next number or <EOF>: 29
Enter next number or <EOF>: 23
Enter next number or <EOF>: ^d

10 numbers read.

Your data sorted are: 
 0   1
 1   3
 2   7
 3  11
 4  13
 5  17
 6  19
 7  23
 8  29
 9  31

End of List
*/

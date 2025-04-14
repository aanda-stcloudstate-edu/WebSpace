/*	Generate a random number permutation.
	   Written by:
	   Date:
*/
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int cAry_Size = 20;

void bldPerm   (int randNos[]);
void printData (int data[], int size, int lineSize);

int main ()
{
	int randNos [cAry_Size];
	
	cout << "Begin Random Permutation Generation\n";
	
	bldPerm   (randNos);
	printData (randNos, cAry_Size, 10);
	
	return 0;
}	// main 

/*	==================== bldPerm ====================
	Generate a random number permutation in array.
	   Pre   randNos is array to receive permutations
	   Post  randNos filled
*/
void bldPerm (int randNos[])
{
	int haveRand[cAry_Size] = {0};
	
	for (int i = 0; i < cAry_Size; i++)
	    {
	     int randNo;
	     do
	       {
	        randNo = rand() % cAry_Size;
	       } while (haveRand[randNo] == 1);
	     haveRand[randNo] = 1;
	     randNos[i] = randNo;
	    } // for 
	return;
}	// bldPerm 
/*	==================== printData ====================
	Prints the data as a two-dimensional array.
	   Pre   data: a filled array
	         last: index to last element to be printed
	         lineSize: number of elements printed on a line
	   Post  the data have been printed
*/
void printData (int data[], int size, int lineSize)
{
	printf("\n");
	for (int i = 0, numPrinted = 0; i < size; i++)
	   {
	    numPrinted++;
	    cout << setw(3) << data[i];
	    if (numPrinted >= lineSize)
	       {
	        cout << endl;
	        numPrinted = 0;
	       } // if 
	   } // for 
	cout << endl;
	return;
}	// printData 

/*	Results:
Begin Random Permutation Generation

 18 13 15 11  7 10 19 12  6  9 
  4  0  5  3 17 14  2 16  1  8 
*/

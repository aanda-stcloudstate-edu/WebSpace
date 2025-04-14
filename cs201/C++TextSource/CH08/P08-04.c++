/*	Read data from a file into an array. 
	Build frequency array & print the data with histogram.
	   Written by:
	   Date:
*/
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int cMAX_ELMNTS  = 100;
const int cANLYS_RANGE =  19;

	int getData (int  numbers[], int size, int range);

	void printData     (const int numbers[], int size, 
	                    int lineSize);
	void makeFrequency (int numbers[], int size,
	                    int frequency[], int range);
	void makeHistogram (int frequency[], int range);

int main ()
{
	int size;
	int nums[cMAX_ELMNTS];
	int frequency[cANLYS_RANGE + 1];

	size = getData (nums, cMAX_ELMNTS, cANLYS_RANGE);
	printData (nums, size, 10);

	makeFrequency(nums,size,frequency,cANLYS_RANGE);
	makeHistogram(frequency, cANLYS_RANGE);
	return 0;
}	// main 
/*	================== getData ================== 
	Read data from file into array. The array 
	does not have to be completely filled.
	   Pre   data is an empty array
	         size is maximum elements in array
	         range is highest value that can be accepted
	   Post  Array is filled--Return number of elements
*/
int getData (int data[], int size, int range)
{
	ifstream  fsData;
	fsData.open("histogrm.dat");
	if (!fsData)
	    cerr << "Error opening file\a\a\n", exit (100); 

	int dataIn;
	int loader = 0;
	while (loader < size 
	    && (fsData >> dataIn))
	   if (dataIn >= 0 && dataIn <= range)
	      data[loader++] = dataIn;
	   else
	      cout << "Data point " << dataIn 
	           << " invalid. Ignored. \n";

//	Test to see what stopped while 
	if (loader == size && (fsData >> dataIn))
	   // More data in file
	   cout << "\nToo much data. Process what read.\n";
	return loader;
}	// getData 
/*	================== printData ================== 
	Print the data as a two-dimensional array.
	   Pre   data: a filled array
	         size: size of array to be printed
	         lineSize: max elements printed on a line 
	   Post  The data have been printed
*/
void printData (const int data[], int size, int lineSize)
{
	cout << endl << endl;
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
	cout << endl << endl;
	return;
}	// printData 
/*	================= makeFrequency ================== 
	Analyze the data in nums and build their frequency
	distribution.
	   Pre    nums: array of data for analysis 
	          size: size of array containing data 
	          frequency: accumulation array
	          range: maximum value of data
	   Post   Frequency array has been built
*/
void makeFrequency (int nums[],      int size,
                    int frequency[], int range)
{
	// First initialize the frequency array 
	for (int i = 0; i <= range; i++)
	   frequency [i] = 0;

	// Scan numbers and build frequency array 
	for (int i = 0; i < size; i++)
	   frequency [nums [i]]++;
	return;
}	// makeFrequency 
/*	================= makeHistogram ================== 
	Print a histogram representing analyzed data.
	   Pre   freq contains value count
	         range max data value & max array index
	   Post  histogram has been printed
*/
void makeHistogram (int freq[], int range)
{
	for (int i = 0; i <= range; i++)
	   {
	    cout << setw(3) << i << setw(3) << freq[i];
	    for (int j = 1; j <= freq[i]; j++)
	        cout << "*";
	    cout << endl;
	   } // for i
	return;
}	// makeHistogram 
//	================= End of Program ================= 

/*	Results:
Data point 20 invalid. Ignored.   
Data point 25 invalid. Ignored. 

 1  2  3  4  5  6  7  8  7 10
 2 12 13 13 15 16 17 18 17  7
 3  4  6  8 10  2  4  6  8 10
 4  3  5  7  1  3  7  7 11 13
 5 10 11 12 13 16 18 11 12  7
 6  1  2  2  3  3  3  4  4  4
 7  7  8  7  6  5  4  1  2  2
 8 11 11 13 13 13 17 17  7  7
13 17 17 15 15

 0  0
 1  4 ****
 2  7 *******
 3  7 *******
 4  8 ********
 5  4 ****
 6  5 *****
 7 12 ************
 8  5 *****
 9  0
10  4 ****
11  5 *****
12  3 ***
13  8 ********
14  0
15  3 ***
16  2 **
17  6 ******
18  2 **
19  0
*/

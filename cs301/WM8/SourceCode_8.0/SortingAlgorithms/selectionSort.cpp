//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.


#include <iostream>
#include <string>

/** Finds the largest item in an array.
 @pre  The size of the array is >= 1.
 @post  The arguments are unchanged.
 @param theArray  The given array.
 @param size  The number of elements in theArray.
 @return  The index of the largest entry in the array. */
template<class ItemType>
int findIndexOfLargest(const ItemType theArray[], int size);

/** Sorts the items in an array into ascending order.
 @pre  None.
 @post  The array is sorted into ascending order; the size of the array
    is unchanged.
 @param theArray  The array to sort.
 @param n  The size of theArray. */
template<class ItemType>
void selectionSort(ItemType theArray[], int n)
{
   // last = index of the last item in the subarray of items yet
   //        to be sorted;
   // largest = index of the largest item found
   for (int endIndex = n - 1; endIndex >= 1; endIndex--)
   {
      // At this point, theArray[last+1..n-1] is sorted, and its 
      // entries are greater than those in theArray[0..last].
      // Select the largest entry in theArray[0..last]
      int largest = findIndexOfLargest(theArray, endIndex+1);
      
      // Swap the largest entry, theArray[largest], with
      // theArray[last]
      std::swap(theArray[largest], theArray[endIndex]);
   }  // end for
}  // end selectionSort

template<class ItemType>
int findIndexOfLargest(const ItemType theArray[], int size)
{
   int indexOfLargest = 0; // Index of largest entry found so far
   for (int currentIndex = 1; currentIndex < size; currentIndex++)
   {
      // At this point, theArray[indexSoFar] >= all entries in
      // theArray[0..currentIndex - 1]
      if (theArray[currentIndex] > theArray[indexOfLargest])
          indexOfLargest = currentIndex;
   }  // end for
   return indexOfLargest; // Index of largest entry
}  // end findIndexOfLargest

int main()
{
   std::string a[6] = {"Z", "X", "R", "K", "F", "B"};
   selectionSort(a, 6);
   for (int i = 0; i < 6; i++)
      std::cout << a[i] << " ";
   std::cout << std::endl;
}  // end main

/*

B F K R X Z 

*/

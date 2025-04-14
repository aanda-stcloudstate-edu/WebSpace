   //  Created by Frank M. Carrano and Timothy M. Henry.
   //  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.
#include <iostream>
const int RUN_SIZE = 32; // length of runs for insertion sort.
template<class ItemType>
void insertionSort(ItemType theArray[], int start, int end)
{
      // unsorted = first index of the unsorted region,
      // loc = index of insertion in the sorted region,
      // nextItem = next item in the unsorted region.
      // Initially, sorted region is theArray[0],
      // unsorted region is theArray[1..n-1].
      // In general, sorted region is theArray[0..unsorted-1],
      // unsorted region theArray[unsorted..n-1]
   for (int unsorted = start; unsorted <= end; unsorted++)
   {
         // At this point, theArray[0..unsorted-1] is sorted.
         // Find the right position (loc) in theArray[0..unsorted]
         // for theArray[unsorted], which is the first entry in the
         // unsorted region; shift, if necessary, to make room
      ItemType nextItem = theArray[unsorted];
      int loc = unsorted;
      while ((loc > 0) && (theArray[loc - 1] > nextItem))
      {
            // Shift theArray[loc - 1] to the right
         theArray[loc] = theArray[loc - 1];
         loc--;
      }  // end while

         // At this point, theArray[loc] is where nextItem belongs
      theArray[loc] = nextItem; // Insert nextItem into sorted region
   }  // end for
}  // end insertionSort

template<class ItemType>
void merge(ItemType theArray[], int first, int mid, int last)
{
   ItemType tempArray[last - first + 1];  // Temporary array

      // Initialize the local indices to indicate the subarrays
   int first1 = first;            // Beginning of first subarray
   int last1 = mid;               // End of first subarray
   int first2 = mid + 1;          // Beginning of second subarray
   int last2 = last;              // End of second subarray

      // While both subarrays are not empty, copy the
      // smaller item into the temporary array
   int index = first1;            // Next available location in tempArray
   while ((first1 <= last1) && (first2 <= last2))
   {
         // At this point, tempArray[first..index-1] is in order
      if (theArray[first1] <= theArray[first2])
      {
         tempArray[index] = theArray[first1];
         first1++;
      }
      else
      {
         tempArray[index] = theArray[first2];
         first2++;
      }  // end if
      index++;
   }  // end while

      // Finish off the first subarray, if necessary
   while (first1 <= last1)
   {
         // At this point, tempArray[first..index-1] is in order
      tempArray[index] = theArray[first1];
      first1++;
      index++;
   }  // end while

      // Finish off the second subarray, if necessary
   while (first2 <= last2)
   {
         // At this point, tempArray[first..index-1] is in order
      tempArray[index] = theArray[first2];
      first2++;
      index++;
   }  // end for

      // Copy the result back into the original array
   for (index = first; index <= last; index++)
      theArray[index] = tempArray[index];
}  // end merge

/** Sorts the items in an array into ascending order.
 Applies insertion sort to runs of entries, and then merges adjacent runs.
 @pre  None.
 @post  theArray is sorted into ascending order; n is unchanged.
 @param theArray  The given array.
 @param arraySize The size of theArray. */

template <class ItemType>
void timSort(ItemType theArray[], int arraySize)
{
   // Sort individual subarrays of size RUN_SIZE
   for (int start = 0; start < arraySize; start += RUN_SIZE)
   {
      // min is used to ensure that the upper bound does not pass the
      // end of the array when arraySize is not a multiple of RUN_SIZE
      insertionSort(theArray, start, std::fmin(start + RUN_SIZE - 1, arraySize - 1));
   } // end insertion sort of runs

   // At this point, the runs are sorted and we must merge them.
   // We begin with runs of size RUN_SIZE and then double their size at each iteration.
   // Outer loop controls size of runs to merge.
   for (int mergeSize = RUN_SIZE; mergeSize < arraySize; mergeSize = 2 * mergeSize)
   {
      // The start of the left subarray begins at zero and is incremented
      // by 2 * mergeSize to jump over the two subarrays that were just merged
      for (int leftStart = 0; leftStart < arraySize; leftStart += 2* mergeSize)
      {
         // last element of left subarray is mid
         int mid = leftStart + mergeSize - 1;

         // ending element of right sub array
         // mid+1 is starting point
         int rightEnd = std::fmin((leftStart + 2* arraySize - 1), (arraySize -1));

         // merge subarrays theArray[leftStart.....mid] and  theArray[mid+1....rightEnd]
         if (mid < rightEnd)
            merge(theArray, leftStart, mid, rightEnd);
      } // end for-loop for this pass of merges
   } // end for-loop merging
} // end timsort



int main()
{
   std::string a[6] = {"Z", "X", "R", "K", "F", "B"};
   timSort(a, 6);
   for (int i = 0; i < 6; i++)
      std::cout << a[i] << " ";
   std::cout << std::endl;

   std::string b[26] = {"Z", "Y", "X", "W", "V", "U", "T", "S", "R", "Q", "P",
      "O", "N", "M", "L", "K", "J", "I", "H", "G", "F", "E", "D", "C", "B", "A"};
   timSort(b, 26);
   for (int i = 0; i < 26; i++)
      std::cout << b[i] << " ";
   std::cout << std::endl;
}  // end main

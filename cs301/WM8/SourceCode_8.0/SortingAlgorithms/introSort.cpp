   //  Created by Frank M. Carrano and Timothy M. Henry.
   //  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

// Contains code for:
//    insertionSort
//    heapSort
//    quicksort
//    introSort

#include <iostream>
const int MIN_SIZE = 8;  // Normally in range 16 to 32
const int DEPTH_LIMIT = 8; // Normally in range 16

////////////////////////////////////
/// insertionSort
////////////////////////////////////
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
   for (int unsorted = start; unsorted < end; unsorted++)
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

////////////////////////////////////
/// heapSort
////////////////////////////////////
int getLeftChildIndex(int nodeIndex)
{
   return (2 * nodeIndex) + 1;
}  // end getLeftChildIndex

int getRightChildIndex(int nodeIndex)
{
   return (2 * nodeIndex) + 2;
}  // end getRightChildIndex

int getParentIndex(int nodeIndex)
{
   return (nodeIndex - 1) / 2;
}  // end getParentIndex

bool isLeaf(const int nodeIndex, int itemCount)
{
   return (getLeftChildIndex(nodeIndex) >= itemCount);
}  // end isLeaf

template<class ItemType>
void heapRebuild(const int subTreeNodeIndex, ItemType items[], int itemCount)
{
   if (!isLeaf(subTreeNodeIndex, itemCount))
   {
         // Find larger child
      int leftChildIndex = getLeftChildIndex(subTreeNodeIndex);   // A left child must exist
      int largerChildIndex = leftChildIndex;                      // Make assumption about larger child
      int rightChildIndex = getRightChildIndex(subTreeNodeIndex); // A right child might not exist

         // Check to see whether a right child exists
      if (rightChildIndex < itemCount)
      {
            // A right child exists; check whether it is larger
         if (items[rightChildIndex] > items[largerChildIndex])
            largerChildIndex = rightChildIndex; // Asssumption was wrong
      }  // end if

         // If root value is smaller that the value in the larger child, swap values
      if (items[subTreeNodeIndex] < items[largerChildIndex])
      {
         swap(items[largerChildIndex], items[subTreeNodeIndex]);

            // Continue with the recursion at that child
         heapRebuild(largerChildIndex, items, itemCount);
      }  // end if
   }  // end if
}  // end heapRebuild

/** Sorts the items in an array into ascending order.
 @pre  None.
 @post  anArray is sorted into ascending order; n is
 unchanged.
 @param anArray  The given array.
 @param n  The size of theArray. */
template<class ItemType>
void heapSort(ItemType anArray[], int start, int end)
{

      // Build initial heap
   for (int index = end / 2; index >= start; index--)
      heapRebuild(index, anArray, end);
      // The heap is anArray[0..n-1]
      // Assertion: anArray[0] is the largest entry in the array

   swap (anArray[start], anArray[end - 1]);

   int heapSize = end - 1;  // Heap region size decreases by 1
   while (heapSize > 1)
   {
      heapRebuild(start, anArray, heapSize);

      heapSize--;
      swap (anArray[start], anArray[heapSize]);
   }  // end while
}  // end heapSort

////////////////////////////////////
/// quickSort
////////////////////////////////////

template<class ItemType>
int sortStartMiddleEnd(ItemType theArray[], int start, int end)
{
   int mid = start + (end - start) / 2;

   if (theArray[start] > theArray[mid])
      std::swap(theArray[start], theArray[mid]); // Exchange entries

   if (theArray[mid] > theArray[end])
      std::swap(theArray[mid], theArray[end]); // Exchange entries

   if (theArray[start] > theArray[end])
      std::swap(theArray[start], theArray[end]); // Exchange entries

   return mid;
}  // end sortStartMiddleEnd
/** Partitions the entries in an array about a pivot entry for quicksort.
 @pre  theArray[start..end] is an array; start <= end.
 @post  theArray[start..end] is partitioned such that:
 S1 = theArray[start..pivotIndex-1] <= pivot
 theArray[pivotIndex]          == pivot
 S2 = theArray[pivotIndex+1..end]  >= pivot
 @param theArray  The given array.
 @param start  The start entry to consider in theArray.
 @param end  The end entry to consider in theArray.
 @return  The index of the pivot. */
template<class ItemType>
int partition(ItemType theArray[], int start, int end)
{
      // Choose pivot using median-of-three selection
   int pivotIndex = sortStartMiddleEnd(theArray, start, end);

      // Reposition pivot so it is end in the array
   std::swap(theArray[pivotIndex], theArray[end - 1]);
   pivotIndex = end - 1;
   ItemType pivot = theArray[pivotIndex];

      // Determine the regions S1 and S2
   int indexFromLeft = start;
   int indexFromRight = end - 2;

   bool done = false;
   while (!done)
   {
         // Locate start entry on left that is >= pivot
      while (theArray[indexFromLeft] < pivot)
         indexFromLeft = indexFromLeft + 1;

         // Locate start entry on right that is <= pivot
      while (theArray[indexFromRight] > pivot)
         indexFromRight = indexFromRight - 1;

      if (indexFromLeft < indexFromRight)
      {
         std::swap(theArray[indexFromLeft], theArray[indexFromRight]);
         indexFromLeft = indexFromLeft + 1;
         indexFromRight = indexFromRight - 1;
      }
      else
         done = true;
   }  // end while

      // Place pivot in proper position between S1 and S2, and mark its new location
   std::swap(theArray[pivotIndex], theArray[indexFromLeft]);
   pivotIndex = indexFromLeft;
   return pivotIndex;
}  // end partition


/** Sorts an array into ascending order. Uses the quick sort with
        median-of-three pivot selection for arrays of at least MIN_SIZE
        entries, and uses the insertion sort for other arrays.
 @pre  theArray[start..end] is an array.
 @post  theArray[start..end] is sorted.
 @param theArray  The given array.
 @param start  The index of the first element to consider in theArray.
 @param end   The index of the last element to consider in theArray. */
template <class ItemType>
void quickSort(ItemType theArray[], int start, int end)
{
   if ((end - start + 1) < MIN_SIZE)
   {
      insertionSort(theArray, start, end);
   }
   else
   {
         // Create the partition: S1 | Pivot | S2
      int pivotIndex = partition(theArray, start, end);

         // Sort subarrays S1 and S2
      quickSort(theArray, start, pivotIndex - 1);
      quickSort(theArray, pivotIndex + 1, end);
   }  // end if
}  // end quickSort

////////////////////////////////////
/// introSort
////////////////////////////////////
template <class ItemType>
void introspectionSort(ItemType theArray[], int start, int end)
{
   int recursionLimit = 2 * std::floor(std::log2(end - start));
   introSort(theArray, start, end, recursionLimit);
}

template <class ItemType>
void introSort(ItemType theArray[], int start, int end, int recursionLimit)
{
   if ((end - start + 1) < MIN_SIZE)
   {
      insertionSort(theArray, start, end);
   }
   else if (recursionLimit == 0)
   {
      heapSort(theArray,  start,  end);
   }
   else
   {
         // Create the partition: S1 | Pivot | S2
      int pivotIndex = partition(theArray, start, end);

         // Sort subarrays S1 and S2
      introSort(theArray, start, pivotIndex - 1, recursionLimit - 1);
      introSort(theArray, pivotIndex + 1, end, recursionLimit - 1);
   }  // end if
}  // end introSort


int main()
{
   std::string b[26] = {"Z", "Y", "X", "W", "V", "U", "T", "S", "R", "Q", "P",
      "O", "N", "M", "L", "K", "J", "I", "H", "G", "F", "E", "D", "C", "B", "A"};
   introSort<std::string>(b, 0, 25, DEPTH_LIMIT);
   for (int i = 0; i < 26; i++)
      std::cout << b[i] << " ";
   std::cout << std::endl;

}  // end main

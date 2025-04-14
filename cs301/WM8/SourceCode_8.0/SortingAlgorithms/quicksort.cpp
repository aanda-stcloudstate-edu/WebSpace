//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

#include <iostream>
#include <string>

static const int MIN_SIZE  = 10; // Smallest size of an array that quicksort will sort

/** Sorts the items in an array into ascending order.
 @pre  None.
 @post  theArray is sorted into ascending order; n is unchanged.
 @param theArray  The given array. */
template<class ItemType>
void insertionSort(ItemType theArray[], int start, int end)
{
   // unsorted = start index of the unsorted region,
   // locaiton = index of insertion in the sorted region,
   // nextItem = next item in the unsorted region.
   // Initially, sorted region is theArray[0],
   // unsorted region is theArray[1..n-1].
   // In general, sorted region is theArray[0..unsorted-1],
   // unsorted region theArray[unsorted..n-1]
   for (int unsorted = start + 1; unsorted <= end; unsorted++)
   {
      // At this point, theArray[start..unsorted-1] is sorted.
      // Find the right position (loc) in theArray[start..unsorted]
      // for theArray[unsorted], which is the start entry in the
      // unsorted region; shift, if necessary, to make room
      ItemType nextItem = theArray[unsorted];
      int locaiton = unsorted;
      while ((locaiton > start) && (theArray[locaiton - 1] > nextItem))
      {
         // Shift theArray[locaiton - 1] to the right
         theArray[locaiton] = theArray[locaiton - 1];
         locaiton--;
      }  // end while
      
      // At this point, theArray[locaiton] is where nextItem belongs
      theArray[locaiton] = nextItem; // Insert nextItem into sorted region
   }  // end for
}  // end insertionSort

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

// Listing 11-5.
/** Sorts an array into ascending order. Uses the quick sort with
 median-of-three pivot selection for arrays of at least MIN_SIZE
 entries, and uses the insertion sort for other arrays.
 @pre  theArray[start..end] is an array.
 @post  theArray[start..end] is sorted.
 @param theArray  The given array.
 @param start  The start element to consider in theArray.
 @param end  The end element to consider in theArray. */
template<class ItemType>
void quickSort(ItemType theArray[], int start, int end)
{

    if (end - start + 1 < MIN_SIZE)
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

int main()
{
   std::string a[6] = {"Z", "X", "R", "K", "F", "B"};
   quickSort(a, 0, 5);
   for (int i = 0; i < 6; i++)
      std::cout << a[i] << " ";
   std::cout << std::endl;
   
   std::string b[26] = {"Z", "Y", "X", "W", "V", "U", "T", "S", "R", "Q", "P", 
            "O", "N", "M", "L", "K", "J", "I", "H", "G", "F", "E", "D", "C", "B", "A"};
   quickSort(b, 0, 25);
   for (int i = 0; i < 26; i++)
      std::cout << b[i] << " ";
   std::cout << std::endl;
}  // end main

/*
 
 B F K R X Z
 A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
 
 */

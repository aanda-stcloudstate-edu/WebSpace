//  Created by Frank M. Carrano and Timothy M. Henry.

/** Interface for the ADT sorted list
 @file SortedListInterface.h */

#ifndef SORTED_LIST_INTERFACE_
#define SORTED_LIST_INTERFACE_

template<class ItemType>
class SortedListInterface
{
public:
   /** Inserts an entry into this sorted list in its proper order
    so that the list remains sorted.
    @pre  None.
    @post  someItem is in the list, and the list is sorted.
    @param someItem The entry to insert into the sorted list.
    @return  True if insertion is successful, or false if not. */
   virtual bool insertSorted(const ItemType& someItem) = 0;

   /** Removes the first or only occurrence of the given entry from this
    sorted list.
    @pre  None.
    @post  If the removal is successful, the first occurrence of the
    given entry is no longer in the sorted list, and the returned
    value is true. Otherwise, the sorted list is unchanged and the
    returned value is false.
    @param target  The entry to remove.
    @return  True if removal is successful, or false if not. */
   virtual bool removeSorted(const ItemType& target) = 0;

   /** Gets the position of the first or only occurrence of the given
    entry in this sorted list. In case the entry is not in the list,
    determines where it should be if it were added to the list.
    @pre  None.
    @post  The position where the given entry is or belongs is returned.
    The sorted list is unchanged.
    @param target  The entry to locate.
    @return  Either the position of the given entry, if it occurs in the
    sorted list, or the position where the entry would occur, but as a
    negative integer. */
   virtual int getPosition(const ItemType& target) const = 0;

   /** Destroys this sorted list and frees its assigned memory. */
   virtual ~SortedListInterface() { }

      // The following member functions are the same as those given in ListInterface
      // in Listing 10-1 of Chapter 10 and are completely specified there.

   /** Sees whether this list is empty. */
   virtual bool isEmpty() const = 0;

   /** Gets the current number of entries in this list. */
   virtual int getLength() const = 0;

   /** Removes the entry at a given position from this list. */
   virtual bool remove(int position) = 0;

   /** Removes all entries from this list. */
   virtual void clear() = 0;

   /** Gets the entry at the given position in this list. */
   virtual ItemType getEntry(int position) const = 0;
}; // end SortedListInterface
#endif

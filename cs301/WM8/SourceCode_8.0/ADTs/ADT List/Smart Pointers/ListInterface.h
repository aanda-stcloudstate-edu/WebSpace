//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** Interface for the ADT list
    @file ListInterface.h */

#ifndef LIST_INTERFACE_
#define LIST_INTERFACE_

template<class ItemType>
class ListInterface
{
public:
   /** Sees whether this list is empty.
    @return True if the list is empty; otherwise returns false. */
   virtual bool isEmpty() const = 0;
   
   /** Gets the current number of entries in this list.
    @return The integer number of entries currently in the list. */
   virtual int getLength() const = 0;
   
   /** Inserts an entry into this list at a given position.
    @pre  None.
    @post  If 1 <= position <= getLength() + 1 and the insertion is
       successful, newEntry is at the given position in the list,
       other entries are renumbered accordingly, and the returned
       value is true.
    @param position  The list position at which to insert someItem.
    @param someItem  The entry to insert into the list.
    @return  True if insertion is successful, or false if not. */
   virtual bool insert(int position, const ItemType& somItem) = 0;
   
   /** Removes the entry at a given position from this list.
    @pre  None.
    @post  If 1 <= position <= getLength() and the removal is successful,
       the entry at the given position in the list is removed, other
       items are renumbered accordingly, and the returned value is true.
    @param position  The list position of the entry to remove.
    @return  True if removal is successful, or false if not. */
   virtual bool remove(int position) = 0;
   
   /** Removes all entries from this list.
    @post  List contains no entries and the count of items is 0. */
   virtual void clear() = 0;
   
   /** Gets the entry at the given position in this list.
    @pre  1 <= position <= getLength().
    @post  The desired entry has been returned.
    @param position  The list position of the desired entry.
    @return  The entry at the given position. */
   virtual ItemType getEntry(int position) const = 0;
   
   /** Destroys object and frees memory allocated by object. */
   virtual ~ListInterface() {  }
}; // end ListInterface
#endif

   //  Created by Frank M. Carrano and Timothy M. Henry.
   //  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.


#include "Board.h"
#include "Queen.h"
#include <cassert>

Board::Board()
{
}

Board::~Board()
{
   clear();
}

void Board::clear()
{
   while (getNumQueens() > 0)
   {
      delete queens.back();
      queens.pop_back();
   }
}

void Board::display() const
{
   for (int i = 0; i < BOARD_SIZE; i++)
   {
      for (int j = 0; j < BOARD_SIZE; j++)
         cout << ' ' << (isQueen(i, j) ? 'Q' : '-');
      cout << endl;
   }
   cout << endl;
}

void Board::doEightQueens()
{
   clear();
   assert(placeQueens(new Queen(0, 0)));
}

int Board::getNumQueens() const
{
   return (int)queens.size();
}

const Queen* Board::getQueen(int index) const
{
   assert(index >= 0 && index < getNumQueens());
   return queens[index];
}

// Private Methods:

bool Board::isQueen(int inRow, int inCol) const
{
   for (int i = 0; i < getNumQueens(); i++)
   {
      const Queen* queenPtr = getQueen(i);
      if (inRow == queenPtr->getRow() && inCol == queenPtr->getCol())
         return true;
   }
   return false;
}

bool Board::placeQueens(Queen* queenPtr)
{
   bool isQueenPlaced = false;
   if (queenPtr->getCol() < BOARD_SIZE)
   {
      while (!isQueenPlaced && queenPtr->getRow() < BOARD_SIZE)
      {
         // If the Queen can be attacked, try moving  
         // it to the next row in the current column.
         bool underAttack = false;
         int col = 0;
         while (!underAttack && (col < getNumQueens()))
         {
            const Queen* queenPtr1 = getQueen(col);
            if (queenPtr->getRow() == queenPtr1->getRow())
               underAttack = true;
            else if (queenPtr->getRow() + queenPtr->getCol() == queenPtr1->getRow() + queenPtr1->getCol())
               underAttack = true;
            else if (queenPtr->getRow() - queenPtr->getCol() == queenPtr1->getRow() - queenPtr1->getCol())
               underAttack = true;
            else
               col++;
         }
         
         if (underAttack)
            queenPtr->nextRow();
         
         // Else put this queen on the board and
         // try putting a new Queen in row zero
         // of the next column.
         else
         {
            setQueen(queenPtr);
            Queen* newQueenPtr = new Queen(0, queenPtr->getCol() + 1);
            isQueenPlaced = placeQueens(newQueenPtr);

            // If it wasn't possible to put the new
            // Queen in the next column, backtrack
            // by deleting the new Queen and
            // by removing the last Queen placed and
            // moving it down one row.
            if (!isQueenPlaced)
            {
               delete newQueenPtr;
               removeQueen();
               queenPtr->nextRow();
            }  // end if
         }  // end if
      }  // end while
   }
   else
   {
      // Base case: Trying to place Queen in a non-existent column.
      // We're done and we don't need this Queen.
      delete queenPtr;
      isQueenPlaced = true;
     
   }  // end if
   
   return isQueenPlaced;
}  // end placeQueens

// Pre:  There is at least one Queen on the board.
// Post: The last Queen placed on the board is removed.
void Board::removeQueen()
{
   assert((int)queens.size() != 0);
   queens.pop_back();
}

void Board::setQueen(Queen* queenPtr)
{
   queens.push_back(queenPtr);
}

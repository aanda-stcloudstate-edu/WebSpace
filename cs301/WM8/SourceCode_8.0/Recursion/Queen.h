   //  Created by Frank M. Carrano and Timothy M. Henry.
   //  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.


/**  
    @file Queen.h */
#ifndef _QUEEN
#define _QUEEN

//#include "Board.h"
class Board; // Forward declaration of Board class

/** The Queen class. */
class Queen
{
private:
   int row; // Row (or prospective row) of queen if it is on the board
   int col; // Column (or prospective column) of queen if it is on the board
   
public:
   /** Places a queen in upper-left corner of board. */
   Queen();
         
   /** Places a queen in supplied location. */
   Queen(int inRow, int inCol);
   
   /** @return Column number. */
   int getCol() const;
   
   /** @return Row number. */
   int getRow() const;
   
   /** Moves queen to next row. */
   void nextRow();
   
}; // end Queen
#endif

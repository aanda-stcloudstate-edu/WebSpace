   //  Created by Frank M. Carrano and Timothy M. Henry.
   //  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

#include "Queen.h"
#include "Board.h"
#include <cassert>

Queen::Queen()
{
   row = 0;
   col = 0;
}

Queen::Queen(int inRow, int inCol)
{
   row = inRow;
   col = inCol;
}

int Queen::getCol() const
{
   return col;
}

int Queen::getRow() const
{
   return row;
}

// This method might move the Queen off the edge of the board; that's OK.
void Queen::nextRow()
{
   row++;
}

//
//  main.cpp
//  writeBackward
//
//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.


#include <iostream>
void writeBackward(std::string s);

int main(int argc, const char * argv[]) {
   // insert code here...
   std::cout << "Hello, World!\n";
   writeBackward("Now is the time!");
   std::cout<<std::endl;
    short x = 32760;
    short y= x + 10;
   std::cout << y;
    return 0;
}

//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Writes a character string backward.
 @pre  The string s to write backward.
 @post  None.
 @param s  The string to write backward. */
void writeBackward(std::string s)
{
   size_t length = s.size(); // Length of string
   if (length > 0)
   {
      // Write the last character
      std::cout << s.substr(length - 1, 1);
      
      // Write the rest of the string backward
      writeBackward(s.substr(0, length - 1)); // Point A
   } // end if
   
   // length == 0 is the base case - do nothing
}  // end writeBackward

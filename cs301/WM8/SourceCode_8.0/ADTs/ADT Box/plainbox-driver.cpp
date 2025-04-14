//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

#include <iostream>
#include <string>
#include "PlainBox.h"

int main()
{

   PlainBox<double> numberBox; // A box to hold a double
   PlainBox<std::string> nameBox;   // A box to hold a string object
   
   double health = 6.5;
   numberBox.setItem(health);
   
   std::string secretName = "Rumpelstiltskin";
   nameBox.setItem(secretName);
   
   std::cout << "numberBox.getItem() = " << numberBox.getItem() << std::endl;
   std::cout << "nameBox() = " << nameBox.getItem() << std::endl;
   
   return 0;
} // end main

/*
 numberBox.getItem() = 6.5
 nameBox() = Rumpelstiltskin
*/

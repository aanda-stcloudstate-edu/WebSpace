//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

#include <iostream>
#include <string>
#include "MagicBox.h"

int main()
{

   std::string rabbit = "Rabbit";
   std::string wand = "Wand";
   
   MagicBox<std::string> magicHat;
   magicHat.setItem(rabbit);
   std::cout << "magicHat.getItem() = " << magicHat.getItem() << std::endl;
   
   magicHat.setItem(wand);
   // magicHat still holds the rabbit
   std::cout << "magicHat.getItem() = " << magicHat.getItem() << std::endl;
   
   return 0;
} // end main

/*
 magicHat.getItem() = Rabbit
 magicHat.getItem() = Rabbit
*/

//� Created by Frank M. Carrano and Timothy M. Henry.
//� Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

#include <iostream> // For cout and cin
#include <string>   // For string objects
#include "Bag.h"    // For ADT bag
int main()
{
    std::string clubs[] = { "Joker", "Ace", "Two", "Three",
      "Four", "Five", "Six", "Seven",
      "Eight", "Nine", "Ten", "Jack",
      "Queen", "King" };
   
   // Create our bag to hold cards.
   Bag<std::string> grabBag;
   
   // Place six cards in the bag.
   grabBag.add(clubs[1]);
   grabBag.add(clubs[2]);
   grabBag.add(clubs[4]);
   grabBag.add(clubs[8]);
   grabBag.add(clubs[10]);
   grabBag.add(clubs[12]);
   
   // Get friend�s guess and check it.
   int guess = 0;
   while (!grabBag.isEmpty())
   {
      std::cout << "What is your guess?"
      << "(1 for Ace to 13 for King):";
      std::cin >> guess;
      
      // Is card in the bag?
      if (grabBag.contains(clubs[guess]))
      {
         // Good guess � remove card from the bag.
         std::cout << "You get the card!\n";
         grabBag.remove(clubs[guess]);
      }
      else
      {
         std::cout << "Sorry, card was not in the bag.\n";
      }  // end if
   }  // end while
   
   std::cout << "No more cards in the bag. Game over!\n";
   return 0;
}; // end main
/*
 What is your guess?(1 for Ace to 13 for King):3
 Sorry, card was not in the bag.
 What is your guess?(1 for Ace to 13 for King):5
 Sorry, card was not in the bag.
 What is your guess?(1 for Ace to 13 for King):2
 You get the card!
 What is your guess?(1 for Ace to 13 for King):1
 You get the card!
 What is your guess?(1 for Ace to 13 for King):10
 You get the card!
 What is your guess?(1 for Ace to 13 for King):12
 You get the card!
 What is your guess?(1 for Ace to 13 for King):8
 You get the card!
 What is your guess?(1 for Ace to 13 for King):8
 Sorry, card was not in the bag.
 What is your guess?(1 for Ace to 13 for King):4
 You get the card!
 No more cards in the bag. Game over!
 */

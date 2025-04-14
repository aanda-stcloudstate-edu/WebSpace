//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.


#include <iostream>
#include <string>
#include <unordered_map> // Note header name since this is in tr1
// Create a type since this is a long name to use (optional)
typedef std::unordered_map<std::string, int> StringKeyMap;
// Create a dummyMap object so we can get its hash function
StringKeyMap dummyMap;
// Capture the hash function for use in program
StringKeyMap::hasher myHashFunction = dummyMap.hash_function();
int main ()
{
   std::cout << "Hashing a String: " << myHashFunction("Hashing a String:") << std::endl;
   std::cout << "Smashing a String: " << myHashFunction ("Smashing a String:") << std::endl;
   return 0;
} // end main

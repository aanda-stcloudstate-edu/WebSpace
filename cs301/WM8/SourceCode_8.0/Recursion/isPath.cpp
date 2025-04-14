   ///  Created by Frank M. Carrano and Timothy M. Henry.
   //  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.


/** Tests whether a sequence of flights exists between two cities.
 @pre  originCity and destinationCity both exist in the flight map.
 @post  Cities visited during the search are marked as visited
    in the flight map.
 @param originCity  The origin city.
 @param destinationCity  The destination city.
 @return  True if a sequence of flights exists from originCity
    to destinationCity; otherwise returns false. */
bool Map::isPath(City originCity, City destinationCity)
{

   // Mark the current city as visited
   markVisited(originCity);
   
   // Base case: the destination is reached
   bool foundCity = (originCity == destinationCity);
   
   if (!foundCity) // Try a flight to each unvisited city
   {
      City nextCity = getNextCity(originCity);
      while (!foundCity && (nextCity != NO_CITY))
      {
         foundCity = isPath(nextCity, destinationCity);
         if (!foundCity)
            nextCity = getNextCity(originCity);
      } // end while
 
   }  // end if
   
   return nextCity;
}  // end isPath

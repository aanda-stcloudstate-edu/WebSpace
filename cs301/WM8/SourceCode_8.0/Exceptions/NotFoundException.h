//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** @file NotFoundException.h */

#ifndef NOT_FOUND_EXCEPTION_
#define NOT_FOUND_EXCEPTION_

#include <stdexcept>
#include <string>

class NotFoundException : public std::logic_error
{
public:
   NotFoundException(const std::string& message = "");
}; // end NotFoundException 
#endif

//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2025 Pearson Education, Hoboken, New Jersey.

/** @file NotFoundException.cpp */
#include "NotFoundException.h"  

NotFoundException::NotFoundException(const std::string& message)
      : std::logic_error("Precondition Violated Exception: " + message)
{
}  // end constructor

// End of implementation file.


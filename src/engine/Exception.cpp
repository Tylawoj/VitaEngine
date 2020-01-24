/** @file Exception.cpp
 *  @brief Implementation of functions for the Exception class.
 */

#include "Exception.h"
#include <iostream>

namespace vita
{
    Exception::Exception(const std::string& message)
    {
      this->message = message;
    }

    const char* Exception::What() const throw()
    {
      return message.c_str();
    }
}

/** @file Environment.h
 *  @brief Class used for throwing Engine exceptions.
 */

#ifndef _VITA_EXCEPTION_H_
#define _VITA_EXCEPTION_H_

#include <exception>
#include <string>

namespace vita
{
    class Exception : public std::exception
    {
        private:
            std::string message;
        public:
            /**
             * @brief Constructs an Exception, used in throwing one.
             * @param message The message of the Exception.
             */
            Exception(const std::string& message);
            /// @brief Throws an Exception and destroys it.
            virtual ~Exception() throw() {}
            /// @brief Displays the message of the Exception.
            virtual const char* What() const throw();
    };
}

#endif

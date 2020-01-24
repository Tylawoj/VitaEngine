/** @file Resources.cpp
 *  @brief Implementation of functions for the Resources class.
 */

#include "Resources.h"

namespace vita
{
    std::string Resources::ChangeSeparator(std::string _path)
    {
        /// Set the separator depending on detected OS.
        #ifdef _WIN32
        std::string correctSeparator = "\\";
        std::string wrongSeparator = "/";
        #elif defined __linux__
        std::string correctSeparator = "/";
        std::string wrongSeparator = "\\";
        #endif

        size_t startPosition = 0;

        while ((startPosition = _path.find(wrongSeparator)) != std::string::npos)
        {
            /// Replace all occurrences of the wrong separator in the file's path.
            _path.replace(startPosition, wrongSeparator.length(), correctSeparator);
        }

        return _path;
    }

    std::sr1::vector<std::string> Resources::ChangeSeparator(std::sr1::vector<std::string> _paths)
    {
        /// Set the separator depending on detected OS.
        #ifdef _WIN32
        std::string correctSeparator = "\\";
        std::string wrongSeparator = "/";
        #elif defined __linux__
        std::string correctSeparator = "/";
        std::string wrongSeparator = "\\";
        #endif

        for (std::sr1::vector<std::string>::iterator strIterator = _paths.begin(); strIterator != _paths.end(); strIterator++)
        {
            size_t startPosition = 0;

            while ((startPosition = (*strIterator).find(wrongSeparator)) != std::string::npos)
            {
                /// Replace all occurrences of the wrong separator in the file paths.
                (*strIterator).replace(startPosition, wrongSeparator.length(), correctSeparator);
            }
        }

        return _paths;
    }
}

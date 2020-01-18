#include "Resources.h"

namespace vita
{
    void Resources::ChangeSeparator(std::string& _path)
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
            _path.replace(startPosition, wrongSeparator.length(), correctSeparator);
        }
    }
}

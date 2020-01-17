#include <exception>
#include <string>

namespace vita
{
    class Exception : public std::exception
    {
        private:
            std::string message;
        public:
            Exception(const std::string& message);
            virtual ~Exception() throw() {}
            virtual const char* What() const throw();
    };
}

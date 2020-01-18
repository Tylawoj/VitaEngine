#include "Exception.h"
#include "Resource.h"
#include <sr1/memory>
#include <sr1/noncopyable>
#include <iostream>
#include <list>
#include <string>

namespace vita
{
    class Core;

    class Resources : public std::sr1::noncopyable
    {
        friend class vita::Core;

        private:
            std::list<std::sr1::shared_ptr<Resource>> m_resources;
        public:
            template <typename T> std::sr1::shared_ptr<T> Load(std::string _string)
            {
                try
                {
                    std::sr1::shared_ptr<T> resource = std::make_shared<T>();
                    resource->OnLoad(_string);
                    m_resources.push_back(resource);

                    return resource;
                }

                catch (std::exception& e)
                {
                    std::cout << "System Exception: " << e.what() << std::endl;
                    std::cout << "Could not load a resource with the specified path: " << _string << std::endl;
                }

                catch (Exception& e)
                {
                    std::cout << "Engine Exception: " << e.What() << std::endl;
                    std::cout << "Could not load a resource with the specified path: " << _string << std::endl;
                }
            }
    };
}

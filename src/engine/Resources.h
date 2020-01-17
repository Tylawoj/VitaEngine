#include "Exception.h"
#include <sr1/memory>
#include <sr1/noncopyable>
#include <iostream>
#include <list>
#include <string>

namespace vita
{
    class Core;
    class Resource;

    class Resources : public std::sr1::noncopyable
    {
        friend class vita::Core;

        private:
            std::list<std::sr1::shared_ptr<Resource>> m_resources;
        public:
            template <typename T> std::sr1::shared_ptr<T> Create()
            {
                std::sr1::shared_ptr<T> resource = std::make_shared<T>();
                m_resources.push_back(resource);

                return resource;
            }

            template <typename T> std::sr1::shared_ptr<T> Load(std::string _string)
            {
                try
                {
                    std::sr1::shared_ptr<T> resource = std::make_shared<T>(_string);
                    m_resources.push_back(resource);

                    return resource;
                }

                catch (Exception& e)
                {
                    std::cout << "Exception: " << e.What() << std::endl;
                    std::cout << "A nullptr "
                }
            }
    };
}

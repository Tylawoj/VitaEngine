#ifndef _VITA_RESOURCES_H_
#define _VITA_RESOURCES_H_

#include "Exception.h"
#include "Resource.h"
#include <sr1/memory>
#include <sr1/noncopyable>
#include <sr1/vector>
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
            std::sr1::weak_ptr<Core> m_core;
            std::list<std::sr1::shared_ptr<Resource>> m_resources;
            std::string ChangeSeparator(std::string _path);
            std::sr1::vector<std::string> ChangeSeparator(std::sr1::vector<std::string> _paths);
        public:
            template <typename T> std::sr1::shared_ptr<T> Load(std::string _path)
            {
                std::sr1::shared_ptr<T> resource;

                try
                {
                    resource = std::make_shared<T>();
                    std::string newPath = ChangeSeparator(_path);
                    resource->m_core = m_core;
                    resource->m_alive = true;
                    resource->OnLoad(newPath);
                    m_resources.push_back(resource);
                }

                catch (Exception& e)
                {
                    std::cout << "Engine Exception: " << e.What() << std::endl;
                    std::cout << "Could not load a resource with the specified path: " << _path << std::endl;
                    resource = NULL;
                }

                catch (std::exception& e)
                {
                    std::cout << "System Exception: " << e.what() << std::endl;
                    std::cout << "Could not load a resource with the specified path: " << _path << std::endl;
                    resource = NULL;
                }

                return resource;
            }

            template <typename T> std::sr1::shared_ptr<T> Load(std::sr1::vector<std::string> _paths)
            {
                std::sr1::shared_ptr<T> resource;

                try
                {
                    resource = std::make_shared<T>();
                    std::sr1::vector<std::string> newPath = ChangeSeparator(_paths);
                    resource->m_core = m_core;
                    resource->m_alive = true;
                    resource->OnLoad(newPath);
                    m_resources.push_back(resource);
                }

                catch (Exception& e)
                {
                    std::cout << "Engine Exception: " << e.What() << std::endl;
                    std::cout << "Could not load a resource with one of the specified paths: " << _paths.at(0) << std::endl;
                    resource = NULL;
                }

                catch (std::exception& e)
                {
                    std::cout << "System Exception: " << e.what() << std::endl;
                    std::cout << "Could not load a resource with one of the specified paths: " << _paths.at(0) << std::endl;
                    resource = NULL;
                }

                return resource;
            }
    };
}

#endif

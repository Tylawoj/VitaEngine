/** @file Resources.h
 *  @brief Class for creating and handling resources, as well as converting file paths.
 */

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
        /** Core is set as a friend class to set itself as a weak_ptr during
         *  the construction of the Resources object. */
        friend class vita::Core;

        private:
            std::sr1::weak_ptr<Core> m_core; ///< A weak_ptr to Core, used by resources.
            std::list<std::sr1::shared_ptr<Resource>> m_resources; ///< List of currently used resources.
            /**
             * @brief Converts a file path to be correct, depending on currently used OS.
             * @param _path A file path.
             * @return A corrected file path.
             */
            std::string ChangeSeparator(std::string _path);
            /**
             * @brief Converts file paths from a vector to be correct, depending on currently used OS.
             * @param _paths A vector of file paths.
             * @return A vector of corrected file paths.
             */
            std::sr1::vector<std::string> ChangeSeparator(std::sr1::vector<std::string> _paths);
        public:
            /**
             * @brief Loads and returns a Resource of the specified type to the user, storing it in the Resources.
             * @param _path A file path used by the Resource.
             * @return A Resource of a specified type.
             */
            template <typename T> std::sr1::shared_ptr<T> Load(std::string _path)
            {
                std::sr1::shared_ptr<T> resource;

                try
                {
                    resource = std::make_shared<T>();
                    /// Change the path depending on used OS.
                    std::string newPath = ChangeSeparator(_path);
                    resource->m_core = m_core;
                    resource->m_alive = true;
                    /// Load the resource.
                    resource->OnLoad(newPath);
                    /// Push it back onto the stored resources list.
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

            /**
             * @brief Loads and returns a Resource of the specified type to the user, storing it in the Resources.
             * @param _paths A vector of file paths used by the Resource.
             * @return A Resource of a specified type.
             */
            template <typename T> std::sr1::shared_ptr<T> Load(std::sr1::vector<std::string> _paths)
            {
                std::sr1::shared_ptr<T> resource;

                try
                {
                    resource = std::make_shared<T>();
                    /// Change the file paths depending on used OS.
                    std::sr1::vector<std::string> newPath = ChangeSeparator(_paths);
                    resource->m_core = m_core;
                    resource->m_alive = true;
                    /// Load the resource.
                    resource->OnLoad(newPath);
                    /// Push it back onto the stored resources list.
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

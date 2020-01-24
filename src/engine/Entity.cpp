/** @file Entity.cpp
 *  @brief Implementation of functions for the Entity class.
 */

#include "Entity.h"
#include "Component.h"
#include "Core.h"
#include <iostream>

namespace vita
{
    void Entity::CheckForDeadComponents()
    {
        for (std::list<std::sr1::shared_ptr<Component>>::iterator componentIterator = m_components.begin(); componentIterator != m_components.end();)
        {
            if (!(*componentIterator)->IsAlive())
            {
                componentIterator = m_components.erase(componentIterator);
            }

            else
            {
                componentIterator++;
            }
        }
    }

    void Entity::CollisionUpdate()
    {
        for (std::list<std::sr1::shared_ptr<Component>>::iterator componentIterator = m_components.begin(); componentIterator != m_components.end(); componentIterator++)
        {
            try
            {
                /// Calls the OnCollisionUpdate() functions in each Component.
                (*componentIterator)->OnCollisionUpdate();
            }

            catch (Exception& e)
            {
                std::cout << "Engine Exception: " << e.What() << std::endl;
                std::cout << "The component will been removed." << std::endl;

                (*componentIterator)->Kill();
            }

            catch (std::exception& e)
            {
                std::cout << "System Exception: " << e.what() << std::endl;
                std::cout << "The component will be removed." << std::endl;

                (*componentIterator)->Kill();
            }
        }

        /// Checks whether there are any dead components after this call (exception checking).
        CheckForDeadComponents();
    }

    void Entity::Display()
    {
        for (std::list<std::sr1::shared_ptr<Component>>::iterator componentIterator = m_components.begin(); componentIterator != m_components.end(); componentIterator++)
        {
            try
            {
                /// Calls the OnDisplay() functions in Components of each Entity stored.
                (*componentIterator)->OnDisplay();
            }

            catch (Exception& e)
            {
                std::cout << "Engine Exception: " << e.What() << std::endl;
                std::cout << "The component will be removed." << std::endl;

                /// Kill the component if it has thrown an exception.
                (*componentIterator)->Kill();
            }

            catch (std::exception& e)
            {
                std::cout << "System Exception: " << e.what() << std::endl;
                std::cout << "The component will be removed." << std::endl;

                /// Kill the component if it has thrown an exception.
                (*componentIterator)->Kill();
            }
        }

        /// Checks whether there are any dead components after this call (exception checking).
        CheckForDeadComponents();
    }

    std::sr1::shared_ptr<Core> Entity::GetCore()
    {
        return m_core.lock();
    }

    void Entity::GUI()
    {
        for (std::list<std::sr1::shared_ptr<Component>>::iterator componentIterator = m_components.begin(); componentIterator != m_components.end(); componentIterator++)
        {
            try
            {
                /// Calls the OnGUI() functions in Components of each Entity stored.
                (*componentIterator)->OnGUI();
            }

            catch (Exception& e)
            {
                std::cout << "Engine Exception: " << e.What() << std::endl;
                std::cout << "The component will been removed." << std::endl;

                /// Kill the component if it has thrown an exception.
                (*componentIterator)->Kill();
            }

            catch (std::exception& e)
            {
                std::cout << "System Exception: " << e.what() << std::endl;
                std::cout << "The component will be removed." << std::endl;

                /// Kill the component if it has thrown an exception.
                (*componentIterator)->Kill();
            }
        }

        /// Checks whether there are any dead components after this call (exception checking).
        CheckForDeadComponents();
    }

    void Entity::Init()
    {
        for (std::list<std::sr1::shared_ptr<Component>>::iterator componentIterator = m_components.begin(); componentIterator != m_components.end(); componentIterator++)
        {
            try
            {
                /// Calls the OnInit() functions in Components of each Entity stored.
                (*componentIterator)->OnInit();
            }

            catch (Exception& e)
            {
                std::cout << "Engine Exception: " << e.What() << std::endl;
                std::cout << "The component will be removed." << std::endl;

                /// Kill the component if it has thrown an exception.
                (*componentIterator)->Kill();
            }

            catch (std::exception& e)
            {
                std::cout << "System Exception: " << e.what() << std::endl;
                std::cout << "The component will be removed." << std::endl;

                /// Kill the component if it has thrown an exception.
                (*componentIterator)->Kill();
            }
        }

        /// Checks whether there are any dead components after this call (exception checking).
        CheckForDeadComponents();
    }

    void Entity::Tick()
    {
        for (std::list<std::sr1::shared_ptr<Component>>::iterator componentIterator = m_components.begin(); componentIterator != m_components.end(); componentIterator++)
        {
            try
            {
                /// Calls the OnTick() functions in Components of each Entity stored.
                (*componentIterator)->OnTick();
            }

            catch (Exception& e)
            {
                std::cout << "Engine Exception: " << e.What() << std::endl;
                std::cout << "The component will been removed." << std::endl;

                /// Kill the component if it has thrown an exception.
                (*componentIterator)->Kill();
            }

            catch (std::exception& e)
            {
                std::cout << "System Exception: " << e.what() << std::endl;
                std::cout << "The component will be removed." << std::endl;

                /// Kill the component if it has thrown an exception.
                (*componentIterator)->Kill();
            }   
        }

        /// Checks whether there are any dead components after this call (exception checking).
        CheckForDeadComponents();
    }
}

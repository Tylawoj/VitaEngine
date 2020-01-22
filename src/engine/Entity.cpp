#include "Entity.h"
#include "Component.h"
#include "Core.h"

#include <iostream>

namespace vita
{
    std::sr1::shared_ptr<Core> Entity::GetCore()
    {
        return m_core.lock();
    }

    void Entity::CollisionUpdate()
    {
        for (std::list<std::sr1::shared_ptr<Component>>::iterator componentIterator = m_components.begin(); componentIterator != m_components.end(); componentIterator++)
        {
            try
            {
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

        CheckForDeadComponents();
    }


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

    void Entity::Init()
    {
        for (std::list<std::sr1::shared_ptr<Component>>::iterator componentIterator = m_components.begin(); componentIterator != m_components.end(); componentIterator++)
        {
            try
            {
                (*componentIterator)->OnInit();
            }

            catch (Exception& e)
            {
                std::cout << "Engine Exception: " << e.What() << std::endl;
                std::cout << "The component will be removed." << std::endl;

                (*componentIterator)->Kill();
            }

            catch (std::exception& e)
            {
                std::cout << "System Exception: " << e.what() << std::endl;
                std::cout << "The component will be removed." << std::endl;

                (*componentIterator)->Kill();
            }
        }

        CheckForDeadComponents();
    }

    void Entity::Tick()
    {
        for (std::list<std::sr1::shared_ptr<Component>>::iterator componentIterator = m_components.begin(); componentIterator != m_components.end(); componentIterator++)
        {
            try
            {
                (*componentIterator)->OnTick();
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

        CheckForDeadComponents();
    }

    void Entity::Display()
    {
        for (std::list<std::sr1::shared_ptr<Component>>::iterator componentIterator = m_components.begin(); componentIterator != m_components.end(); componentIterator++)
        {
            try
            {
                (*componentIterator)->OnDisplay();
            }

            catch (Exception& e)
            {
                std::cout << "Engine Exception: " << e.What() << std::endl;
                std::cout << "The component will be removed." << std::endl;

                (*componentIterator)->Kill();
            }

            catch (std::exception& e)
            {
                std::cout << "System Exception: " << e.what() << std::endl;
                std::cout << "The component will be removed." << std::endl;

                (*componentIterator)->Kill();
            } 
        }

        CheckForDeadComponents();
    }
}

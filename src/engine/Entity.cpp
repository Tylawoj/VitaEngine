#include "Entity.h"
#include "Component.h"
#include "Exception.h"

#include <iostream>

namespace vita
{
    std::shared_ptr<Core> Entity::GetCore()
    {
        return m_core.lock();
    }

    void Entity::Init()
    {
        std::list<std::sr1::shared_ptr<Component>>::iterator componentIterator = m_components.begin();

        while (componentIterator != m_components.end())
        {
            bool exceptionCaught = false;

            try
            {
                (*componentIterator)->OnInit();
            }

            catch (Exception& e)
            {
                std::cout << "Exception: " << e.What() << std::endl;
                std::cout << "The component has been removed." << std::endl;

                componentIterator = m_components.erase(componentIterator);
                exceptionCaught = true;
            }

            if (!exceptionCaught)
            {
                componentIterator++;
            }
        }
    }

    void Entity::Tick()
    {
        std::list<std::sr1::shared_ptr<Component>>::iterator componentIterator = m_components.begin();

        while (componentIterator != m_components.end())
        {
            bool exceptionCaught = false;

            try
            {
                (*componentIterator)->OnTick();
            }

            catch (Exception& e)
            {
                std::cout << "Exception: " << e.What() << std::endl;
                std::cout << "The component has been removed." << std::endl;

                componentIterator = m_components.erase(componentIterator);
                exceptionCaught = true;
            }

            if (!exceptionCaught)
            {
                componentIterator++;
            }
        }
    }

    void Entity::Display()
    {
        std::list<std::sr1::shared_ptr<Component>>::iterator componentIterator = m_components.begin();

        while (componentIterator != m_components.end())
        {
            bool exceptionCaught = false;

            try
            {
                (*componentIterator)->OnDisplay();
            }

            catch (Exception& e)
            {
                std::cout << "Exception: " << e.What() << std::endl;
                std::cout << "The component has been removed." << std::endl;

                componentIterator = m_components.erase(componentIterator);
                exceptionCaught = true;
            }

            if (!exceptionCaught)
            {
                componentIterator++;
            }
        }
    }
}

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
        for (std::list<std::sr1::shared_ptr<Component>>::iterator componentIterator = m_components.begin(); componentIterator != m_components.end(); componentIterator++)
        {
            try
            {
                (*componentIterator)->OnInit();
            }

            catch (Exception& e)
            {
                std::cout << "Exception: " << e.What() << std::endl;
                (*componentIterator)->Kill();
            }
        }
    }

    void Entity::Tick()
    {
        std::list<std::shared_ptr<Component>>::iterator componentIterator;

        for (componentIterator = m_components.begin(); componentIterator != m_components.end(); componentIterator++)
        {
            try
            {
                (*componentIterator)->OnTick();
            }

            catch (Exception& e)
            {
                std::cout << "Exception: " << e.What() << std::endl;
                (*componentIterator)->Kill();
                m_components.erase(componentIterator);
            }
        }
    }

    void Entity::Display()
    {
        std::list<std::shared_ptr<Component>>::iterator componentIterator;

        for (componentIterator = m_components.begin(); componentIterator != m_components.end(); componentIterator++)
        {
            try
            {
                (*componentIterator)->OnDisplay();
            }

            catch (Exception& e)
            {
                std::cout << "Exception: " << e.What() << std::endl;
                (*componentIterator)->Kill();
                m_components.erase(componentIterator);
            }
        }
    }

    void Entity::Kill()
    {
        m_aliveStatus = false;
    }

    bool Entity::IsAlive()
    {
        return m_aliveStatus;
    }
}

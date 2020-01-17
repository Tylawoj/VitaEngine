#include "Core.h"
#include "Entity.h"
#include "Resource.h"
#include "Resources.h"
#include <chrono>

namespace vita
{
    std::sr1::shared_ptr<Entity> Core::AddEntity()
    {
        std::sr1::shared_ptr<Entity> entity = std::make_shared<Entity>();
        m_entities.push_back(entity);
        entity->m_core = m_self;

        return entity;
    }

    std::sr1::shared_ptr<Core> Core::Initialize()
    {
        std::sr1::shared_ptr<Core> core = std::make_shared<Core>();
        core->m_self = core;

        return core;
    }

    void Core::Run()
    {
        std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
        std::chrono::system_clock::time_point now;

        while (m_isRunning)
        {
            for (std::list<std::sr1::shared_ptr<Entity>>::iterator entityIterator = m_entities.begin(); entityIterator != m_entities.end(); entityIterator++)
            {
                (*entityIterator)->Tick();
            }

            for (std::list<std::sr1::shared_ptr<Entity>>::iterator entityIterator = m_entities.begin(); entityIterator != m_entities.end(); entityIterator++)
            {
                (*entityIterator)->Display();
            }

            now = std::chrono::system_clock::now();

            if (std::chrono::duration_cast<std::chrono::milliseconds>(now - start).count() > 1000)
            {
                std::list<std::sr1::shared_ptr<Resource>>::iterator resourceIterator;

                while (resourceIterator != m_resources->m_resources.end())
                {
                    bool resourceRemoved = false;

                    if (resourceIterator->use_count() == 1)
                    {
                        resourceIterator = m_resources->m_resources.erase(resourceIterator);
                        resourceRemoved = true;
                    }

                    if (!resourceRemoved)
                    {
                        resourceIterator++;
                    }
                }

                start = std::chrono::system_clock::now();
            }
        }
    }
}

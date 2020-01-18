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

    std::sr1::shared_ptr<Core> Core::Init()
    {
        std::sr1::shared_ptr<Core> core = std::make_shared<Core>();
        core->m_self = core;

        return core;
    }

    void Core::Start()
    {
        m_isRunning = true;
    }

    void Core::Stop()
    {
        m_isRunning = false;
    }

    void Core::CheckForDeadResources()
    {
        for (std::list<std::sr1::shared_ptr<Resource>>::iterator resourceIterator = m_resources->m_resources.begin();
             resourceIterator != m_resources->m_resources.end();)
        {
            if (!(*resourceIterator)->IsAlive())
            {
                resourceIterator = m_resources->m_resources.erase(resourceIterator);
            }

            else
            {
                resourceIterator++;
            }
        }
    }

    void Core::Run()
    {
        std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
        std::chrono::system_clock::time_point now;

        for (std::list<std::sr1::shared_ptr<Entity>>::iterator entityIterator = m_entities.begin(); entityIterator != m_entities.end(); entityIterator++)
        {
            (*entityIterator)->Init();
        }

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

                for (std::list<std::sr1::shared_ptr<Resource>>::iterator resourceIterator = m_resources->m_resources.begin();
                     resourceIterator != m_resources->m_resources.end(); resourceIterator++)
                {
                    if (resourceIterator->use_count() == 1)
                    {
                        (*resourceIterator)->Kill();
                    }
                }

                CheckForDeadResources();

                start = std::chrono::system_clock::now();
            }
        }
    }
}

#include "Core.h"
#include "Entity.h"

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

            for
        }
    }
}

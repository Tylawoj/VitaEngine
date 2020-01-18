#include "Component.h"
#include "Core.h"
#include "Entity.h"
#include "Environment.h"
#include "Keyboard.h"

namespace vita
{

std::sr1::shared_ptr<Entity> Component::GetEntity()
{
    return m_entity.lock();
}

std::sr1::shared_ptr<Core> Component::GetCore()
{
    return m_entity.lock()->GetCore();
}

bool Component::IsAlive()
{
    return m_alive;
}

void Component::Kill()
{
    m_alive = false;
}
//std::shared_ptr<Keyboard> Component::getKeyboard()
//{
//}
//
//std::shared_ptr<Environment> Component::getEnvironment()
//{
//}
}

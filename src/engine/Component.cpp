#include "Component.h"
#include "Core.h"
#include "Entity.h"
#include "Environment.h"
#include "Keyboard.h"

namespace vita
{

//void Component::Update()
//{
//    OnUpdate();
//}

void Component::Kill()
{
    m_status = false;
}

bool Component::IsAlive()
{
    return m_status;
}

std::sr1::shared_ptr<Entity> Component::GetEntity()
{
    return m_entity.lock();
}

std::sr1::shared_ptr<Core> Component::GetCore()
{
    return m_entity.lock()->GetCore();
}
//std::shared_ptr<Keyboard> Component::getKeyboard()
//{
//}
//
//std::shared_ptr<Environment> Component::getEnvironment()
//{
//}
}

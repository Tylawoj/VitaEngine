/** @file Component.cpp
 *  @brief Implementation of functions for the Component class.
 *
 *  The functions below serve as shortcuts for Components to
 *  obtain major class members of the Core.
 */

#include "Component.h"
#include "Camera.h"
#include "Core.h"
#include "Entity.h"
#include "Environment.h"
#include "GUI.h"
#include "Input.h"

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

    std::sr1::shared_ptr<Environment> Component::GetEnvironment()
    {
        return m_entity.lock()->GetCore()->GetEnvironment();
    }

    std::sr1::shared_ptr<GUI> Component::GetGUI()
    {
        return m_entity.lock()->GetCore()->GetGUI();
    }

    std::sr1::shared_ptr<Input> Component::GetInput()
    {
        return m_entity.lock()->GetCore()->GetInput();
    }

    std::sr1::shared_ptr<Resources> Component::GetResources()
    {
        return m_entity.lock()->GetCore()->GetResources();
    }

    std::sr1::shared_ptr<Camera> Component::GetCurrentCamera()
    {
        return m_entity.lock()->GetCore()->GetCurrentCamera();
    }

    bool Component::IsAlive()
    {
        return m_alive;
    }

    void Component::Kill()
    {
        m_alive = false;
    }
}

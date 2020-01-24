/** @file Resource.cpp
 *  @brief Implementation of functions for the Resource class.
 */

#include "Resource.h"
#include "Core.h"
#include <rend/rend.h>

namespace vita
{
    std::sr1::shared_ptr<Core> Resource::GetCore()
    {
        return m_core.lock();
    }

    std::sr1::shared_ptr<rend::Context> Resource::GetContext()
    {
        /// Shortcut function to Core.
        return m_core.lock()->GetContext();
    }

    bool Resource::IsAlive()
    {
        return m_alive;
    }

    void Resource::Kill()
    {
        m_alive = false;
    }
}

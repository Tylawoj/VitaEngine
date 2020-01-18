#include "Resource.h"

namespace vita
{
    bool Resource::IsAlive()
    {
        return m_alive;
    }

    void Resource::Kill()
    {
        m_alive = false;
    }
}

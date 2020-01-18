#include "Environment.h"

namespace vita
{
    void Environment::Init()
    {
        m_previousTick = std::chrono::system_clock::now();
    }

    float Environment::GetDeltaTime()
    {
        std::chrono::system_clock::time_point deltaTime = std::chrono::system_clock::now();
        return std::chrono::duration_cast<std::chrono::milliseconds>(deltaTime - m_previousTick).count() / 1000.0f;
    }
}

/** @file Environment.cpp
 *  @brief Implementation of functions for the Environment class.
 */

#include "Environment.h"

namespace vita
{
    float Environment::GetDeltaTime()
    {
        return m_deltaTime;
    }

    void Environment::Init()
    {
        m_previousTick = std::chrono::system_clock::now(); ///< Set the previous tick to current time.
        m_deltaTime = 0.0f; ///< Initialize the delta time to 0.
    }

    void Environment::OnTick()
    {
        std::chrono::system_clock::time_point currentTick = std::chrono::system_clock::now();
        /// Calculate the delta time from the difference between now and the previous tick.
        m_deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTick - m_previousTick).count() / 1000.0f;
        /// Store the current tick.
        m_previousTick = currentTick;
    }
}

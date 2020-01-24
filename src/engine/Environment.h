/** @file Environment.h
 *  @brief Class for storing information about the environment (delta time).
 */

#include <chrono>

namespace vita
{
    class Environment
    {
        private:
            float m_deltaTime; ///< The time difference between now and the previous tick.
            std::chrono::system_clock::time_point m_previousTick; ///< Stores the time of the previous tick.
        public:
            /**
             * @brief Returns a delta time.
             * @return A delta time.
             */
            float GetDeltaTime();
            /// @brief Initializes the member variables.
            void Init();
            /// @brief Calculates the delta time with each tick.
            void OnTick();
    };
}

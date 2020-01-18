#include <chrono>

namespace vita
{
    class Environment
    {
        private:
            std::chrono::system_clock::time_point m_previousTick;
        public:
            void Init();
            float GetDeltaTime();
    };
}

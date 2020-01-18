#include "Component.h"
#include <SDL2/SDL.h>

namespace vita
{
    class Screen : public Component
    {
        private:
            int m_height;
            int m_width;
            SDL_Window* m_window;
        public:
            int GetWidth();
            int GetHeight();
    };
}

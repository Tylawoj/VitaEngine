#include "Component.h"
#include <SDL2/SDL.h>

namespace vita
{
    class Screen
    {
        private:
            int m_height;
            int m_width;
            std::string m_title;
            SDL_Window* m_window;
            SDL_GLContext m_glContext;
        public:
            Screen(std::string _title, int _width, int _height, int _samples);
            ~Screen();
            void GLSwapWindow();
            void ClearScreen();
            int GetWidth();
            int GetHeight();
    };
}

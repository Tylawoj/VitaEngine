#include <sr1/vector>
#include <SDL2/SDL.h>

namespace vita
{
    class Input
    {
        private:
            SDL_Event m_event;
            std::sr1::vector<bool> m_keyCodes;
            std::sr1::vector<bool> m_keyCodesPressed;
            std::sr1::vector<bool> m_keyCodesReleased;
            std::sr1::vector<bool> m_mouseButtons;
            std::sr1::vector<bool> m_mouseButtonsPressed;
            std::sr1::vector<bool> m_mouseButtonsReleased;
            int m_mouseMotionX;
            int m_mouseMotionY;
        public:
            Input();
            void ClearInput();
            bool GetKey(int _keyCode);
            bool GetKeyPressed(int _keyCode);
            bool GetKeyReleased(int _keyCode);
            bool GetMouseButton(int _mouseButton);
            bool GetMouseButtonPressed(int _mouseButton);
            bool GetMouseButtonReleased(int _mouseButton);
            int GetMouseMotionX();
            int GetMouseMotionY();
            void UpdateInput();
    };
}

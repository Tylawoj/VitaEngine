/** @file Input.h
 *  @brief Class for storing any keyboard and mouse input.
 */

#include <SDL2/SDL.h>
#include <sr1/vector>

namespace vita
{
    class Core;

    class Input
    {
        friend class vita::Core;

        private:
            std::sr1::weak_ptr<Core> m_core; ///< A weak_ptr to Core, used to stop it if the user quits the program.
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
            /// @brief Initializes the member variables.
            Input();
            /// @brief Clears the stored pressed/released keycodes/mouseButtons.
            void ClearInput();
            /**
             * @brief Returns if the key is pressed/held.
             * @param _keyCode The specified key code.
             * @return Whether the key has been pressed/held or not.
             */
            bool GetKey(int _keyCode);
            /**
             * @brief Returns if the key has been pressed (but not held).
             * @param _keyCode The specified key code.
             * @return Whether the key has been pressed or not.
             */
            bool GetKeyPressed(int _keyCode);
            /**
             * @brief Returns if the key has been released.
             * @param _keyCode The specified key code.
             * @return Whether the key has been released or not.
             */
            bool GetKeyReleased(int _keyCode);
            /**
             * @brief Returns if a mouse button is pressed/held.
             * @param _mouseButton The specified mouse button.
             * @return Whether the mouse button is pressed/held or not.
             */
            bool GetMouseButton(int _mouseButton);
            /**
             * @brief Returns if the mouse button has been pressed (but not held).
             * @param _mouseButton The specified mouse button.
             * @return Whether the mouse button has been pressed or not.
             */
            bool GetMouseButtonPressed(int _mouseButton);
            /**
             * @brief Returns if the mouse button has been released.
             * @param _mouseButton The specified mouse button.
             * @return Whether the mouse button has been released or not.
             */
            bool GetMouseButtonReleased(int _mouseButton);
            /**
             * @brief Returns x-axis mouse motion.
             * @return X-axis mouse motion.
             */
            int GetMouseMotionX();
            /**
             * @brief Returns y-axis mouse motion.
             * @return Y-axis mouse motion.
             */
            int GetMouseMotionY();
            /// @brief Updates the inputs for this frame.
            void UpdateInput();
    };
}

/** @file Screen.h
 *  @brief Class for storing the SDL's window used for rendering.
 */

#include "Component.h"
#include <SDL2/SDL.h>

namespace vita
{
    class Screen
    {
        private:
            SDL_GLContext m_glContext;
            int m_height;
            std::string m_title;
            int m_width;
            SDL_Window* m_window;
        public:
            /**
             * @brief Creates a SDL_window with a GLContext for rendering to the window.
             * @param _title The title of the window.
             * @param _width The width of the window.
             * @param _height The height of the window.
             * @param _samples The amount of samples used for MSAA.
             */
            Screen(std::string _title, int _width, int _height, int _samples);
            /// @brief Destroys the window and GLContext, and quits SDL.
            ~Screen();
            /// @brief Clears the screen for rendering.
            void ClearScreen();
            /**
             * @brief Returns the height of the window.
             * @return The height of the window.
             */
            int GetHeight();
            /**
             * @brief Returns the width of the window.
             * @return The width of the window.
             */
            int GetWidth();
            /// @brief Swaps the SDL window with the OpenGL render.
            void GLSwapWindow();
    };
}

/** @file Screen.cpp
 *  @brief Implementation of functions for the Screen class.
 */

#include "Exception.h"
#include "Screen.h"
#include <GL/glew.h>

namespace vita
{
    Screen::Screen(std::string _title, int _width, int _height, int _samples)
    {
        /// Try to initialize SDL.
        if (SDL_Init(SDL_INIT_VIDEO) < 0)
        {
            std::string exceptionMsg = "Could not initialize SDL: ";
            exceptionMsg += SDL_GetError();

            throw Exception(exceptionMsg);
        }

        /// Ensure the amount of samples for MSAA is above 0.
        if (_samples < 1)
        {
            std::cout << "Engine Warning: Amount of samples set by user to a value below 1. " << std::endl;
            std::cout << "Automatically changed the amount of samples to 1." << std::endl;

            _samples = 1;
        }

        /// Ensure the amount of samples for MSAA is not above 8.
        else if (_samples > 8)
        {
            std::cout << "Engine Warning: Amount of samples set by user to a value above the max value of 8. " << std::endl;
            std::cout << "Automatically changed the amount of samples to 8." << std::endl;

            _samples = 8;
        }

        /// If there is more than one sample set, enable MSAA.
        if (_samples > 1)
        {
            SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
            SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, _samples);
        }

        /// Create a SDL window with the specified title, width and height (MSAA as well).
        m_window = SDL_CreateWindow(_title.c_str(),
                                    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                    _width, _height,
                                    SDL_WINDOW_OPENGL);

        if (!m_window)
        {
            std::string exceptionMsg = "SDL failed to create a window: ";
            exceptionMsg += SDL_GetError();
            exceptionMsg += "\nPossible solution: If using MSAA, make sure that the currently used GPU supports multisampling.";

            throw Exception(exceptionMsg);
        }

        /// Create an OpenGL context using SDL's window.
        m_glContext = SDL_GL_CreateContext(m_window);

        if (!m_glContext)
        {
            std::string exceptionMsg = "SDL failed to create an OpenGL context: ";
            exceptionMsg += SDL_GetError();

            throw Exception(exceptionMsg);
        }

        m_width = _width;
        m_height = _height;
    }

    Screen::~Screen()
    {
        /// Delete the OpenGL's context and SDL window.
        SDL_GL_DeleteContext(m_glContext);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
    }

    void Screen::ClearScreen()
    {
        /// Clear the window with a black colour and clear the depth and colour buffer.
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    int Screen::GetHeight()
    {
        return m_height;
    }

    int Screen::GetWidth()
    {
        return m_width;
    }

    void Screen::GLSwapWindow()
    {
        SDL_GL_SwapWindow(m_window);
    }
}


#include "Exception.h"
#include "Screen.h"
#include <GL/glew.h>

namespace vita
{
    Screen::Screen(std::string _title, int _width, int _height, int _samples)
    {
        if (_samples < 1)
        {
            std::cout << "Engine Warning: Amount of samples set by user to a value below 1. " << std::endl;
            std::cout << "Automatically changed the amount of samples to 1." << std::endl;

            _samples = 1;
        }

        else if (_samples > 1)
        {
            SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
            SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, _samples);
        }

        m_window = SDL_CreateWindow(_title.c_str(),
                                    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                    _width, _height,
                                    SDL_WINDOW_OPENGL);

        if (!m_window)
        {
            std::string exceptionMsg = "Engine Exception: SDL failed to create a window: ";
            exceptionMsg += SDL_GetError();

            throw Exception(exceptionMsg);
        }

        m_glContext = SDL_GL_CreateContext(m_window);

        if (!m_glContext)
        {
            std::string exceptionMsg = "Engine Exception: SDL failed to create an OpenGL context: ";
            exceptionMsg += SDL_GetError();

            throw Exception(exceptionMsg);
        }

        m_width = _width;
        m_height = _height;
    }

    Screen::~Screen()
    {
        SDL_GL_DeleteContext(m_glContext);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
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

    void Screen::ClearScreen()
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
}


/** @file Audio.cpp
 *  @brief Implementation of functions for the Audio class.
 */

#include "Audio.h"
#include "Exception.h"

namespace vita
{
    void Audio::Init()
    {
       /// Open a handle to the default device.
       m_audioDevice = alcOpenDevice(NULL);

       if (m_audioDevice == NULL)
       {
           throw Exception("OpenAL could not open a handle to the default device.");
       }

       /// Create an OpenAL audio context.
       m_audioContext = alcCreateContext(m_audioDevice, NULL);

       if (m_audioContext == NULL)
       {
           alcCloseDevice(m_audioDevice);
           throw Exception("OpenAL failed to create a context.");
       }

       /// Set the created context as current.
       if (!alcMakeContextCurrent(m_audioContext))
       {
           alcDestroyContext(m_audioContext);
           alcCloseDevice(m_audioDevice);
           throw Exception("OpenAL failed to make its context current.");
       }
    }

    Audio::~Audio()
    {
        /// Destroy the context and the handle to the default device.
        alcMakeContextCurrent(NULL);
        alcDestroyContext(m_audioContext);
        alcCloseDevice(m_audioDevice);
    }
}

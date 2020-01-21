#include "Audio.h"
#include "Exception.h"

namespace vita
{
    void Audio::Init()
    {
        // Open up the OpenAL device
       m_audioDevice = alcOpenDevice(NULL);

       if (m_audioDevice == NULL)
       {
           throw Exception("OpenAL could not open a handle to the default device.");
       }

       // Create audio context
       m_audioContext = alcCreateContext(m_audioDevice, NULL);

       if (m_audioContext == NULL)
       {
           alcCloseDevice(m_audioDevice);
           throw Exception("OpenAL failed to create a context.");
       }

       // Set as current context
       if (!alcMakeContextCurrent(m_audioContext))
       {
           alcDestroyContext(m_audioContext);
           alcCloseDevice(m_audioDevice);
           throw Exception("OpenAL failed to make its context current.");
       }
    }

    Audio::~Audio()
    {
        alcMakeContextCurrent(NULL);
        alcDestroyContext(m_audioContext);
        alcCloseDevice(m_audioDevice);
    }
}

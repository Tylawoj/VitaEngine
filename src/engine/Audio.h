/** @file Audio.h
 *  @brief Class for storing OpenAL's context and used audio device.
 */

#include <sr1/memory>
#include <AL/al.h>
#include <AL/alc.h>

namespace vita
{
    class Audio
    {
        private:
            ALCcontext* m_audioContext;
            ALCdevice* m_audioDevice;
        public:
            /// @brief Initializes the OpenAL audio context and a handle to used audio device.
            void Init();
            ~Audio();
    };
}

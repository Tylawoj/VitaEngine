/** @file Audio.h
 *  @brief Class for storing OpenAL's context and used audio device.
 */

#include <AL/al.h>
#include <AL/alc.h>
#include <sr1/memory>

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
            /// @brief Destroys the OpenAL audio context and its handle to used audio device.
            ~Audio();
    };
}

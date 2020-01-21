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
            void Init();
            ~Audio();
    };
}

#include "Component.h"
#include <AL/al.h>

namespace vita
{
    class Sound;

    class SoundSource : public Component
    {
        private:
            ALuint m_sourceId;
            bool m_autoRemove;
        public:
            SoundSource(std::sr1::shared_ptr<Sound> _sound);
            void OnInit();
            void OnTick();
            void SetAutoRemove(bool _autoRemove);
            void SetSound(std::sr1::shared_ptr<Sound> _sound);
    };
}

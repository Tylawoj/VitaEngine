#include "Component.h"
#include <AL/al.h>

namespace vita
{
    class Sound;

    class SoundSource : public Component
    {
        private:
            std::sr1::shared_ptr<Sound> m_sound;
            ALuint m_sourceId;
            bool m_hasPlayedYet;
            bool m_playStatus;
            bool m_removeAfterPlay;
        public:
            SoundSource(std::sr1::shared_ptr<Sound> _sound, bool _playOnInit, bool _removeAfterPlay);
            void OnInit();
            void OnTick();
            bool IsPlaying();
            ALuint GetSourceId();
            bool GetAutoRemove();
            void SetToPlay(bool _playStatus);
            void SetAutoRemove(bool _autoRemove);
            void StopPlaying();
            void SetSound(std::sr1::shared_ptr<Sound> _sound);
            ~SoundSource();
    };
}

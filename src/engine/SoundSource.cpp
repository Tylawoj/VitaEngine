#include "SoundSource.h"
#include "Camera.h"
#include "Entity.h"
#include "Sound.h"
#include "Transform.h"

namespace vita
{
    void SoundSource::OnInit()
    {
        m_hasPlayedYet = false;
    }

    void SoundSource::OnTick()
    {
        if (m_playStatus && !m_hasPlayedYet)
        {
            glm::vec3 soundPosition = GetEntity()->GetComponent<Transform>()->GetGlobalPosition();
            glm::vec3 listenerPosition = GetCurrentCamera()->GetPosition();

            alListener3f(AL_POSITION, listenerPosition.x, listenerPosition.y, listenerPosition.z);
            alSource3f(m_sourceId, AL_POSITION, soundPosition.x, soundPosition.y, soundPosition.z);
            alSourcei(m_sourceId, AL_BUFFER, m_sound->GetBufferId());
            alSourcePlay(m_sourceId);

            m_playStatus = false;
        }

        else if (m_hasPlayedYet)
        {
            ALint state = 0;

            alGetSourcei(m_sourceId, AL_SOURCE_STATE, &state);

            if (state == AL_STOPPED && m_removeAfterPlay)
            {
                Kill();
            }
        }
    }

    void SoundSource::StopPlaying()
    {
        alSourceStop(m_sourceId);
    }

    bool SoundSource::GetAutoRemove()
    {
        return m_removeAfterPlay;
    }

    ALuint SoundSource::GetSourceId()
    {
        return m_sourceId;
    }

    SoundSource::SoundSource(std::sr1::shared_ptr<Sound> _sound, bool _playOnInit, bool _removeAfterPlay)
    {
        m_sourceId = 0;
        alGenSources(1, &m_sourceId);

        m_sound = _sound;
        m_playStatus = _playOnInit;
        m_removeAfterPlay = _removeAfterPlay;
    }

    SoundSource::~SoundSource()
    {
        alDeleteSources(1, &m_sourceId);
    }

    void SoundSource::SetAutoRemove(bool _removeAfterPlay)
    {
        m_removeAfterPlay = _removeAfterPlay;
    }

    void SoundSource::SetToPlay(bool _playStatus)
    {
        m_playStatus = _playStatus;
    }

    bool SoundSource::IsPlaying()
    {
        return m_playStatus;
    }
}

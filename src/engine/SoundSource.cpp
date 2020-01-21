#include "SoundSource.h"
#include "Camera.h"
#include "Entity.h"
#include "Sound.h"
#include "Transform.h"

namespace vita
{
    void SoundSource::OnInit()
    {
        m_autoRemove = false;
        m_playStatus = true;
    }

    void SoundSource::OnTick()
    {
        if (m_playStatus)
        {
            glm::vec3 soundPosition = GetEntity()->GetComponent<Transform>()->GetGlobalPosition();
            glm::vec3 listenerPosition = GetCurrentCamera()->GetPosition();

            alListener3f(AL_POSITION, listenerPosition.x, listenerPosition.y, listenerPosition.z);
            alSource3f(m_sourceId, AL_POSITION, soundPosition.x, soundPosition.y, soundPosition.z);
            alSourcei(m_sourceId, AL_BUFFER, m_sound->GetBufferId());
            alSourcePlay(m_sourceId);

            m_playStatus = false;
        }
    }

    void SoundSource::StopPlaying()
    {
        alSourceStop(m_sourceId);
    }

    bool SoundSource::GetAutoRemove()
    {
        return m_autoRemove;
    }

    ALuint SoundSource::GetSourceId()
    {
        return m_sourceId;
    }

    SoundSource::SoundSource(std::sr1::shared_ptr<Sound> _sound)
    {
        m_sourceId = 0;
        alGenSources(1, &m_sourceId);

        m_sound = _sound;
    }

    SoundSource::~SoundSource()
    {
        alDeleteSources(1, &m_sourceId);
    }

    void SoundSource::SetAutoRemove(bool _autoRemove)
    {
        m_autoRemove = _autoRemove;
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

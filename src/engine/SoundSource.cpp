/** @file SoundSource.cpp
 *  @brief Implementation of functions for the SoundSource class.
 */

#include "SoundSource.h"
#include "Camera.h"
#include "Entity.h"
#include "Sound.h"
#include "Transform.h"

namespace vita
{
    SoundSource::~SoundSource()
    {
        /// Delete the source ID.
        alDeleteSources(1, &m_sourceId);
    }

    void SoundSource::OnInit()
    {
        /// Generate a source ID.
        m_sourceId = 0;
        alGenSources(1, &m_sourceId);

        m_hasPlayedYet = false;
    }

    void SoundSource::OnTick()
    {
        /// Check if the sound is due to play.
        if (m_playStatus && !m_hasPlayedYet)
        {
            /// Sets the sound position to the storing Entity's Transform.
            glm::vec3 soundPosition = GetEntity()->GetComponent<Transform>()->GetGlobalPosition();
            /// Sets the listener's position to the camera position.
            glm::vec3 listenerPosition = GetCurrentCamera()->GetPosition();

            alListener3f(AL_POSITION, listenerPosition.x, listenerPosition.y, listenerPosition.z);
            alSource3f(m_sourceId, AL_POSITION, soundPosition.x, soundPosition.y, soundPosition.z);

            /// Try to play the sound at this sound source.
            try
            {
                alSourcei(m_sourceId, AL_BUFFER, m_sound->GetBufferId());
                alSourcePlay(m_sourceId);
            }

            catch (Exception& e)
            {
                std::cout << "Engine Exception: " << e.What() << std::endl;
                std::cout << "A SoundSource failed to play a sound. " << std::endl;
                Kill();
            }

            catch (std::exception& e)
            {
                std::cout << "System Exception: " << e.what() << std::endl;
                std::cout << "A SoundSource failed to play a sound. " << std::endl;
                Kill();
            }

            /// Set as no longer due to play.
            m_playStatus = false;
        }

        else if (m_hasPlayedYet)
        {
            ALint state = 0;

            /// Get the state of the sound source.
            alGetSourcei(m_sourceId, AL_SOURCE_STATE, &state);

            /** Check whether the sound source has stopped playing,
             *  and if yes, check whether it is supposed to be destroyed after playing. */
            if (state == AL_STOPPED && m_removeAfterPlay)
            {
                Kill();
            }
        }
    }

    void SoundSource::StopPlaying()
    {
        /// Stops the playing sound source.
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
        m_sound = _sound;
        m_playStatus = _playOnInit;
        m_removeAfterPlay = _removeAfterPlay;
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

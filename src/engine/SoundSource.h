/** @file SoundSource.h
 *  @brief Class for setting an Entity as a sound source for positional audio.
 */

#include "Component.h"
#include <AL/al.h>

namespace vita
{
    class Sound;

    class SoundSource : public Component
    {
        private:
            bool m_hasPlayedYet; ///< Checks whether the soundsource has played yet.
            bool m_playStatus; ///< Checks whether the sound should be played.
            bool m_removeAfterPlay; ///< Checks if the soundsource should be removed after playing.
            std::sr1::shared_ptr<Sound> m_sound; ///< The sound to play.
            ALuint m_sourceId; ///< The sound source ID for OpenAl.
        public:
            /**
             * @brief Constructs a SoundSource with a set sound to play, and whether it should play when
             * initializes, as well as removed after playing.
             * @param _sound The sound to store.
             * @param _playOnInit Whether the sound should play on initialization.
             * @param _removeAfterPlay Whether the soundsource should be destroyed after playing.
             */
            SoundSource(std::sr1::shared_ptr<Sound> _sound, bool _playOnInit, bool _removeAfterPlay);
            /// @brief Destroys the OpenAL source.
            ~SoundSource();
            /**
             * @brief Returns if the sound source will destroy after playing.
             * @return Whether the sound source will destroy after playing.
             */
            bool GetAutoRemove();
            /**
             * @brief Returns the OpenAL sound source ID.
             * @return The OpenAL sound source ID.
             */
            ALuint GetSourceId();
            /**
             * @brief Returns if the sound source is playing now.
             * @return Whether the sound source is playing now.
             */
            bool IsPlaying();
            /// @brief Initializes member variables.
            void OnInit();
            /**
             * @brief Checks if the sound source is set to play and if yes, plays the sound.
             * If the sound source already played once, checks for removal.
             */
            void OnTick();
            /**
             * @brief Sets whether the sound source should destroy after playing once.
             * @param _autoRemove Whether the soundsource should be destroyed after playing.
             */
            void SetAutoRemove(bool _autoRemove);
            /**
             * @brief Sets a sound to be played by the sound source.
             * @param _sound The sound to store.
             */
            void SetSound(std::sr1::shared_ptr<Sound> _sound);
            /**
             * @brief Sets whether the sound source should play on next tick.
             * @param _playStatus Whether the sound source should start playing on next tick.
             */
            void SetToPlay(bool _playStatus);
            /// @brief Stops playing the sound.
            void StopPlaying();
    };
}

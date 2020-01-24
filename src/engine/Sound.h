/** @file Sound.h
 *  @brief Class for loading a sound from an OGG file and storing OpenAL's buffer ID.
 */

#include "Resource.h"
#include <AL/al.h>

namespace vita
{
    class Sound : public Resource
    {
        private:
            ALuint m_bufferId; ///< The buffer ID of the loaded sound file.
        public:
            /// @brief Destroys the OpenAL buffer.
            ~Sound();
            /**
             * @brief Loads a Sound from an OGG file.
             * @param _path The file path to the OGG file.
             */
            void OnLoad(const std::string& _path);
            /**
             * @brief Returns the buffer ID of the Sound object.
             * @return The buffer ID of the Sound object.
             */
            ALuint GetBufferId();

    };
}

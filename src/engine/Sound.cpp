/** @file Sound.cpp
 *  @brief Implementation of functions for the Sound class.
 */

#include "Sound.h"
#include "Exception.h"
#include <stb/stb_vorbis.h>
#include <vector>

namespace vita
{
    Sound::~Sound()
    {
        /// Delete the buffer with the stored sound.
        alDeleteBuffers(1, &m_bufferId);
    }

    ALuint Sound::GetBufferId()
    {
        /// Try returning the buffer ID with the sound.
        try
        {
            return m_bufferId;
        }

        /// If unable to, kill the resource and return NULL.
        catch (Exception& e)
        {
            std::cout << "Engine Exception: " << e.What() << std::endl;
            std::cout << "A Sound failed to return its buffer ID. " << std::endl;
            Kill();
            return NULL;
        }

        catch (std::exception& e)
        {
            std::cout << "System Exception: " << e.what() << std::endl;
            std::cout << "A Sound failed to return its buffer ID. " << std::endl;
            Kill();
            return NULL;
        }
    }

    void Sound::OnLoad(const std::string &_path)
    {
        /// Create a sound buffer.
        alGenBuffers(1, &m_bufferId);

        ALenum format = 0;
        ALsizei freq = 0;
        std::vector<char> bufferData;

        int channels = 0;
        int sampleRate = 0;
        short* output = NULL;

        /// Decode the OGG file using STB_Vorbis.
        size_t samples = stb_vorbis_decode_filename(
                             _path.c_str(), &channels, &sampleRate, &output);

        if (samples == -1)
        {
            throw Exception("STB Vorbis failed to decode a .ogg file.");
        }

        /// Record the sample rate required by OpenAL.
        freq = sampleRate;

        /// Record the format required by OpenAL.
        if (channels == 1)
        {
            format = AL_FORMAT_MONO16;
        }

        else
        {
            format = AL_FORMAT_STEREO16;

            // Force format to be mono (Useful for positional audio)
            // format = AL_FORMAT_MONO16;
            // freq *= 2;
        }

        /// Allocate space for the sound in the buffer.
        bufferData.resize(sizeof(*output) * channels * samples);
        memcpy(&bufferData.at(0), output, bufferData.size());

        /// Clean up the read data.
        free(output);

        /// Store the buffer data at the given buffer ID.
        alBufferData(m_bufferId, format, &bufferData.at(0),
                     static_cast<ALsizei>(bufferData.size()), freq);

        if (m_bufferId == NULL)
        {
            throw Exception("STB Vorbis failed to decode a .ogg file.");
        }
    }
}


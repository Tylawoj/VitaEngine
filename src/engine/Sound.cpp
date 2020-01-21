#include "Sound.h"
#include "Exception.h"
#include <stb/stb_vorbis.h>
namespace vita
{
    void Sound::OnLoad(const std::string &_path)
    {
        alGenBuffers(1, &m_bufferId);

        ALenum format = 0;
        ALsizei freq = 0;
        std::vector<char> bufferData;

        int channels = 0;
        int sampleRate = 0;
        short* output = NULL;

        size_t samples = stb_vorbis_decode_filename(
                             _path.c_str(), &channels, &sampleRate, &output);

        if (samples == -1)
        {
            throw Exception("STB Vorbis failed to decode a .ogg file.");
        }

        // Record the sample rate required by OpenAL
        freq = sampleRate;

        // Record the format required by OpenAL
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

        // Allocate enough space based on short (two chars) multipled by the number of
        // channels and length of clip
        bufferData.resize(sizeof(*output) * channels * samples);
        memcpy(&bufferData.at(0), output, bufferData.size());

        // Clean up the read data
        free(output);

        alBufferData(m_bufferId, format, &bufferData.at(0),
                     static_cast<ALsizei>(bufferData.size()), freq);

    }

    ALuint Sound::GetBufferId()
    {
        return m_bufferId;
    }

    Sound::~Sound()
    {
        alDeleteBuffers(1, &m_bufferId);
    }
}


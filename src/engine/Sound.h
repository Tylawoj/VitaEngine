#include "Resource.h"
#include <AL/al.h>

namespace vita
{
    class Sound : public Resource
    {
        private:
            ALuint m_bufferId;
        public:
            void OnLoad(const std::string& _path);
            ALuint GetBufferId();
            ~Sound();
    };
}

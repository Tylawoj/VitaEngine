#include "Resource.h"

namespace rend
{
    struct Texture;
}

namespace vita
{
    class Texture : public Resource
    {
        private:
            std::sr1::shared_ptr<rend::Texture> m_texture;
        public:
            std::sr1::shared_ptr<rend::Texture> GetRendTexture();
            void OnLoad(const std::string& _path);
    };
}

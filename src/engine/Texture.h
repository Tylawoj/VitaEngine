#include "Resource.h"
#include <rend/rend.h>

namespace vita
{
    class Material;

    class Texture : public Resource
    {
        friend class vita::Material;

        private:
            std::sr1::shared_ptr<rend::Texture> m_texture;
            std::sr1::shared_ptr<rend::Texture> GetRendTexture();
        public:
            void OnLoad(const std::string& _path);
    };
}

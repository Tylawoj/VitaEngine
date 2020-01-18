#include "Resource.h"
#include <rend/rend.h>

namespace vita
{
    class Material : public Resource
    {
        private:
            std::sr1::shared_ptr<rend::Shader> m_shader;
            std::sr1::shared_ptr<rend::Texture> m_texture;
        public:
            void OnLoad(const std::string& _path);
    };
}

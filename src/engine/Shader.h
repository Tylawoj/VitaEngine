#include "Resource.h"

namespace rend
{
    struct Shader;
}

namespace vita
{
    class Material;

    class Shader : public Resource
    {
        friend class vita::Material;

        private:
            std::sr1::shared_ptr<rend::Shader> m_shader;
            std::sr1::shared_ptr<rend::Shader> GetRendShader();
        public:
            void OnLoad(const std::string& _path);
    };
}

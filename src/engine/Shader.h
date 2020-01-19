#include "Resource.h"
#include <rend/rend.h>

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

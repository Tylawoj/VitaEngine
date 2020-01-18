#include "Resource.h"
#include <rend/rend.h>

namespace vita
{
    class Shader : public Resource
    {
        private:
            std::sr1::shared_ptr<rend::Shader> m_shader;
        public:
            void OnLoad(const std::string& _path);
    };
}

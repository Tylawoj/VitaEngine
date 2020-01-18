#include "Resource.h"
#include "rend/rend.h"

namespace vita
{
    class Mesh : public Resource
    {
        private:
            std::sr1::shared_ptr<rend::Mesh> m_mesh;
        public:
            void OnLoad(const std::string& _path);
    };
}

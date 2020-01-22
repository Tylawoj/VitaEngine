#include "Resource.h"
#include <sr1/memory>

namespace rend
{
    struct Mesh;
}

namespace vita
{
    class Mesh : public Resource
    {
        private:
            std::sr1::shared_ptr<rend::Mesh> m_mesh;
        public:
            std::sr1::shared_ptr<rend::Mesh> GetRendMesh();
            void OnLoad(const std::string& _path);
    };
}

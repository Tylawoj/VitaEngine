#include "Resource.h"
#include "rend/rend.h"

namespace vita
{
    class MeshRenderer;

    class Mesh : public Resource
    {
        friend class vita::MeshRenderer;

        private:
            std::sr1::shared_ptr<rend::Mesh> m_mesh;
            std::sr1::shared_ptr<rend::Mesh> GetRendMesh();
        public:
            void OnLoad(const std::string& _path);
    };
}

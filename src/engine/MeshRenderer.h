#include "Component.h"
#include <sr1/memory>

namespace rend
{
    struct Buffer;
}

namespace vita
{
    class Material;
    class Mesh;

    class MeshRenderer : public Component
    {
        private:
            std::sr1::shared_ptr<Mesh> m_mesh;
            std::sr1::shared_ptr<Material> m_material;
        public:
            MeshRenderer(std::sr1::shared_ptr<Mesh> _mesh, std::sr1::shared_ptr<Material> _material);
            void OnDisplay();
            void SetMesh(std::sr1::shared_ptr<Mesh> _mesh);
            void SetMaterial(std::sr1::shared_ptr<Material> _material);
    };
}

#include "Component.h"
#include <sr1/memory>

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
            void OnInit();
            void OnDisplay();
            void SetMesh(std::sr1::shared_ptr<Mesh> _mesh);
            void SetMaterial(std::sr1::shared_ptr<Material> _material);
    };
}

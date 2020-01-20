#include "Component.h"
#include <sr1/memory>
#include <rend/rend.h>

namespace vita
{
    class Material;
    class Mesh;

    class MeshRenderer : public Component
    {
        private:
            std::sr1::shared_ptr<Mesh> m_mesh;
            std::sr1::shared_ptr<Material> m_material;
            std::sr1::shared_ptr<rend::Buffer> m_buffer;
        public:
            MeshRenderer(std::sr1::shared_ptr<Mesh> _mesh, std::sr1::shared_ptr<Material> _material);
            void OnInit();
            void OnDisplay();
            void SetMesh(std::sr1::shared_ptr<Mesh> _mesh);
            void SetMaterial(std::sr1::shared_ptr<Material> _material);
    };
}

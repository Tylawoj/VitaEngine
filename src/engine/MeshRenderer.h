/** @file MeshRenderer.h
 *  @brief Class for rendering a set Mesh with its Material (shader and texture).
 */

#include "Component.h"
#include <rend/rend.h>
#include <sr1/memory>

namespace vita
{
    class Material;
    class Mesh;

    class MeshRenderer : public Component
    {
        private:
            std::sr1::shared_ptr<Material> m_material;
            std::sr1::shared_ptr<Mesh> m_mesh;
        public:
            /**
             * @brief Constructs a MeshRenderer with the already constructed Mesh and Material.
             * @param _shader A loaded Mesh object.
             * @param _texture A loaded Material object.
             */
            MeshRenderer(std::sr1::shared_ptr<Mesh> _mesh, std::sr1::shared_ptr<Material> _material);
            /// @brief Renders the stored Mesh using its Material.
            void OnDisplay();
            /**
             * @brief Sets a new Mesh for the MeshRenderer to use.
             * @param _mesh A Mesh object.
             */
            void SetMesh(std::sr1::shared_ptr<Mesh> _mesh);
            /**
             * @brief Sets a new Material for the MeshRenderer to use.
             * @param _material A Material object.
             */
            void SetMaterial(std::sr1::shared_ptr<Material> _material);
    };
}

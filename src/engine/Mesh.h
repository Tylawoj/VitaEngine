/** @file Mesh.h
 *  @brief Class for loading a mesh from an OBJ file and storing a rend's Mesh.
 */

#include "Resource.h"

namespace rend
{
    struct Mesh;
}

namespace vita
{
    class MeshRenderer;

    class Mesh : public Resource
    {
        private:
            std::sr1::shared_ptr<rend::Mesh> m_mesh; ///< rend's Mesh object.
        public:
            /**
             * @brief Returns the rend's Mesh, used in rendering.
             * @return The rend's Mesh object.
             */
            std::sr1::shared_ptr<rend::Mesh> GetRendMesh();
            /**
             * @brief Loads a Mesh from an OBJ file.
             * @param _path The file path to the OBJ file.
             */
            void OnLoad(const std::string& _path);
    };
}

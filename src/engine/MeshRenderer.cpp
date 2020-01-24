/** @file MeshRenderer.cpp
 *  @brief Implementation of functions for the MeshRenderer class.
 */

#include "MeshRenderer.h"
#include "Camera.h"
#include "Core.h"
#include "Exception.h"
#include "Entity.h"
#include "Material.h"
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"
#include "Transform.h"
#include <rend/rend.h>

namespace vita
{
    MeshRenderer::MeshRenderer(std::sr1::shared_ptr<Mesh> _mesh, std::sr1::shared_ptr<Material> _material)
    {
        m_mesh = _mesh;
        m_material = _material;
    }

    void MeshRenderer::OnDisplay()
    {
        /// Ensure that the Material and Mesh exist with its class members.
        if (m_mesh != NULL && m_material != NULL)
        {
            if (m_material->GetShader() != NULL && m_material->GetTexture() != NULL)
            {
                /// Ensure that this Entity has a Transform to get a transformation matrix from.
                bool transformExists = GetEntity()->HasComponent<Transform>();

                if (transformExists)
                {
                    /// Get the Transform of this entity.
                    std::sr1::shared_ptr<Transform> transform = GetEntity()->GetComponent<Transform>();
                    /// Get the currently set camera.
                    std::sr1::shared_ptr<Camera> camera = GetCore()->GetCurrentCamera();

                    /// Ensure that Core has a camera set.
                    if (camera == NULL)
                    {
                        throw Exception("MeshRenderer: Core does not have a current camera set.");
                    }

                    /// Get the rend's Shader from Material.
                    std::sr1::shared_ptr<rend::Shader> rendShader = m_material->GetRendShader();

                    /// Set the shader to use the model (transformation), view and projection matrix.
                    rendShader->setUniform("u_Model", transform->GetTransformMatrix());
                    rendShader->setUniform("u_View", camera->GetViewMatrix());
                    rendShader->setUniform("u_Projection", camera->GetProjectionMatrix());

                    /// Get the rend's Mesh from Mesh.
                    std::sr1::shared_ptr<rend::Mesh> rendMesh = m_mesh->GetRendMesh();
                    /// Set the rend's Mesh to use rend's Texture stored in Material.
                    rendMesh->setTexture("u_Texture", m_material->GetRendTexture());
                    /// Set the shader to use the mesh with the texture.
                    rendShader->setMesh(rendMesh);
                    /// Render the mesh.
                    rendShader->render();
                }

                else
                {
                    throw Exception("MeshRenderer: Could not find a Transform in an Entity.");
                }
            }

            else
            {
                throw Exception("MeshRenderer: Material's Shader or Texture was not loaded correctly.");
            }
        }

        else if (m_mesh == NULL)
        {
            throw Exception("MeshRenderer: Mesh was not loaded correctly.");
        }

        else if (m_material == NULL)
        {
            throw Exception("MeshRenderer: Material was not loaded correctly.");
        }
    }

    void MeshRenderer::SetMesh(std::sr1::shared_ptr<Mesh> _mesh)
    {
        m_mesh = _mesh;
    }

    void MeshRenderer::SetMaterial(std::sr1::shared_ptr<Material> _material)
    {
        m_material = _material;
    }
}

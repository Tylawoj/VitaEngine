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

namespace vita
{
    MeshRenderer::MeshRenderer(std::sr1::shared_ptr<Mesh> _mesh, std::sr1::shared_ptr<Material> _material)
    {
        m_mesh = _mesh;
        m_material = _material;
    }

    void MeshRenderer::OnDisplay()
    {
        if (m_mesh != NULL && m_material != NULL)
        {
            bool transformExists = GetEntity()->HasComponent<Transform>();

            if (transformExists)
            {
                std::sr1::shared_ptr<Transform> transform = GetEntity()->GetComponent<Transform>();
                std::sr1::shared_ptr<Camera> camera = GetCore()->GetCamera();
                std::sr1::shared_ptr<rend::Shader> rendShader = m_material->GetRendShader();

                rendShader->setUniform("in_Model", transform->GetTransformMatrix());
                rendShader->setUniform("in_Projection", camera->GetProjectionMatrix());
                rendShader->setUniform("in_View", camera->GetViewMatrix());

                //if (GetCore()->IsLightingSet())
                //{

                //}

                std::sr1::shared_ptr<rend::Mesh> rendMesh = m_mesh->GetRendMesh();

                rendMesh->setTexture("in_Texture", m_material->GetRendTexture());

                rendShader->render();
            }

            else
            {
                throw Exception("MeshRenderer: Could not find a Transform in an Entity.");
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

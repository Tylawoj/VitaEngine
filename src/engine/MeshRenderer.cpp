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

    void MeshRenderer::OnInit()
    {
        m_buffer = GetCore()->GetContext()->createBuffer();
    }

    void MeshRenderer::OnDisplay()
    {
        if (m_mesh != NULL && m_material != NULL)
        {
            if (m_material->GetShader() != NULL && m_material->GetTexture())
            {
                bool transformExists = GetEntity()->HasComponent<Transform>();

                if (transformExists)
                {
                    std::sr1::shared_ptr<Transform> transform = GetEntity()->GetComponent<Transform>();
                    std::sr1::shared_ptr<Camera> camera = GetCore()->GetCurrentCamera();

                    if (camera == NULL)
                    {
                        throw Exception("MeshRenderer: Core does not have a current camera set.");
                    }

                    std::sr1::shared_ptr<rend::Shader> rendShader = m_material->GetRendShader();

                    rendShader->setUniform("u_Model", transform->GetTransformMatrix());
                    rendShader->setUniform("u_View", camera->GetViewMatrix());
                    rendShader->setUniform("u_Projection", camera->GetProjectionMatrix());

                    //if (GetCore()->IsLightingSet())
                    //{

                    //}

                    std::sr1::shared_ptr<rend::Mesh> rendMesh = m_mesh->GetRendMesh();
                    rendMesh->setTexture("u_Texture", m_material->GetRendTexture());
                    rendShader->setMesh(rendMesh);
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

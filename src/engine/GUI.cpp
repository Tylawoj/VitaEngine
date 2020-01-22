#include "GUI.h"
#include "Core.h"
#include "Material.h"
#include "Screen.h"
#include <rend/rend.h>

namespace vita
{
    void GUI::Init()
    {
        m_projection = glm::ortho(0, m_core.lock()->GetScreen()->GetWidth(), m_core.lock()->GetScreen()->GetHeight(), 0);
        m_mesh = m_core.lock()->GetContext()->createMesh();
    }

    void GUI::DrawGUITexture(glm::vec2 _position, glm::vec2 _size, std::sr1::shared_ptr<Material> _material)
    {
        std::sr1::shared_ptr<rend::Shader> rendShader = _material->GetRendShader();

        glm::mat4 model(1.0f);

        model = glm::translate(model, glm::vec3(_position.x, _position.y, 0.0f));
        model = glm::scale(model, glm::vec3(_size.x, _size.y, 1.0f));

        rendShader->setUniform("u_Model", model);
        rendShader->setUniform("u_Projection", m_projection);
        m_mesh->setTexture("u_Texture", _material->GetRendTexture());
        rendShader->setMesh(m_mesh);
        rendShader->setDepthTesting(false);
        rendShader->render();
        rendShader->setDepthTesting(true);
    }

    void GUI::DrawGUITexture(glm::vec2 _position, std::sr1::shared_ptr<Material> _material)
    {
        std::sr1::shared_ptr<rend::Shader> rendShader = _material->GetRendShader();

        glm::mat4 model(1.0f);

        model = glm::translate(model, glm::vec3(_position.x, _position.y, 0.0f));

        rendShader->setUniform("u_Model", model);
        rendShader->setUniform("u_Projection", m_projection);
        m_mesh->setTexture("u_Texture", _material->GetRendTexture());
        rendShader->setMesh(m_mesh);
        rendShader->setDepthTesting(false);
        rendShader->render();
        rendShader->setDepthTesting(true);
    }
}

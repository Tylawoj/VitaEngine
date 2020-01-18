#include "Material.h"
#include "Core.h"
#include "Resources.h"
#include "Shader.h"
#include "Texture.h"

namespace vita
{
    Material::Material(std::sr1::shared_ptr<Shader> _shader, std::sr1::shared_ptr<Texture> _texture)
    {
        m_shader = _shader;
        m_texture = _texture;
    }

    Material::Material(std::string& _shaderPath, std::string& _texturePath)
    {
        m_shader = GetResources()->Load<Shader>(_shaderPath);
        m_texture = GetResources()->Load<Texture>(_texturePath);
    }

    void Material::SetShader(std::sr1::shared_ptr<Shader> _shader)
    {
        m_shader = _shader;
    }

    void Material::SetTexture(std::sr1::shared_ptr<Texture> _texture)
    {
        m_texture = _texture;
    }
}

/** @file Material.cpp
 *  @brief Implementation of functions for the Material class.
 */

#include "Material.h"
#include "Core.h"
#include "Resources.h"
#include "Shader.h"
#include "Texture.h"
#include <rend/rend.h>

namespace vita
{
    Material::Material(std::sr1::shared_ptr<Shader> _shader, std::sr1::shared_ptr<Texture> _texture)
    {
        m_shader = _shader;
        m_texture = _texture;
    }

    Material::Material(std::string& _shaderPath, std::string& _texturePath)
    {
        /** Creates a Shader and Texture using the specified file paths,
         *  and sets them as class members. */
        m_shader = GetResources()->Load<Shader>(_shaderPath);
        m_texture = GetResources()->Load<Texture>(_texturePath);
    }

    std::sr1::shared_ptr<rend::Shader> Material::GetRendShader()
    {
        return m_shader->GetRendShader();
    }

    std::sr1::shared_ptr<rend::Texture> Material::GetRendTexture()
    {
        return m_texture->GetRendTexture();
    }

    std::sr1::shared_ptr<Shader> Material::GetShader()
    {
        return m_shader;
    }

    std::sr1::shared_ptr<Texture> Material::GetTexture()
    {
        return m_texture;
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

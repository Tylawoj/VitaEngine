/** @file Material.h
 *  @brief Class for storing a shader and texture, which are later used in rendering with a Mesh.
 */

#include "Component.h"

namespace rend
{
    struct Shader;
    struct Texture;
}

namespace vita
{
    class MeshRenderer;
    class Shader;
    class Texture;

    class Material : public Component
    {
        private:
            std::sr1::shared_ptr<Shader> m_shader; ///< A vertex and/or fragment shader.
            std::sr1::shared_ptr<Texture> m_texture; ///< The texture of this material.
        public:
            /**
             * @brief Constructs a Material with the already constructed shader and texture.
             * @param _shader A loaded Shader object.
             * @param _texture A loaded Texture object.
             */
            Material(std::sr1::shared_ptr<Shader> _shader, std::sr1::shared_ptr<Texture> _texture);
            /**
             * @brief Constructs a Material, loading and constructing a shader and a texture from
             * the specified paths.
             * @param _shaderPath A file path to the shader.
             * @param _texturePath A file path to the texture.
             */
            Material(std::string& _shaderPath, std::string& _texturePath);
            /**
             * @brief Returns the rend's Shader from the member Shader object.
             * @return The rend's Shader from the member Shader object.
             */
            std::sr1::shared_ptr<rend::Shader> GetRendShader();
            /**
             * @brief Returns the rend's Texture from the member Texture object.
             * @return The rend's Texture from the member Texture object.
             */
            std::sr1::shared_ptr<rend::Texture> GetRendTexture();
            /**
             * @brief Returns the stored Shader.
             * @return A Shader object.
             */
            std::sr1::shared_ptr<Shader> GetShader();
            /**
             * @brief Returns the stored Texture.
             * @return A Texture object.
             */
            std::sr1::shared_ptr<Texture> GetTexture();
            /**
             * @brief Sets a new shader for the Material to use.
             * @param _shader A Shader object.
             */
            void SetShader(std::sr1::shared_ptr<Shader> _shader);
            /**
             * @brief Sets a new texture for the Material to use.
             * @param _texture A Texture object.
             */
            void SetTexture(std::sr1::shared_ptr<Texture> _texture);
    };
}

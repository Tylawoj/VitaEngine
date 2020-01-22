#include "Component.h"
#include <sr1/memory>

namespace rend
{
    struct Shader;
    struct Texture;
}

namespace vita
{
    class Shader;
    class Texture;

    class Material : public Component
    {
        private:
            std::sr1::shared_ptr<Shader> m_shader;
            std::sr1::shared_ptr<Texture> m_texture;
        public:
            Material(std::sr1::shared_ptr<Shader> _shader, std::sr1::shared_ptr<Texture> _texture);
            Material(std::string& _shaderPath, std::string& _texturePath);
            std::sr1::shared_ptr<rend::Shader> GetRendShader();
            std::sr1::shared_ptr<rend::Texture> GetRendTexture();
            std::sr1::shared_ptr<Shader> GetShader();
            std::sr1::shared_ptr<Texture> GetTexture();
            void SetShader(std::sr1::shared_ptr<Shader> _shader);
            void SetTexture(std::sr1::shared_ptr<Texture> _texture);
    };
}

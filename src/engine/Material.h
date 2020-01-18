#include "Component.h"

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
            void SetShader(std::sr1::shared_ptr<Shader> _shader);
            void SetTexture(std::sr1::shared_ptr<Texture> _texture);
    };
}

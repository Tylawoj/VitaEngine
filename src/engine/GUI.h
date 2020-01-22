#include <glm/mat4x4.hpp>
#include <glm/vec2.hpp>
#include <sr1/memory>

namespace rend
{
    struct Buffer;
    struct Mesh;
}

namespace vita
{
    class Core;
    class Material;

    class GUI
    {
        friend class vita::Core;

        private:
            std::sr1::weak_ptr<Core> m_core;
            std::sr1::shared_ptr<rend::Mesh> m_mesh;
            glm::mat4 m_projection;
        public:
            void Init();
            void DrawGUITexture(glm::vec2 _position, glm::vec2 _size, std::sr1::shared_ptr<Material> _material);
            void DrawGUITexture(glm::vec2 _position, std::sr1::shared_ptr<Material> _material);
    };
}

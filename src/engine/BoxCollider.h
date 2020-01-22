#include "Component.h"
#include <glm/vec3.hpp>

namespace vita
{
    class BoxCollider : public Component
    {
        private:
            glm::vec3 m_size;
            glm::vec3 m_offset;
            bool m_solid;
            bool IsColliding(glm::vec3 _position, glm::vec3 _size);
            glm::vec3 GetCollisionResponse(glm::vec3 _position, glm::vec3 _size);
        public:
            BoxCollider(glm::vec3 _size, glm::vec3 _offset, bool _solid);
            void OnCollisionUpdate();
            void SetSize(glm::vec3 _size);
            void SetOffset(glm::vec3 _offset);
    };
}

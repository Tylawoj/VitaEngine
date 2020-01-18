#include "Component.h"
#include <glm/ext.hpp>
#include <list>

namespace vita
{
    class Transform : public Component
    {
        private:
            glm::vec3 m_position;
            glm::vec3 m_rotation;
            glm::vec3 m_scale;
            std::sr1::shared_ptr<Entity> m_parent;
            bool m_setAsChild;
        public:
            void Translate(glm::vec3 _translation);
            void Rotate(glm::vec3 _rotation);
            void SetAsChildrenOf(std::sr1::shared_ptr<Entity> _parent);
            glm::vec3 GetPosition();
            glm::mat4 GetTransform();
            Transform(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale);
            Transform(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale, std::sr1::shared_ptr<Entity> _parent);
    };
}


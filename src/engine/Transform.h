#include "Component.h"
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
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
            void RemoveChildStatus();
            glm::vec3 GetGlobalPosition();
            glm::vec3 GetGlobalRotation();
            glm::vec3 GetGlobalScale();
            glm::vec3 GetLocalPosition();
            glm::vec3 GetLocalRotation();
            glm::vec3 GetLocalScale();
            glm::mat4 GetTransformMatrix();
            void SetLocalPosition(glm::vec3 _position);
            void SetLocalRotation(glm::vec3 _rotation);
            Transform(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale);
            Transform(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale, std::sr1::shared_ptr<Entity> _parent);
    };
}


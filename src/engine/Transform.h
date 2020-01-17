#include "Component.h"
#include <glm/vec3.hpp>
#include <list>

namespace vita
{
    class Transform : public Component
    {
        private:
            glm::vec3 m_localPosition;
            glm::vec3 m_localRotation;
            glm::vec3 m_localScale;
            std::list<std::sr1::shared_ptr<Transform>> m_children;
            bool m_isParent;
        public:
            void Translate(glm::vec3 _translation);
            void Rotate(glm::vec3 _rotation);
            glm::mat4 GetModel();
            void SetAsParent();
            Transform();
            ~Transform();
    }
};


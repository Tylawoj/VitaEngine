#include "Component.h"
#include <glm/mat4x4.hpp>

namespace vita
{
    class Camera : public Component
    {
        private:
            float m_fov;
            glm::vec3 m_target;
            glm::mat4 m_projectionMatrix;
        public:
            Camera(float _fov, glm::vec3 _target);
            /**
             * @brief Sets a direction for the camera to look at.
             * Warning: The direction will still be affected by rotations.
             * @param _target The direction vector.
             */
            void SetTargetDirection(glm::vec3 _target);
            void OnInit();
            void RotateTargetDirection(glm::vec3 _rotation);
            glm::mat4 GetProjectionMatrix();
            glm::mat4 GetViewMatrix();
    };
}


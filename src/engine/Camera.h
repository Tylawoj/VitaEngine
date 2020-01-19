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
            /**
             * @brief Nullifies the rotation of the containing Entity and
             * sets a direction for the camera to look at.
             * Warning: The direction may still be affected by rotations
             * from parent's Transform, if set.
             * @param _target The direction vector.
             */
            void SetTargetDirectionNoRotation(glm::vec3 _target);
            /**
             * @brief Removes any parent Transform of the containing Entity,
             * nullifies the rotation and sets a direction for the camera to look at.
             * Warning: This function may break some functionality if the Camera
             * is dependent on a parent's Transform.
             * @param _target The direction vector.
             */
            void ForceSetTargetDirection(glm::vec3 _target);
            glm::mat4 GetProjectionMatrix();
            glm::mat4 GetViewMatrix();
    };
}


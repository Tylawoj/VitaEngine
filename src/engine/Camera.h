/** @file Camera.h
 *  @brief Class used for returning a view matrix, used in rendering.
 */

#include "Component.h"
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>

namespace vita
{
    class Camera : public Component
    {
        private:
            float m_fov; ///< Field of view.
            glm::vec3 m_up; ///< Defines where the up direction is in the world.
            glm::vec3 m_target; ///< Target direction.
            glm::mat4 m_projectionMatrix;
        public:
            /**
             * @brief Sets the starting FOV and target direction.
             * @param _fov The field of view.
             * @param _target Target direction.
             */
            Camera(float _fov, glm::vec3 _target);
            /**
             * @brief Sets a direction for the camera to look at.
             * @param _target The direction vector.
             */
            void SetTargetDirection(glm::vec3 _target);
            /**
             * @brief Returns the position of the camera.
             * @return
             */
            glm::vec3 GetPosition();
            /**
             * @brief Initializes the projection matrix of the camera.
             */
            void OnInit();
            /**
             * @brief Rotates the target direction vector.
             * @param _rotation Axis-angled rotation.
             */
            void RotateTargetDirection(glm::vec3 _rotation);
            /**
             * @brief Returns the projection matrix.
             * @return A projection matrix.
             */
            glm::mat4 GetProjectionMatrix();
            /**
             * @brief Constructs and returns a view matrix using the target direction and camera's position.
             * @return A view matrix.
             */
            glm::mat4 GetViewMatrix();
    };
}


#include "Camera.h"
#include "Core.h"
#include "Entity.h"
#include "Screen.h"
#include "Transform.h"

namespace vita
{
    Camera::Camera(float _fov, glm::vec3 _target)
    {
        m_fov = _fov;
        m_target = glm::normalize(_target);
        m_projectionMatrix = glm::perspective(glm::radians(_fov),
                                              (float)GetCore()->GetScreen()->GetWidth() / (float)GetCore()->GetScreen()->GetWidth(),
                                              0.1f, 100.f);
    }

    glm::mat4 Camera::GetProjectionMatrix()
    {
        return m_projectionMatrix;
    }

    void Camera::SetTargetDirection(glm::vec3 _target)
    {
        m_target = glm::normalize(_target);
    }

    void Camera::SetTargetDirectionNoRotation(glm::vec3 _target)
    {
        GetEntity()->GetComponent<Transform>()->SetLocalRotation(glm::vec3(0.0f, 0.0f, 0.0f));
        m_target = glm::normalize(_target);
    }

    void Camera::ForceSetTargetDirection(glm::vec3 _target)
    {
        GetEntity()->GetComponent<Transform>()->RemoveChildStatus();
        GetEntity()->GetComponent<Transform>()->SetLocalRotation(glm::vec3(0.0f, 0.0f, 0.0f));
        m_target = glm::normalize(_target);
    }

    glm::mat4 Camera::GetViewMatrix()
    {
        glm::vec3 position = GetEntity()->GetComponent<Transform>()->GetGlobalPosition();
        glm::vec3 rotation = GetEntity()->GetComponent<Transform>()->GetGlobalRotation();
        glm::vec3 worldUp = glm::vec3(0.0f, 1.0f, 0.0f);

        /**
         * Camera looks at target.
         * Camera can be rotated - does it lose target or not?
         * If yes - it cannot be rotated and care 100% about target location
         * If not - it can be rotated, however it will lose target
         *
         * Best solution - rotate target direction if needed
         */

        glm::vec3 forward;
        forward.x = glm::cos(rotation.x) * glm::cos(rotation.y);
        forward.y = glm::sin(rotation.y);
        forward.z = glm::sin(rotation.x) * glm::cos(rotation.y);

        forward = glm::normalize(forward);

        glm::vec3 right = glm::normalize(glm::cross(m_target, worldUp));
        glm::vec3 up = glm::normalize(glm::cross(m_target, right));

        if (up == )
        glm::mat4 view = glm::lookAt(position, m_target,

        return glm::inverse(GetEntity()->GetComponent<Transform>()->GetTransformMatrix());
    }

}

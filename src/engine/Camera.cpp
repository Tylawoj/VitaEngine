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
    }

    void Camera::OnInit()
    {
        m_projectionMatrix = glm::perspective(glm::radians(m_fov),
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

    void Camera::RotateTargetDirection(glm::vec3 _rotation)
    {
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::rotate(model, _rotation.x, glm::vec3(1, 0, 0));
        model = glm::rotate(model, _rotation.y, glm::vec3(0, 1, 0));
        model = glm::rotate(model, _rotation.z, glm::vec3(0, 0, 1));
        model = glm::translate(model, m_target);

        m_target = glm::normalize(glm::vec3(model[3]));
    }

    glm::mat4 Camera::GetViewMatrix()
    {
        glm::vec3 position = GetEntity()->GetComponent<Transform>()->GetGlobalPosition();

		glm::vec3 right = glm::vec3(-m_target.z, 0, m_target.x);
		right = glm::normalize(right);

		glm::vec3 up = glm::cross(m_target, right);
		glm::normalize(up);

        return glm::inverse(glm::lookAt(position, position + m_target, up));
    }

}

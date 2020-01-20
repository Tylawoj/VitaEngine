#include "Transform.h"
#include "Exception.h"
#include "Entity.h"
#include <glm/gtx/matrix_decompose.hpp>
#include <iostream>

namespace vita
{
    Transform::Transform(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale)
    {
        m_position = _position;
        m_rotation = glm::vec3(glm::radians(_rotation.x),
                               glm::radians(_rotation.y),
                               glm::radians(_rotation.z));
        m_scale = _scale;
        m_setAsChild = false;
    }

    Transform::Transform(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale, std::sr1::shared_ptr<Entity> _parent)
    {
        m_position = _position;
        m_rotation = glm::vec3(glm::radians(_rotation.x),
                               glm::radians(_rotation.y),
                               glm::radians(_rotation.z));
        m_scale = _scale;
        m_setAsChild = true;
        m_parent = _parent;
    }

    glm::vec3 Transform::GetGlobalPosition()
    {
        glm::mat4 model(1.0f);

        if (m_setAsChild)
        {
            if (m_parent->HasComponent<Transform>())
            {
                std::sr1::shared_ptr<Transform> parentTransform = m_parent->GetComponent<Transform>();
                model = model * parentTransform->GetTransformMatrix();
            }

            else
            {
                std::cout << "Engine Warning: A Transform was set as a child node of another Transform, but could not find parent's Transform." << std::endl;
                std::cout << "Its parent will be removed, and the used GetPosition() function will only use local values." << std::endl;
                m_parent = NULL;
                m_setAsChild = false;
            }
        }

        glm::vec3 position = m_position * glm::vec3(model[3]);
        return position;
    }

    glm::vec3 Transform::GetGlobalRotation()
    {
        glm::mat4 model(1.0f);

        if (m_setAsChild)
        {
            if (m_parent->HasComponent<Transform>())
            {
                std::sr1::shared_ptr<Transform> parentTransform = m_parent->GetComponent<Transform>();
                model = model * parentTransform->GetTransformMatrix();
            }

            else
            {
                std::cout << "Engine Warning: A Transform was set as a child node of another Transform, but could not find parent's Transform." << std::endl;
                std::cout << "Its parent will be removed, and the used GetRotation() function will only use local values." << std::endl;
                m_parent = NULL;
                m_setAsChild = false;
                return m_rotation;
            }

            /** Reference: https://stackoverflow.com/questions/29229611/quaternion-to-axis-angles
             *  https://stackoverflow.com/questions/17918033/glm-decompose-mat4-into-translation-and-rotation */

            glm::vec3 scale;
            glm::quat rotation;
            glm::vec3 translation;
            glm::vec3 skew;
            glm::vec4 perspective;

            glm::decompose(model, scale, rotation, translation, skew, perspective);

            glm::vec3 axisAngledRotation;

            float angle = glm::acos(rotation.w) * 2;
            float axisAngle = glm::sin(angle / 2.0f);

            if (axisAngle >= 0.0f && axisAngle < std::numeric_limits<float>::epsilon())
            {
                axisAngledRotation.x = 0;
                axisAngledRotation.y = 0;
                axisAngledRotation.z = 0;
            }

            else
            {
                axisAngledRotation.x = rotation.x / axisAngle;
                axisAngledRotation.y = rotation.y / axisAngle;
                axisAngledRotation.z = rotation.z / axisAngle;
            }

            axisAngledRotation = m_rotation * axisAngledRotation;
            return axisAngledRotation;
        }

        else
        {
            return m_rotation;
        }
    }

    glm::vec3 Transform::GetLocalPosition()
    {
        return m_position;
    }

    glm::vec3 Transform::GetLocalRotation()
    {
        return m_rotation;
    }

    glm::mat4 Transform::GetTransformMatrix()
    {
        glm::mat4 model(1.0f);

        if (m_setAsChild)
        {
            if (m_parent->HasComponent<Transform>())
            {
                std::sr1::shared_ptr<Transform> parentTransform = m_parent->GetComponent<Transform>();
				model = model * parentTransform->GetTransformMatrix();
            }

            else
            {
                std::cout << "Engine Warning: A Transform was set as a child node of another Transform, but could not find parent's Transform." << std::endl;
                std::cout << "Its parent will be removed, and the used GetTransform() function will only use local values." << std::endl;
                m_parent = NULL;
                m_setAsChild = false;
            }
        }

        model = glm::scale(model, m_scale);
        model = glm::rotate(model, m_rotation.x, glm::vec3(1, 0, 0));
        model = glm::rotate(model, m_rotation.y, glm::vec3(0, 1, 0));
        model = glm::rotate(model, m_rotation.z, glm::vec3(0, 0, 1));
        model = glm::translate(model, m_position);
        return model;
    }

    void Transform::RemoveChildStatus()
    {
        m_parent = NULL;
        m_setAsChild = false;
    }

    void Transform::SetAsChildrenOf(std::sr1::shared_ptr<Entity> _parent)
    {
        m_parent = _parent;
        m_setAsChild = true;
    }

    void Transform::SetLocalPosition(glm::vec3 _position)
    {
        m_position = _position;
    }

    void Transform::SetLocalRotation(glm::vec3 _rotation)
    {
        m_rotation = glm::vec3(glm::radians(_rotation.x),
                               glm::radians(_rotation.y),
                               glm::radians(_rotation.z));
    }

    void Transform::Rotate(glm::vec3 _rotation)
    {
        m_rotation.x += glm::radians(_rotation.x);
        m_rotation.y += glm::radians(_rotation.y);
        m_rotation.z += glm::radians(_rotation.z);
    }

    void Transform::Translate(glm::vec3 _translation)
    {
        m_position += _translation;
    }
}

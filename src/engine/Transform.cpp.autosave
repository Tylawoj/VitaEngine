#include "Transform.h"
#include "Exception.h"
#include "Entity.h"
#include <iostream>

namespace vita
{
    glm::vec3 Transform::GetPosition()
    {
        glm::mat4 model(1.0f);

        if (m_setAsChild)
        {
            try
            {
                std::sr1::shared_ptr<Transform> parentTransform = m_parent->GetComponent<Transform>();
                model = model * parentTransform->GetTransform();
            }

            catch (Exception& e)
            {
                std::cout << "Exception: " << e.What() << std::endl;
                std::cout << "A Transform has had its parent removed." << std::endl;
                m_parent = nullptr;
                m_setAsChild = false;
            }
        }

        //glm::vec3 position = m_localPosition * model;
       // return position;
    }

    glm::mat4 Transform::GetTransform()
    {
        glm::mat4 model(1.0f);

        if (m_setAsChild)
        {
            try
            {
                std::sr1::shared_ptr<Transform> parentTransform = m_parent->GetComponent<Transform>();
                model = model * parentTransform->GetTransform();
            }

            catch (Exception& e)
            {
                std::cout << "Exception: " << e.What() << std::endl;
                std::cout << "A Transform has had its parent removed." << std::endl;
                m_parent = nullptr;
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

    void Transform::SetAsChildrenOf(std::sr1::shared_ptr<Entity> _parent)
    {
        m_parent = _parent;
        m_setAsChild = true;
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

    Transform::Transform(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale)
    {
        m_position = _position;
        m_rotation = _rotation;
        m_scale = _scale;
        m_setAsChild = false;
    }

    Transform::Transform(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale, std::sr1::shared_ptr<Entity> _parent)
    {
        m_position = _position;
        m_rotation = _rotation;
        m_scale = _scale;
        m_setAsChild = true;
        m_parent = _parent;
    }
}

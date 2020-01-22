#include "BoxCollider.h"
#include "Core.h"
#include "Entity.h"
#include "Transform.h"

namespace vita
{
    BoxCollider::BoxCollider(glm::vec3 _size, glm::vec3 _offset, bool _solid)
    {
        m_size = _size;
        m_offset = _offset;
        m_solid = _solid;
    }

    void BoxCollider::OnCollisionUpdate()
    {
        std::vector<std::sr1::shared_ptr<Entity>> boxColliders = GetCore()->GetEntities<BoxCollider>();

        glm::vec3 currentPosition = GetEntity()->GetComponent<Transform>()->GetGlobalPosition() + m_offset;

        for (std::vector<std::sr1::shared_ptr<Entity>>::iterator boxCollidingEntities = boxColliders.begin();
             boxCollidingEntities != boxColliders.end(); boxCollidingEntities++)
        {
            if ((*boxCollidingEntities) == GetEntity())
            {
                continue;
            }

            std::sr1::shared_ptr<BoxCollider> otherCollider = (*boxCollidingEntities)->GetComponent<BoxCollider>();

            glm::vec3 newPosition = otherCollider->GetCollisionResponse(currentPosition, m_size);
            newPosition = newPosition - m_offset;

            GetEntity()->GetComponent<Transform>()->SetLocalPosition(newPosition);
        }
    }

    bool BoxCollider::IsColliding(glm::vec3 _position, glm::vec3 _size)
    {
        glm::vec3 a = GetEntity()->GetComponent<Transform>()->GetGlobalPosition() + m_offset;
        glm::vec3 b = _position;

        if (a.x > b.x) // a right of b
        {
            if (a.x - m_size.x > b.x + _size.x) // left edge of a greater than right edge of b (not colliding)
            {
                return false;
            }
        }
        else
        {
            if (b.x - _size.x > a.x + m_size.x)
            {
                return false;
            }
        }

        if (a.z > b.z) // a front of b
        {
            if (a.z - m_size.z > b.z + _size.z) // back edge of a greater than front edge of b (not colliding)
            {
                return false;
            }
        }
        else
        {
            if (b.z - _size.z > a.z + m_size.z)
            {
                return false;
            }
        }

        if (a.y > b.y) // a above b
        {
            if (a.y - m_size.y > b.y + _size.y) // bottom edge of a greater than top edge of b (not colliding)
            {
                return false;
            }
        }
        else
        {
            if(b.y - _size.y > a.y + m_size.y)
            {
                return false;
            }
        }

        return true;
    }

    glm::vec3 BoxCollider::GetCollisionResponse(glm::vec3 _position, glm::vec3 _size)
    {
        float amount = 0.1f;
        float step = 0.1f;

        glm::vec3 storePosition = _position;

        if (!m_solid)
        {
            while (true)
            {
                if (amount < 5.0f)
                {
                    if (!IsColliding(_position, _size)) { break; }

                    _position.x += amount;

                    if (!IsColliding(_position, _size)) { break; }

                    _position.x -= amount;
                    _position.x -= amount;

                    if (!IsColliding(_position, _size)) { break; }

                    _position.x += amount;
                    _position.z += amount;

                    if (!IsColliding(_position, _size)) { break; }

                    _position.z -= amount;
                    _position.z -= amount;

                    if (!IsColliding(_position, _size)) { break; }

                    _position.z += amount;
                    _position.y += amount;

                    if (!IsColliding(_position, _size)) { break; }

                    _position.y -= amount;
                    _position.y -= amount;

                    if (!IsColliding(_position, _size)) { break; }

                    _position.y += amount;
                    amount += step;
                }

                else
                {
                    _position = storePosition;
                }
            }

            return _position;
        }

        else
        {
            return _position;
        }
    }
}

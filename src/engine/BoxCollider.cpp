/** @file BoxCollider.cpp
 *  @brief Implementation of functions for the BoxCollider class.
 */

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

        /// Set the current position to Entity's Transform position, with a pre-set offset.
        glm::vec3 currentPosition = GetEntity()->GetComponent<Transform>()->GetGlobalPosition() + m_offset;

        /// Loop through other Entities with box colliders in the scene.
        for (std::vector<std::sr1::shared_ptr<Entity>>::iterator boxCollidingEntities = boxColliders.begin();
             boxCollidingEntities != boxColliders.end(); boxCollidingEntities++)
        {
            /// If the iterator is the same as this entity, continue looping.
            if ((*boxCollidingEntities) == GetEntity())
            {
                continue;
            }

            /// Get the other box collider.
            std::sr1::shared_ptr<BoxCollider> otherCollider = (*boxCollidingEntities)->GetComponent<BoxCollider>();

            /// Set the new position depending on the collision response with the other box collider.
            glm::vec3 newPosition = otherCollider->GetCollisionResponse(m_solid, currentPosition, m_size);
            /// Remove the offset from the new position.
            newPosition = newPosition - m_offset;

            /// Set the new position to this Entity's transform.
            GetEntity()->GetComponent<Transform>()->SetLocalPosition(newPosition);
        }
    }

    bool BoxCollider::IsColliding(glm::vec3 _position, glm::vec3 _size)
    {
        /// Set the 'a' bounding box's position to the current Transform position.
        glm::vec3 a = GetEntity()->GetComponent<Transform>()->GetGlobalPosition() + m_offset;
        /// Set the 'b' bounding box's position to the other box collider's Transform position.
        glm::vec3 b = _position;

        /// Perform the AABB bounding box test.
        if (a.x > b.x) ///< Position of 'a' is right of 'b'.
        {
            if (a.x - m_size.x > b.x + _size.x) ///< Left edge of 'a' greater than right edge of 'b', not colliding.
            {
                return false;
            }
        }

        else
        {
            if (b.x - _size.x > a.x + m_size.x) ///< Left edge of 'b' greater than right edge of 'a', not colliding.
            {
                return false;
            }
        }

        if (a.z > b.z) ///< Position of 'a' is in front of 'b'.
        {
            if (a.z - m_size.z > b.z + _size.z) ///< Back edge of 'a' is greater than front edge of 'b', not colliding.
            {
                return false;
            }
        }

        else
        {
            if (b.z - _size.z > a.z + m_size.z) ///< Back edge of 'b' is greater than front edge of 'a', not colliding.
            {
                return false;
            }
        }

        if (a.y > b.y) ///< Position of 'a' is above 'b'.
        {
            if (a.y - m_size.y > b.y + _size.y) ///< Bottom edge of 'a' is greater than the top edge of 'b', not colliding.
            {
                return false;
            }
        }

        else
        {
            if (b.y - _size.y > a.y + m_size.y) ///< Bottom edge of 'b' is greater than the top edge of 'a', not colliding.
            {
                return false;
            }
        }

        return true; ///< If all tests failed, the box colliders are colliding.
    }

    glm::vec3 BoxCollider::GetCollisionResponse(bool _solid, glm::vec3 _position, glm::vec3 _size)
    {
        float amount = 0.1f; ///< The amount added to each axis during the cludge.
        float step = 0.1f; ///< The incrementing value after each run of the loop.

        glm::vec3 storePosition = _position; ///< Store the current position of the other box collider.

        /// Check before the tests if the other box collider is solid (inmovable).
        if (!_solid)
        {
            while (true) ///< While the boxes are colliding...
            {
                if (amount < 5.0f) ///< Ensure the objects will not move too much after removing the collision.
                {
                    /** Move the other box collider a little in each axis and see
                     *  if the colliders are still colliding after each test. */
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

                /** If the move amount gets over 5.0f, break the test
                 *  and just return the other box collider to the previous position. */
                else
                {
                    _position = storePosition;
                }
            }

            return _position;
        }

        /// If the other box collider is solid (inmovable), return (do not change its position).
        else
        {
            return _position;
        }
    }
}

/** @file BoxCollider.h
 *  @brief Class for storing an AABB bounding box and resolving collisions.
 */

#include "Component.h"
#include <glm/ext.hpp>

namespace vita
{
    class BoxCollider : public Component
    {
        private:
            glm::vec3 m_size; /// Size of the collider.
            glm::vec3 m_offset; ///< Offset from Entity's position.
            bool m_solid; ///< Movability of the collider.
            /**
             * @brief Checks whether another collider collides with the current one.
             * @param _position Position of another collider.
             * @param _size Size of another collider.
             * @return Returns whether the collision happened or not.
             */
            bool IsColliding(glm::vec3 _position, glm::vec3 _size);
            glm::vec3 GetCollisionResponse(bool _solid, glm::vec3 _position, glm::vec3 _size);
        public:
            /**
             * @brief Initializes a BoxCollider, setting its size, offset from Entity's position
             * and whether the Entity is solid (inmovable).
             * @param _size The size of the collider.
             * @param _offset The offset from Entity's position.
             * @param _solid Sets whether the Entity is movable or not.
             */
            BoxCollider(glm::vec3 _size, glm::vec3 _offset, bool _solid);
            /// @brief Checks for collisions with any other colliders in the scene.
            void OnCollisionUpdate();
            /**
             * @brief Sets the size of the collider.
             * @param _size The size of the collider.
             */
            void SetSize(glm::vec3 _size);
            /**
             * @brief Sets the offset for the collider from Entity's position.
             * @param _offset The offset from Entity's position.
             */
            void SetOffset(glm::vec3 _offset);
    };
}

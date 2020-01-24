/** @file Transform.h
 *  @brief Class for storing the transformation matrix of an Entity.
 */

#include "Component.h"
#include <glm/ext.hpp>
#include <list>

namespace vita
{
    class Transform : public Component
    {
        private:
            glm::vec3 m_position;
            glm::vec3 m_rotation;
            glm::vec3 m_scale;
            std::sr1::shared_ptr<Entity> m_parent; ///< The parent node of this Transform.
            bool m_setAsChild; ///< Whether this Transform has a parent set.
        public:
            /**
             * @brief Constructs a Transform, using the set position, rotation and scale.
             * Use degrees and axis-angled rotation only.
             * @param _position The position of the Entity.
             * @param _rotation The rotation of the Entity.
             * @param _scale The scale of the Entity.
             */
            Transform(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale);
            /**
             * @brief Constructs a Transform, using the set position, rotation and scale,
             * and sets it as a child to a parent Entity. Use degrees and axis-angled rotation only.
             * @param _position The position of the Entity.
             * @param _rotation The rotation of the Entity.
             * @param _scale The scale of the Entity.
             * @param _parent The parent Transform.
             */
            Transform(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale, std::sr1::shared_ptr<Entity> _parent);
            /**
             * @brief Returns the position from this Transform, taking into account
             * parent Entity's position.
             * @return Global position of this Transform.
             */
            glm::vec3 GetGlobalPosition();
            /**
             * @brief Returns the rotation from this Transform, taking into account
             * parent Entity's rotation.
             * @return Global rotation of this Transform.
             */
            glm::vec3 GetGlobalRotation();
            /**
             * @brief Returns the scale from this Transform, taking into account
             * parent Entity's scale.
             * @return Global scale of this Transform.
             */
            glm::vec3 GetGlobalScale();
            /**
             * @brief Returns the local position of this Transform.
             * @return Local position of this Transform.
             */
            glm::vec3 GetLocalPosition();
            /**
             * @brief Returns the local rotation of this Transform.
             * @return Local rotation of this Transform.
             */
            glm::vec3 GetLocalRotation();
            /**
             * @brief Returns the local scale of this Transform.
             * @return Local scale of this Transform.
             */
            glm::vec3 GetLocalScale();
            /**
             * @brief Creates a transformation matrix using the Transform's position,
             * rotation and scale and returns it.
             * @return A transformation matrix.
             */
            glm::mat4 GetTransformMatrix();
            /// @brief Removes the child status from this Transform.
            void RemoveChildStatus();
            /**
             * @brief Rotates the Transform using axis-angled rotation. Use degrees only.
             * @param _rotation Axis-angled rotation.
             */
            void Rotate(glm::vec3 _rotation);
            /**
             * @brief Sets this Transform as a child of another Entity.
             * @param _parent The parent Entity.
             */
            void SetAsChildrenOf(std::sr1::shared_ptr<Entity> _parent);
            /**
             * @brief Sets the local position of this Transform.
             * @param _position A position vector.
             */
            void SetLocalPosition(glm::vec3 _position);
            /**
             * @brief Sets the local rotation of this Transform.
             * Use degrees and axis-angled rotation only.
             * @param _rotation Axis-angled rotation.
             */
            void SetLocalRotation(glm::vec3 _rotation);
            /**
             * @brief Translates the local position of this Transform.
             * @param _translation Translation vector.
             */
            void Translate(glm::vec3 _translation);
    };
}


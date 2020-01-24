/** @file Entity.h
 *  @brief Class (equivalent to a GameObject) used for storing Components.
 */

/// Include guards are needed, as Entity is used in a template function in Core.
#ifndef _VITA_ENTITY_H_
#define _VITA_ENTITY_H_

#include "Component.h"
#include "Exception.h"
#include <sr1/memory>
#include <list>

namespace vita
{
    class Core;

    class Entity : public std::enable_shared_from_this<Entity>
    {
        /** Core is set as a friend class to set itself as a weak_ptr during
         *  the construction of an Entity. */
        friend class vita::Core;

        private:
            std::list<std::shared_ptr<Component>> m_components; ///< The Components this Entity stores.
            std::sr1::weak_ptr<Core> m_core; ///< A weak_ptr to Core, used by Components.
            std::sr1::weak_ptr<Entity> m_self; ///< A weak_ptr to itself, used to forward itself during the constructions of Components.
            /// @brief Checks if there are any non-used components and destroys them.
            void CheckForDeadComponents();
        public:
            /**
             * @brief Constructs and returns a Component of the specified type to the user passing the arguments
             * to the Component's constructor, and stores it in the Entity.
             * @param _arguments The arguments used by a constructor of the specified type Component.
             * @return A Component of a specified type.
             */
            template <typename T, typename... A> std::sr1::shared_ptr<T> AddComponent(A... _arguments)
            {
                std::sr1::shared_ptr<T> component = std::make_shared<T>(_arguments...); ///< Constructs a Component using its own constructor, passing in specified arguments.
                component->m_entity = m_self; ///< Sets the Entity itself as a weak_ptr in the Component.
                component->m_alive = true; ///< Sets the Component as alive.

                m_components.push_back(component); ///< Stores the Component in Entity's component list.

                return component; ///< Returns the Component.
            }
            /// @brief Calls the OnCollisionUpdate() function in each Component stored.
            void CollisionUpdate();
            /// @brief Calls the OnDisplay() function in each Component stored.
            void Display();
            /**
             * @brief Returns a Component of the specified type.
             * @return A Component with the specified type.
             */
            template<typename T> std::sr1::shared_ptr<T> GetComponent()
            {
                for (std::list<std::sr1::shared_ptr<Component>>::iterator componentIterator = m_components.begin(); componentIterator != m_components.end(); componentIterator++)
                {
                    /// Compares the type of the iterated component with the searched type.
                    std::sr1::shared_ptr<T> component = std::dynamic_pointer_cast<T>(*componentIterator);

                    /// Checks whether it could cast the iterated component to the searched type.
                    if (component != NULL)
                    {
                        return component;
                    }
                }

                throw Exception("GetComponent() could not find a Component of specified type in an Entity. Hint: Use HasComponent() first if you are unsure if an Entity contains this Component.");
            }
            /**
             * @brief Returns the Core object.
             * @return The Core of the engine.
             */
            std::sr1::shared_ptr<Core> GetCore();
            /// @brief Calls the OnGUI() function in each Component stored.
            void GUI();
            /**
             * @brief Returns whether the Entity has a Component of the specified type.
             * @return Whether the Entity has a Component of the specified type or not.
             */
            template<typename T> bool HasComponent()
            {
                for (std::list<std::sr1::shared_ptr<Component>>::iterator componentIterator = m_components.begin(); componentIterator != m_components.end(); componentIterator++)
                {
                    /// Compares the type of the iterated component with the searched type.
                    std::sr1::shared_ptr<T> component = std::dynamic_pointer_cast<T>(*componentIterator);

                    /// Checks whether it could cast the iterated component to the searched type.
                    if (component != NULL)
                    {
                        return true;
                    }
                }

                return false;
            }
             /// @brief Calls the OnInit() function in each Component stored.
            void Init();
            /// @brief Calls the OnTick() function in each Component stored.
            void Tick();
    };
}

#endif

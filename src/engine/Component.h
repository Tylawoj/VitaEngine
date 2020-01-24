/** @file Component.h
 *  @brief Base class for any components used by Entities.
 */

/// As Component is used as a base class, include guards are needed.
#ifndef _VITA_COMPONENT_H_
#define _VITA_COMPONENT_H_

#include <sr1/memory>

namespace vita
{
    class Camera;
    class Core;
    class Entity;
    class Environment;
    class GUI;
    class Input;
    class Resources;
    class Transform;

    class Component
    {
        /** Entity is set as a friend class to set itself as a weak_ptr during
         *  the construction of a Component. */
        friend class vita::Entity;

        private:
            std::sr1::weak_ptr<Entity> m_entity; ///< Weak_ptr to Entity containing this component.
            bool m_alive; ///< Defines whether the component should be still in the scene.

        public:
            /**
             * @brief Returns the owner entity.
             * @return The entity that stores this component.
             */
            std::sr1::shared_ptr<Entity> GetEntity();
            /**
             * @brief Returns the currently set camera in Core.
             * @return The currently used camera.
             */
            std::sr1::shared_ptr<Camera> GetCurrentCamera();
            /**
             * @brief Returns the core of the engine.
             * @return The core of the engine.
             */
            std::sr1::shared_ptr<Core> GetCore();
            /**
             * @brief Returns the GUI, allowing to draw 2D textures on screen.
             * @return The GUI allowing to draw 2D textures on screen.
             */
            std::sr1::shared_ptr<GUI> GetGUI();
            /**
             * @brief Returns the Input class, storing keyboard
             * and mouse input.
             * @return The Input class with current inputs.
             */
            std::sr1::shared_ptr<Input> GetInput();
            /**
             * @brief Returns the Environment class, storing the
             * current delta time.
             * @return The Environment class with the delta time.
             */
            std::sr1::shared_ptr<Environment> GetEnvironment();
            /**
             * @brief Returns the Resources class, storing the
             * currently used resources.
             * @return The Resources class with currently used resources.
             */
            std::sr1::shared_ptr<Resources> GetResources();
            /**
             * @brief Returns whether the component is alive or not (still in the scene).
             * @return Returns if the component is alive or not.
             */
            bool IsAlive();
            /// @brief Kills the component, removing it from the scene.
            void Kill();
            /// @brief Allows components to perform actions dependent on collision.
            virtual void OnCollisionUpdate() {}
            /// @brief Allows components to render after all physics calculations.
            virtual void OnDisplay() {}
            /// @brief Allows components to draw GUI textures.
            virtual void OnGUI() {}
            /// @brief Allows components to initialize themselves.
            virtual void OnInit() {}
            /// @brief Allows components to perform actions on each tick.
            virtual void OnTick() {}
    };
}

#endif

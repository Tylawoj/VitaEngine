/** @file Resource.h
 *  @brief Base class for any resources used by Components.
 */

/// As Resource is used as a base class, include guards are needed.
#ifndef _VITA_RESOURCE_H_
#define _VITA_RESOURCE_H_

#include <sr1/memory>
#include <sr1/vector>
#include <string>

namespace rend
{
    struct Context;
}

namespace vita
{
    class Core;
    class Resources;

    class Resource
    {
        /** Resources is set as a friend class to set a weak_ptr to Core
         *  during the construction of a Resource. */
        friend class vita::Resources;

        private:
            bool m_alive; ///< Defines whether the resource is still being used.
            std::sr1::weak_ptr<Core> m_core;
        public:
            /**
             * @brief Returns the rend Context, used for rendering.
             * @return rend's Context stored in Core.
             */
            std::sr1::shared_ptr<rend::Context> GetContext();
            /**
             * @brief Returns the Core object.
             * @return The Core of the engine.
             */
            std::sr1::shared_ptr<Core> GetCore();
            /**
             * @brief Returns whether the resource is alive or not (still used in the scene).
             * @return Returns if the resource is alive or not.
             */
            bool IsAlive();
            /// @brief Kills the component, removing it from the scene.
            void Kill();
            /// @brief Allows resources to load a required file.
            virtual void OnLoad(const std::string& _path) {}
            /// @brief Allows resources to required files.
            virtual void OnLoad(std::sr1::vector<std::string> _paths) {}
    };
}

#endif

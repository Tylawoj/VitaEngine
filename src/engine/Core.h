/** @file Core.h
 *  @brief Core class responsible for storing the core of the engine, along with its required members.
 */

#include "Entity.h"
#include "Resources.h"
#include <rend/rend.h>
#include <sr1/noncopyable> ///< Noncopyable class is used to disallow from copying the Core to another pointer.
#include <sr1/memory>
#include <list>

namespace vita
{
    class Audio;
    class Camera;
    class Environment;
    class GUI;
    class Input;
    class Screen;

    class Core : public std::enable_shared_from_this<Core>, public std::sr1::noncopyable
    {
        private:
            std::sr1::shared_ptr<Audio> m_audio;
            std::sr1::shared_ptr<Camera> m_camera;
            std::list<std::sr1::shared_ptr<Entity>> m_entities; ///< List of all entities in the scene.
            std::sr1::shared_ptr<Environment> m_environment;
            bool m_isRunning; ///< Determines whether the Core should be still running.
            std::sr1::shared_ptr<rend::Context> m_rendContext; ///< Rend context used in rendering.
            std::sr1::shared_ptr<GUI> m_gui;
            std::sr1::shared_ptr<Input> m_input;
            std::sr1::shared_ptr<Resources> m_resources; ///< Shared_ptr to the Resources class, storing all used resources at the moment.
            std::sr1::shared_ptr<Screen> m_screen;
            std::sr1::weak_ptr<Core> m_self; ///< Weak_ptr to itself, used to forward itself during the constructions of Entities.

            /// @brief Checks if there are any non-used resources and destroys them.
            void CheckForDeadResources();
        public:
            /**
             * @brief Loads and returns a resource to the user, storing it in the Core.
             * @return A loaded resource.
             */
            template <typename T> std::sr1::shared_ptr<T> AddResource(std::string _path)
            {
                return m_resources->Load<T>(_path);
            }

            /**
             * @brief Returns a vector of Entities with the specified type.
             * @return A vector of Entities with the specified type.
             */
            template<typename T> std::sr1::vector<std::sr1::shared_ptr<Entity>> GetEntities()
            {
                std::sr1::vector<std::sr1::shared_ptr<Entity>> entities;

                for (std::list<std::sr1::shared_ptr<Entity>>::iterator entityIterator = m_entities.begin(); entityIterator != m_entities.end(); entityIterator++)
                {
                    /// Checks if an Entity has a component of the specified type.
                    if ((*entityIterator)->HasComponent<T>())
                    {
                        entities.push_back(*entityIterator); ///< Pushes back the Entity onto a return vector.
                    }
                }

                return entities;
            }

            /**
             * @brief Returns an Entity to the user, storing it in the list of Entities.
             * @return An Entity.
             */
            std::sr1::shared_ptr<Entity> AddEntity();
            /**
             * @brief Returns the rend Context, used for rendering.
             * @return rend's Context stored in Core.
             */
            std::sr1::shared_ptr<rend::Context> GetContext();
            /**
             * @brief Returns the currently used camera.
             * @return The currently used camera by Core.
             */
            std::sr1::shared_ptr<Camera> GetCurrentCamera();
            /**
             * @brief Returns the Environment class, which stores information about the environment.
             * @return The Environment class stored in Core.
             */
            std::sr1::shared_ptr<Environment> GetEnvironment();
            /**
             * @brief Returns the Input class, which stores all mouse and keyboard inputs.
             * @return The Input class stored in Core.
             */
            std::sr1::shared_ptr<Input> GetInput();
            /**
             * @brief Returns the GUI class, allowing to draw 2D textures for GUI.
             * @return The GUI class stored in Core.
             */
            std::sr1::shared_ptr<GUI> GetGUI();
            /**
             * @brief Returns a shared_ptr to the Resources class, which stores all currently used resources.
             * @return The Resources class, which stores all currently used resources.
             */
            std::sr1::shared_ptr<Resources> GetResources();
            /**
             * @brief Returns the Screen class, which stores a SDL_Window and its width and height.
             * @return The Screen class, which stores a SDL_Window and its width and height.
             */
            std::sr1::shared_ptr<Screen> GetScreen();
            /**
             * @brief Initializes the Core and its class members.
             * @param _title The title of the window.
             * @param _width The width of the window.
             * @param _height The height of the window.
             * @param _samples Amount of multisampling samples.
             * @return An initialized Core.
             */
            static std::sr1::shared_ptr<Core> Init(std::string _title, int _width, int _height, int _samples);
            /**
             * @brief Sets the currently used camera.
             * @param _camera A Camera class.
             */
            void SetCurrentCamera(std::sr1::shared_ptr<Camera> _camera);
            /// @brief Sets the Core to run.
            void Start();
            /// @brief Stops the Core from running.
            void Stop();
            /// @brief Runs the Core, which initializes the Entities with its Components.
            void Run();
    };
}

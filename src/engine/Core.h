/** @file Core.h
 *  @brief Core class responsible for storing the core of the engine, along with its required members.
 */

#include <rend/rend.h>
#include <sr1/noncopyable> ///< Noncopyable class is used to disallow from copying the Core to another pointer.
#include <sr1/memory>
#include <list>

#include "Resources.h"

namespace vita
{
    class Camera;
    class Entity;
    class Environment;
    class Keyboard;
    class MeshRenderer;
    class Screen;

    class Core : public std::enable_shared_from_this<Core>, public std::sr1::noncopyable
    {
        friend class vita::Entity;

        private:
            std::sr1::weak_ptr<Camera> m_currentCamera;
            std::sr1::weak_ptr<Core> m_self;
            std::sr1::shared_ptr<rend::Context> m_context;
            std::sr1::shared_ptr<Environment> m_environment;
            std::list<std::sr1::shared_ptr<Entity>> m_entities;
            std::sr1::shared_ptr<Keyboard> m_keyboard;
            std::sr1::shared_ptr<MeshRenderer> m_meshRenderer;
            std::sr1::shared_ptr<Resources> m_resources;
            std::sr1::shared_ptr<Screen> m_screen;
            bool m_isRunning;
            void CheckForDeadResources();
        public:
            template <typename T> std::sr1::shared_ptr<T> AddResource(std::string _path)
            {
                return m_resources->Load<T>(_path);
            }

            std::sr1::shared_ptr<Entity> AddEntity();
            std::sr1::shared_ptr<Camera> GetCurrentCamera();
            std::sr1::shared_ptr<rend::Context> GetContext();
            std::sr1::shared_ptr<Resources> GetResources();
            static std::sr1::shared_ptr<Core> Init(std::string _title, int _width, int _height, int _samples);
            void Start();
            void Stop();
            void Run();
	};
}

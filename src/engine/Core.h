/** @file Core.h
 *  @brief Core class responsible for storing the core of the engine, along with its required members.
 *
 *  Core stores all of the Entities in the game,
 */

#include <SDL2/SDL.h>
#include <sr1/noncopyable> ///< Noncopyable class is used to disallow from copying the Core to another pointer.
#include <sr1/memory>
#include <list>

namespace vita
{
    class Entity;
    class Environment;
    class Keyboard;
    class Resources;
    class Screen;

    class Core : public std::enable_shared_from_this<Core>, public std::sr1::noncopyable
    {
        friend class vita::Entity;

        private:
            std::sr1::weak_ptr<Core> m_self;
            std::sr1::shared_ptr<Environment> m_environment;
            std::list<std::sr1::shared_ptr<Entity>> m_entities;
            std::sr1::shared_ptr<Keyboard> m_keyboard;
            std::sr1::shared_ptr<Resources> m_resources;
            std::sr1::shared_ptr<Screen> m_screen;
            SDL_Window* m_window;
            bool m_isRunning;
        public:
            std::sr1::shared_ptr<Entity> AddEntity();
            static std::sr1::shared_ptr<Core> Initialize();
            void Start();
            void Stop();
            void Run();
	};
}

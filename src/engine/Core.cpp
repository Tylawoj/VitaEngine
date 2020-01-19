#include "Core.h"
#include "Exception.h"
#include "Entity.h"
#include "Resource.h"
#include "Screen.h"
#include <SDL2/SDL.h>
#include <chrono>

namespace vita
{
    std::sr1::shared_ptr<Entity> Core::AddEntity()
    {
        std::sr1::shared_ptr<Entity> entity = std::make_shared<Entity>();
        m_entities.push_back(entity);
        entity->m_core = m_self;

        return entity;
    }

    std::sr1::shared_ptr<Camera> Core::GetCamera()
    {
        return m_camera;
    }

    std::sr1::shared_ptr<Core> Core::Init(std::string _title, int _width, int _height, int _samples)
    {
        std::sr1::shared_ptr<Core> core = std::make_shared<Core>();
        core->m_self = core;

        try
        {
            core->m_screen = std::make_shared<Screen>(_title, _width, _height, _samples);
            core->m_context = rend::Context::initialize();
        }

        catch (Exception& e)
        {
            std::cout << "Critical Engine Exception: " << e.What() << std::endl;
            std::cout << "The engine will quit." << std::endl;

            return NULL;
        }

        catch (std::exception& e)
        {
            std::cout << "Critical System Exception: " << e.what() << std::endl;
            std::cout << "The engine will quit." << std::endl;

            return NULL;
        }

        core->m_resources = std::make_shared<Resources>();
        core->m_resources->m_core = core;

        return core;
    }

    void Core::Start()
    {
        m_isRunning = true;
    }

    void Core::Stop()
    {
        m_isRunning = false;
    }

    void Core::CheckForDeadResources()
    {
        for (std::list<std::sr1::shared_ptr<Resource>>::iterator resourceIterator = m_resources->m_resources.begin();
             resourceIterator != m_resources->m_resources.end();)
        {
            if (!(*resourceIterator)->IsAlive())
            {
                resourceIterator = m_resources->m_resources.erase(resourceIterator);
            }

            else
            {
                resourceIterator++;
            }
        }
    }

    std::sr1::shared_ptr<rend::Context> Core::GetContext()
    {
        return m_context;
    }

    std::sr1::shared_ptr<Resources> Core::GetResources()
    {
        return m_resources;
    }

    void Core::Run()
    {
        std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
        std::chrono::system_clock::time_point now;

        SDL_Event event = { 0 };

        for (std::list<std::sr1::shared_ptr<Entity>>::iterator entityIterator = m_entities.begin(); entityIterator != m_entities.end(); entityIterator++)
        {
            (*entityIterator)->Init();
        }

        while (m_isRunning)
        {
            while (SDL_PollEvent(&event) != 0)
            {
                if (event.type == SDL_QUIT)
                {
                    m_isRunning = false;
                }
            }

            for (std::list<std::sr1::shared_ptr<Entity>>::iterator entityIterator = m_entities.begin(); entityIterator != m_entities.end(); entityIterator++)
            {
                (*entityIterator)->Tick();
            }

            m_screen->ClearScreen();

            for (std::list<std::sr1::shared_ptr<Entity>>::iterator entityIterator = m_entities.begin(); entityIterator != m_entities.end(); entityIterator++)
            {
                (*entityIterator)->Display();
            }

            m_screen->GLSwapWindow();

            now = std::chrono::system_clock::now();

            if (std::chrono::duration_cast<std::chrono::milliseconds>(now - start).count() > 1000)
            {
                std::list<std::sr1::shared_ptr<Resource>>::iterator resourceIterator;

                for (std::list<std::sr1::shared_ptr<Resource>>::iterator resourceIterator = m_resources->m_resources.begin();
                     resourceIterator != m_resources->m_resources.end(); resourceIterator++)
                {
                    if (resourceIterator->use_count() == 1)
                    {
                        (*resourceIterator)->Kill();
                    }
                }

                CheckForDeadResources();

                start = std::chrono::system_clock::now();
            }
        }
    }
}

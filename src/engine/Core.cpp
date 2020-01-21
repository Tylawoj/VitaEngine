#include "Core.h"
#include "Audio.h"
#include "Environment.h"
#include "Exception.h"
#include "Entity.h"
#include "Resource.h"
#include "Screen.h"
#include "SoundSource.h"
#include "Transform.h"
#include <SDL2/SDL.h>
#include <chrono>

namespace vita
{
    std::sr1::shared_ptr<Entity> Core::AddEntity()
    {
        std::sr1::shared_ptr<Entity> entity = std::make_shared<Entity>();
        entity->m_self = entity;
        entity->m_core = m_self;

        m_entities.push_back(entity);

        return entity;
    }

    std::sr1::shared_ptr<Camera> Core::GetCurrentCamera()
    {
        return m_camera;
    }

    void Core::SetCurrentCamera(std::sr1::shared_ptr<Camera> _camera)
    {
        m_camera = _camera;
    }

    std::sr1::shared_ptr<Core> Core::Init(std::string _title, int _width, int _height, int _samples)
    {
        std::sr1::shared_ptr<Core> core = std::make_shared<Core>();
        core->m_self = core;

        core->m_audio = std::make_shared<Audio>();

        try
        {
            core->m_screen = std::make_shared<Screen>(_title, _width, _height, _samples);
            core->m_rendContext = rend::Context::initialize();
            core->m_audio->Init();
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

        core->m_environment = std::make_shared<Environment>();

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
        return m_rendContext;
    }

    std::sr1::shared_ptr<Screen> Core::GetScreen()
    {
        return m_screen;
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

        m_environment->Init();

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

                if ((*entityIterator)->HasComponent<SoundSource>())
                {
                    std::sr1::shared_ptr<SoundSource> soundSource = (*entityIterator)->GetComponent<SoundSource>();
                    ALuint sourceId = soundSource->GetSourceId();
                    ALint state = 0;

                    alGetSourcei(sourceId, AL_SOURCE_STATE, &state);

                    if (state == AL_STOPPED && soundSource->GetAutoRemove())
                    {
                        soundSource->Kill();
                    }
                }
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

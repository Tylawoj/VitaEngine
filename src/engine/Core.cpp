/** @file Core.cpp
 *  @brief Implementation of functions for the Core class.
 */

#include "Core.h"
#include "Audio.h"
#include "Environment.h"
#include "Exception.h"
#include "Entity.h"
#include "GUI.h"
#include "Input.h"
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
        /// Sets the core and entity weak_ptrs in the created Entity.
        entity->m_self = entity;
        entity->m_core = m_self;

        /// Pushes back the entity onto the entities list.
        m_entities.push_back(entity);

        /// Returns the entity.
        return entity;
    }

    void Core::CheckForDeadResources()
    {
        for (std::list<std::sr1::shared_ptr<Resource>>::iterator resourceIterator = m_resources->m_resources.begin();
             resourceIterator != m_resources->m_resources.end();)
        {
            /// Checks whether the resource is alive, and if not, erases it from the list, destroying it.
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

    std::sr1::shared_ptr<Camera> Core::GetCurrentCamera()
    {
        return m_camera;
    }

    std::sr1::shared_ptr<Environment> Core::GetEnvironment()
    {
        return m_environment;
    }

    std::sr1::shared_ptr<GUI> Core::GetGUI()
    {
        return m_gui;
    }

    std::sr1::shared_ptr<Input> Core::GetInput()
    {
        return m_input;
    }

    std::sr1::shared_ptr<Core> Core::Init(std::string _title, int _width, int _height, int _samples)
    {
        std::sr1::shared_ptr<Core> core = std::make_shared<Core>();
        core->m_self = core;
        /// Constructs the Audio and Input members.
        core->m_audio = std::make_shared<Audio>();
        core->m_input = std::make_shared<Input>();
        core->m_input->m_core = core;

        try
        {
            /** These lines are set in a try-catch statement as they are trying to
             *  initialize SDL2, OpenGL and OpenAL, which may throw exceptions. */
            core->m_screen = std::make_shared<Screen>(_title, _width, _height, _samples);
            core->m_rendContext = rend::Context::initialize();
            core->m_audio->Init();
        }

        catch (Exception& e)
        {
            std::cout << "Critical Engine Exception: " << e.What() << std::endl;
            std::cout << "The engine will quit." << std::endl;

            /// As the engine cannot run without SDL2, OpenGL or OpenAL, it has to quit.
            return NULL;
        }

        catch (std::exception& e)
        {
            std::cout << "Critical System Exception: " << e.what() << std::endl;
            std::cout << "The engine will quit." << std::endl;

            /// As the engine cannot run without SDL2, OpenGL or OpenAL, it has to quit.
            return NULL;
        }

        core->m_resources = std::make_shared<Resources>();
        core->m_resources->m_core = core;

        core->m_environment = std::make_shared<Environment>();
        core->m_gui = std::make_shared<GUI>();
        core->m_gui->m_core = core;
        core->m_gui->Init();

        return core;
    }

    std::sr1::shared_ptr<rend::Context> Core::GetContext()
    {
        return m_rendContext;
    }

    std::sr1::shared_ptr<Resources> Core::GetResources()
    {
        return m_resources;
    }

    std::sr1::shared_ptr<Screen> Core::GetScreen()
    {
        return m_screen;
    }

    void Core::Run()
    {
        /// Creates a timer for garbage collecting the resources.
        std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
        std::chrono::system_clock::time_point now;

        for (std::list<std::sr1::shared_ptr<Entity>>::iterator entityIterator = m_entities.begin(); entityIterator != m_entities.end(); entityIterator++)
        {
            /// Initializes all Components in the entities stored in Core.
            (*entityIterator)->Init();
        }

        /// Initializes the environment here to get an accurate previous tick measurement.
        m_environment->Init();

        while (m_isRunning)
        {
            /// Checks for inputs in this tick.
            m_input->UpdateInput();

            for (std::list<std::sr1::shared_ptr<Entity>>::iterator entityIterator = m_entities.begin(); entityIterator != m_entities.end(); entityIterator++)
            {
                /// Calls the OnTick() function in Components of each Entity stored.
                (*entityIterator)->Tick();
            }

            /// Clears the stored pressed and released keys/mouse buttons.
            m_input->ClearInput();

            for (std::list<std::sr1::shared_ptr<Entity>>::iterator entityIterator = m_entities.begin(); entityIterator != m_entities.end(); entityIterator++)
            {
                /// Calls the OnCollisionUpdate() function in Components of each Entity stored.
                (*entityIterator)->CollisionUpdate();
            }

            /// Clears the screen from the previous render.
            m_screen->ClearScreen();

            for (std::list<std::sr1::shared_ptr<Entity>>::iterator entityIterator = m_entities.begin(); entityIterator != m_entities.end(); entityIterator++)
            {
                /// Calls the OnGUI() function in Components of each Entity stored.
                (*entityIterator)->GUI();
            }

            for (std::list<std::sr1::shared_ptr<Entity>>::iterator entityIterator = m_entities.begin(); entityIterator != m_entities.end(); entityIterator++)
            {
                /// Calls the OnDisplay() function in Components of each Entity stored.
                (*entityIterator)->Display();
            }

            /// Swaps the window with the current OpenGL render.
            m_screen->GLSwapWindow();

            now = std::chrono::system_clock::now();

            /// Checks each second for resources no longer used.
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

            /// Stores the time of this tick.
            m_environment->OnTick();
        }
    }

    void Core::SetCurrentCamera(std::sr1::shared_ptr<Camera> _camera)
    {
        m_camera = _camera;
    }

    void Core::Start()
    {
        m_isRunning = true;
    }

    void Core::Stop()
    {
        m_isRunning = false;
    }
}

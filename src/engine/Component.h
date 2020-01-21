#ifndef _VITA_COMPONENT_H_
#define _VITA_COMPONENT_H_

#include <sr1/memory>

namespace vita
{
    class Camera;
    class Core;
    class Entity;
    class Environment;
    class Input;
    class Resources;
    class Transform;

    class Component
    {
        friend class vita::Entity;

        private:
            std::sr1::weak_ptr<Entity> m_entity;
            bool m_alive;

        public:
            virtual void OnInit() {}
            virtual void OnTick() {}
            virtual void OnDisplay() {}
            bool IsAlive();
            void Kill();

            std::sr1::shared_ptr<Entity> GetEntity();
            std::sr1::shared_ptr<Camera> GetCurrentCamera();
            std::sr1::shared_ptr<Core> GetCore();
            std::sr1::shared_ptr<Input> GetInput();
            std::sr1::shared_ptr<Environment> GetEnvironment();
            std::sr1::shared_ptr<Resources> GetResources();
    };
}

#endif

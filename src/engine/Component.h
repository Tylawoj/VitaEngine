#ifndef _VITA_COMPONENT_H_
#define _VITA_COMPONENT_H_

#include <sr1/memory>

namespace vita
{
    class Core;
    class Entity;
    class Keyboard;
    class Environment;
    class Transform;

    class Component
    {
        private:
            std::sr1::weak_ptr<Entity> m_entity;

        public:
            virtual void OnInit() {}
            virtual void OnBegin() {}
            virtual void OnTick() {}
            virtual void OnDisplay() {}
            bool IsAlive();

            std::sr1::shared_ptr<Entity> GetEntity();
            std::sr1::shared_ptr<Core> GetCore();
            std::sr1::shared_ptr<Keyboard> GetKeyboard();
            std::sr1::shared_ptr<Environment> GetEnvironment();
            std::sr1::shared_ptr<Transform> GetTransform();
    }
};

#endif

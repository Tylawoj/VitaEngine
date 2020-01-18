#include "Component.h"
#include "Exception.h"
#include <sr1/memory>
#include <memory>
#include <list>

namespace vita
{
    class Core;

    class Entity : public std::enable_shared_from_this<Entity>
    {
        friend class vita::Core;

        private:
            std::list<std::shared_ptr<Component>> m_components;
            std::sr1::weak_ptr<Core> m_core;
            std::sr1::weak_ptr<Entity> m_self;
            void CheckForDeadComponents();
        public:
            void Init();
            void Display();
            std::sr1::shared_ptr<Core> GetCore();
            void Tick();

            template <typename T, typename... A> std::sr1::shared_ptr<T> AddComponent(A... arguments)
            {
                std::sr1::shared_ptr<T> component = std::make_shared<T>(arguments...);
                component->m_entity = m_self;
                m_components.push_back(component);

                return component;
            }

            template<typename T> std::sr1::shared_ptr<T> GetComponent()
            {
                for (std::list<std::sr1::shared_ptr<Component>>::iterator componentIterator = m_components.begin(); componentIterator != m_components.end(); componentIterator++)
                {
                    std::sr1::shared_ptr<T> rtn = std::dynamic_pointer_cast<T>(*componentIterator);

                    if (rtn != NULL)
                    {
                        return rtn;
                    }

                    else
                    {
                        return nullptr;
                    }
                }
            }

//        template <typename T, typename A> std::shared_ptr<T> addComponent(A a);
//        template <typename T, typename A, typename B> std::shared_ptr<T> addComponent(A a, B b);
//        template <typename T, typename A, typename B, typename C> std::shared_ptr<T> addComponent(A a, B b, C c);
    };
}

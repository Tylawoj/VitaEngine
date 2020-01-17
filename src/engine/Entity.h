#include <sr1/memory>
#include <list>

namespace vita
{
    class Component;
    class Core;

    class Entity : public std::enable_shared_from_this<Entity>
    {
        friend class vita::Core;

        private:
            std::list<std::shared_ptr<Component>> m_components;
            std::sr1::weak_ptr<Core> m_core;
            std::sr1::weak_ptr<Entity> m_self;

        public:
            void Init();
            void Display();
            std::sr1::shared_ptr<Core> GetCore();
            void Tick();

            template <typename T, typename... A> std::sr1::shared_ptr<T> AddComponent(A... arguments)
            {
                std::sr1::shared_ptr<T> component = std::make_shared<T>();
                component->m_entity = m_self;
                m_components.push_back(component);

                component->OnInitialize(arguments...);

                return component;
            }

            template<typename T> std::sr1::shared_ptr<T> GetComponent()
            {
                for (std::list<std::sr1::shared_ptr<Component>>::iterator componentIterator = m_components.begin(); componentIterator != m_components.end(); componentIterator++)
                {

                }
                    for (auto& c : components)
                    {
                        std::shared_ptr<T> rtn1 = std::dynamic_pointer_cast<T>(c);
                        if (rtn1 != NULL)
                        {
                            return rtn1;
                        }
                    }

                    std::cout << "Does not Exist" << std::endl;

                    throw std::exception();
            }

//        template <typename T, typename A> std::shared_ptr<T> addComponent(A a);
//        template <typename T, typename A, typename B> std::shared_ptr<T> addComponent(A a, B b);
//        template <typename T, typename A, typename B, typename C> std::shared_ptr<T> addComponent(A a, B b, C c);
    }
};

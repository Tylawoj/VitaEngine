#ifndef _VITA_RESOURCE_H_
#define _VITA_RESOURCE_H_

#include <sr1/memory>
#include <string>

namespace vita
{
    class Core;

    class Resource
    {
        private:
            bool m_alive;
            std::sr1::weak_ptr<Core> m_core;
        public:
            bool IsAlive();
            void Kill();
            virtual void OnLoad(const std::string& _path);
    };
}

#endif

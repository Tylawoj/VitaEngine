#ifndef _VITA_RESOURCE_H_
#define _VITA_RESOURCE_H_

#include <rend/rend.h>
#include <sr1/memory>
#include <string>

namespace vita
{
    class Core;
    class Resources;

    class Resource
    {
        friend class vita::Resources;

        private:
            bool m_alive;
            std::sr1::weak_ptr<Core> m_core;
        public:
            std::sr1::shared_ptr<Core> GetCore();
            std::sr1::shared_ptr<rend::Context> GetContext();
            bool IsAlive();
            void Kill();
            virtual void OnLoad(const std::string& _path) {}
    };
}

#endif

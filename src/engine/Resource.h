#include <sr1/memory>
#include <string>

namespace vita
{
    class Core;

    class Resource
    {
        private:
            std::sr1::weak_ptr<Core> m_core;
        public:

            Resource();
            ~Resource();
    };
}


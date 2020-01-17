#include <sr1/memory>
#include <sr1/vector>
#include <vector>

namespace vita
{
    class Keyboard
    {
        private:
            std::sr1::vector<int> keyCodes;
        public:
            bool GetKey(int _keyCode);
            bool GetKeyDown(int _keyCode);
            bool GetKeyUp(int _keyCode);
    };
}

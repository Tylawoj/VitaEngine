#include "engine/Vita.h"

using namespace vita;

class Player : public Component
{
    private:
        std::sr1::shared_ptr<Material> m_guiMaterial;
    public:
        Player(std::sr1::shared_ptr<Material> _material);
        void OnDisplay();
};


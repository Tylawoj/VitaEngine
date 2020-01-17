#include "engine/Vita.h"
#include <memory>

using namespace vita;

int main()
{

    // Initialize our engine
    std::shared_ptr<Core> core = Core::Initialize();

    // Create a single in-game object
    std::shared_ptr<Entity> entity = core->AddEntity();

    // Add a very simple component to it
    std::shared_ptr<Screen> screen = entity->addComponent<Screen>();

    // Start the engine's main loop
    core->Run();


	return 0;
}

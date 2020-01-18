#include "engine/Vita.h"
#include <memory>

using namespace vita;

int main()
{
    // Initialize our engine
    std::string gameTitle = "Aliens from Outer Space 2";
    int screenWidth = 1280;
    int screenHeight = 960;
    int samples = 16;

    std::shared_ptr<Core> core = Core::Init(gameTitle, screenWidth, screenHeight, samples);

    // Create a single in-game object
    std::shared_ptr<Entity> entity = core->AddEntity();

    // Add a very simple component to it
    // none yet

    // Start the engine's main loop
    core->Start();
    core->Run();

	return 0;
}

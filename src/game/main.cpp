#include "engine/Vita.h"
#include <sr1/memory>

using namespace vita;

int main()
{
    // Initialize our engine
    std::string gameTitle = "Aliens from Outer Space 2";
    int screenWidth = 1280;
    int screenHeight = 960;
    int samples = 16;
    float fov = 60.0f;

    std::sr1::shared_ptr<Core> core = Core::Init(gameTitle, screenWidth, screenHeight, samples);

    if (core != NULL)
    {
        // Create a single in-game object
        std::sr1::shared_ptr<Entity> cameraEntity = core->AddEntity();
        std::sr1::shared_ptr<Camera> cameraComponent = cameraEntity->AddComponent<Camera>(fov, glm::vec3(0.0f, 0.0f, -1.0f));
        std::sr1::shared_ptr<Transform> cameraTransform = cameraEntity->AddComponent<Transform>(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f));

  //      std::sr1::shared_ptr<Shader> shader = core->AddResource<Shader>("xd");
 //       std::sr1::shared_ptr<Mesh> mesh = core->AddResource<Mesh>("model.obj");
  //      std::sr1::shared_ptr<Material> component = entity->AddComponent<Material>(mesh, shader);

        // Add a very simple component to it
        // none yet

        // Start the engine's main loop
        core->Start();
        core->Run();
    }
	return 0;
}

#include "engine/Vita.h"
#include <sr1/memory>

using namespace vita;

int main()
{
    // Initialize our engine
    std::string gameTitle = "Don't Fall";
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
        core->SetCurrentCamera(cameraComponent);
        std::sr1::shared_ptr<Transform> cameraTransform = cameraEntity->AddComponent<Transform>(glm::vec3(0.0f, 0.0f, 5.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f));

        std::sr1::shared_ptr<Shader> shader = core->AddResource<Shader>("../shared/shaders/Tex.txt");
        std::sr1::shared_ptr<Mesh> mesh = core->AddResource<Mesh>("../shared/models/curuthers.obj");
        std::sr1::shared_ptr<Texture> texture = core->AddResource<Texture>("../shared/textures/Whiskers_diffuse.png");

        std::sr1::shared_ptr<Entity> catEntity = core->AddEntity();
        std::sr1::shared_ptr<Transform> catTransform = catEntity->AddComponent<Transform>(glm::vec3(0.0f, -4.0f, -8.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
        std::sr1::shared_ptr<Material> catMaterial = catEntity->AddComponent<Material>(shader, texture);
        std::sr1::shared_ptr<MeshRenderer> catRenderer = catEntity->AddComponent<MeshRenderer>(mesh, catMaterial);
        std::sr1::shared_ptr<BoxCollider> catCollider = catEntity->AddComponent<BoxCollider>(glm::vec3(1.0f, 4.0f, 2.0f), glm::vec3(0.0f, 0.0f, 0.0f), false);

        std::sr1::shared_ptr<Sound> music = core->AddResource<Sound>("../shared/sounds/gameMusic.ogg");
        std::sr1::shared_ptr<SoundSource> catMusic = catEntity->AddComponent<SoundSource>(music, true, true);
   //     catMusic->SetToPlay(true);
  //      catMusic->SetAutoRemove(true);

        cameraComponent->SetTargetDirection(catTransform->GetGlobalPosition());
        cameraComponent->RotateTargetDirection(glm::vec3(0.0f, 0.0f, 0.0f));


        std::sr1::shared_ptr<Shader> floorShader = core->AddResource<Shader>("../shared/shaders/Tex.txt");
        std::sr1::shared_ptr<Mesh> floorMesh = core->AddResource<Mesh>("../shared/models/woodfloor.obj");
        std::sr1::shared_ptr<Texture> floorTexture = core->AddResource<Texture>("../shared/textures/woodfloor.jpg");

        std::sr1::shared_ptr<Entity> floorEntity = core->AddEntity();
        std::sr1::shared_ptr<Transform> floorTransform = floorEntity->AddComponent<Transform>(glm::vec3(0.0f, -5.0f, -8.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
        std::sr1::shared_ptr<Material> floorMaterial = floorEntity->AddComponent<Material>(floorShader, floorTexture);
        std::sr1::shared_ptr<MeshRenderer> floorRenderer = floorEntity->AddComponent<MeshRenderer>(floorMesh, floorMaterial);
        std::sr1::shared_ptr<BoxCollider> floorCollider = floorEntity->AddComponent<BoxCollider>(glm::vec3(20.0f, 0.1f, 20.0f), glm::vec3(0.0f, 0.0f, 0.0f), true);

        std::sr1::shared_ptr<Shader> skyboxShader = core->AddResource<Shader>("../shared/shaders/Tex.txt");
        std::sr1::shared_ptr<Mesh> skyboxMesh = core->AddResource<Mesh>("../shared/models/bigcube.obj");
        std::sr1::shared_ptr<Texture> skyboxTexture = core->AddResource<Texture>("../shared/textures/skybox.jpg");

        std::sr1::shared_ptr<Entity> skyboxEntity = core->AddEntity();
        std::sr1::shared_ptr<Transform> skyboxTransform = skyboxEntity->AddComponent<Transform>(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
        std::sr1::shared_ptr<Material> skyboxMaterial = skyboxEntity->AddComponent<Material>(skyboxShader, skyboxTexture);
        std::sr1::shared_ptr<MeshRenderer> skyboxRenderer = skyboxEntity->AddComponent<MeshRenderer>(skyboxMesh, skyboxMaterial);


        // Start the engine's main loop
        core->Start();
        core->Run();
    }
	return 0;
}

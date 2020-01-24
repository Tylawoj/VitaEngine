/** @file Main.cpp
 *  @brief Main function demonstrating the engine.
 */

#include "Player.h"
#include "engine/Vita.h"
#include <sr1/memory>

using namespace vita;

int main()
{
    /// Screen initialization values.
    std::string gameTitle = "VitaEngine Demo";
    int screenWidth = 1280;
    int screenHeight = 960;
    int samples = 16;
    float fov = 60.0f;

    /// Initialize the core.
    std::sr1::shared_ptr<Core> core = Core::Init(gameTitle, screenWidth, screenHeight, samples);

    /// Check if the core had any critical exceptions.
    if (core != NULL)
    {
        /// Create the camera entity with a Transform and SoundSource component.
        std::sr1::shared_ptr<Entity> cameraEntity = core->AddEntity();
        std::sr1::shared_ptr<Camera> cameraComponent = cameraEntity->AddComponent<Camera>(fov, glm::vec3(0.0f, 0.0f, -1.0f));
        std::sr1::shared_ptr<Transform> cameraTransform = cameraEntity->AddComponent<Transform>(glm::vec3(0.0f, 0.0f, 5.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
        std::sr1::shared_ptr<Sound> music = core->AddResource<Sound>("../shared/demo/sounds/gameMusic.ogg");
        std::sr1::shared_ptr<SoundSource> cameraMusic = cameraEntity->AddComponent<SoundSource>(music, true, true);

        /// Set this camera as currently used.
        core->SetCurrentCamera(cameraComponent);

        /// Load the player shader, mesh and texture.
        std::sr1::shared_ptr<Shader> playerShader = core->AddResource<Shader>("../shared/demo/shaders/Tex.txt");
        std::sr1::shared_ptr<Mesh> playerMesh = core->AddResource<Mesh>("../shared/demo/models/curuthers.obj");
        std::sr1::shared_ptr<Texture> playerTexture = core->AddResource<Texture>("../shared/demo/textures/Whiskers_diffuse.png");

        /// Create a player entity.
        std::sr1::shared_ptr<Entity> player = core->AddEntity();

        /// Load GUI shader and texture.
        std::sr1::shared_ptr<Shader> guiShader = core->AddResource<Shader>("../shared/demo/shaders/gui.txt");
        std::sr1::shared_ptr<Texture> guiTexture = core->AddResource<Texture>("../shared/demo/textures/test.png");
        std::sr1::shared_ptr<Material> guiMaterial = player->AddComponent<Material>(guiShader, guiTexture);

        /// Add a Player component to Player (which should display GUI and process movement).
        std::sr1::shared_ptr<Player> playerComponent = player->AddComponent<Player>(guiMaterial);

        /// Create the Player's Transform, Material, MeshRenderer and BoxCollider.
        std::sr1::shared_ptr<Transform> playerTransform = player->AddComponent<Transform>(glm::vec3(0.0f, -4.0f, -8.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
        std::sr1::shared_ptr<Material> playerMaterial = player->AddComponent<Material>(playerShader, playerTexture);
        std::sr1::shared_ptr<MeshRenderer> playerRenderer = player->AddComponent<MeshRenderer>(playerMesh, playerMaterial);
        std::sr1::shared_ptr<BoxCollider> playerCollider = player->AddComponent<BoxCollider>(glm::vec3(1.0f, 2.0f, 2.0f), glm::vec3(0.0f, 0.0f, 0.0f), false);

        /// Set the camera to look at the Player's position.
        cameraComponent->SetTargetDirection(playerTransform->GetGlobalPosition());

        /// Load the floor's shader, mesh and texture.
        std::sr1::shared_ptr<Shader> floorShader = core->AddResource<Shader>("../shared/demo/shaders/Tex.txt");
        std::sr1::shared_ptr<Mesh> floorMesh = core->AddResource<Mesh>("../shared/demo/models/woodfloor.obj");
        std::sr1::shared_ptr<Texture> floorTexture = core->AddResource<Texture>("../shared/demo/textures/woodfloor.jpg");

        /// Create a floor Entity with a Transform, Material, MeshRenderer and BoxCollider.
        std::sr1::shared_ptr<Entity> floorEntity = core->AddEntity();
        std::sr1::shared_ptr<Transform> floorTransform = floorEntity->AddComponent<Transform>(glm::vec3(0.0f, -5.0f, -8.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
        std::sr1::shared_ptr<Material> floorMaterial = floorEntity->AddComponent<Material>(floorShader, floorTexture);
        std::sr1::shared_ptr<MeshRenderer> floorRenderer = floorEntity->AddComponent<MeshRenderer>(floorMesh, floorMaterial);
        std::sr1::shared_ptr<BoxCollider> floorCollider = floorEntity->AddComponent<BoxCollider>(glm::vec3(10.0f, 0.1f, 10.0f), glm::vec3(0.0f, 0.0f, 0.0f), true);

        /// Load the skybox's shader, mesh and texture.
        std::sr1::shared_ptr<Shader> skyboxShader = core->AddResource<Shader>("../shared/demo/shaders/Tex.txt");
        std::sr1::shared_ptr<Mesh> skyboxMesh = core->AddResource<Mesh>("../shared/demo/models/bigcube.obj");
        std::sr1::shared_ptr<Texture> skyboxTexture = core->AddResource<Texture>("../shared/demo/textures/skybox.jpg");

        /// Create a skybox Entity with a Transform, Material and MeshRenderer.
        std::sr1::shared_ptr<Entity> skyboxEntity = core->AddEntity();
        std::sr1::shared_ptr<Transform> skyboxTransform = skyboxEntity->AddComponent<Transform>(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f));
        std::sr1::shared_ptr<Material> skyboxMaterial = skyboxEntity->AddComponent<Material>(skyboxShader, skyboxTexture);
        std::sr1::shared_ptr<MeshRenderer> skyboxRenderer = skyboxEntity->AddComponent<MeshRenderer>(skyboxMesh, skyboxMaterial);

        /// Start the engine and run it.
        core->Start();
        core->Run();
    }
	return 0;
}

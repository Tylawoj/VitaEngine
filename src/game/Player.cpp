/** @file Mesh.cpp
 *  @brief Implementation of functions for the Player class.
 */


#include "Player.h"

Player::Player(std::sr1::shared_ptr<Material> _material)
{
    m_guiMaterial = _material;
}

void Player::OnTick()
{
    std::sr1::shared_ptr<Transform> transform = GetEntity()->GetComponent<Transform>();

    glm::vec3 m_translation(0.0f);

    /// Move the Mesh depending on pressed key.
    /// W
    if (GetInput()->GetKey(39))
    {
        m_translation.z = -10.0f * GetEnvironment()->GetDeltaTime();
    }

    /// A
    if (GetInput()->GetKey(52))
    {
        m_translation.x = -10.0f * GetEnvironment()->GetDeltaTime();
    }

    /// S
    if (GetInput()->GetKey(53))
    {
        m_translation.z = 10.0f * GetEnvironment()->GetDeltaTime();
    }

    /// D
    if (GetInput()->GetKey(54))
    {
        m_translation.x = 10.0f * GetEnvironment()->GetDeltaTime();
    }

    /// LSHIFT
    if (GetInput()->GetKey(66))
    {
        m_translation.y = 10.0f * GetEnvironment()->GetDeltaTime();
    }

    /// LCTRL
    if (GetInput()->GetKey(82))
    {
        m_translation.y = -10.0f * GetEnvironment()->GetDeltaTime();
    }

    transform->Translate(m_translation);

    /// Set the camera to follow the Mesh.
    GetCurrentCamera()->SetTargetDirection(transform->GetGlobalPosition());

}

void Player::OnGUI()
{
   /// Fails to run (segmentation fault). Explanation in the function.
   // GetCore()->GetGUI()->DrawGUITexture(glm::vec2(300, 300), glm::vec2(0.1f, 0.1f), m_guiMaterial);
}

#include "Player.h"

Player::Player(std::sr1::shared_ptr<Material> _material)
{
    m_guiMaterial = _material;
}

void Player::OnDisplay()
{
    GetCore()->GetGUI()->DrawGUITexture(glm::vec2(0.0f, 0.0f), m_guiMaterial);
}

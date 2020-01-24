/** @file Player.h
 *  @brief An example user defined Component.
 */

#include "engine/Vita.h"

using namespace vita;

class Player : public Component
{
    private:
        std::sr1::shared_ptr<Material> m_guiMaterial;
    public:
        Player(std::sr1::shared_ptr<Material> _material);
        /// @brief Draws a GUI texture.
        void OnGUI();
        /// @brief Translates a mesh depending on Input.
        void OnTick();
};


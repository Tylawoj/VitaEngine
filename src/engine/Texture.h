/** @file Texture.h
 *  @brief Class for loading a texture from an image and storing a rend's Texture.
 */

#include "Resource.h"

namespace rend
{
    struct Texture;
}

namespace vita
{
    class Texture : public Resource
    {
        private:
            std::sr1::shared_ptr<rend::Texture> m_texture; ///< rend's Texture object.
        public:
            /**
             * @brief Returns the rend's Texture, used in rendering.
             * @return The rend's Texture object.
             */
            std::sr1::shared_ptr<rend::Texture> GetRendTexture();
            /**
             * @brief Loads a Sound from an image.
             * @param _path The file path to the image.
             */
            void OnLoad(const std::string& _path);
    };
}

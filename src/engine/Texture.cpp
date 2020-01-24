/** @file Texture.cpp
 *  @brief Implementation of functions for the Texture class.
 */

#include "Texture.h"
#include "Exception.h"
#define STB_IMAGE_IMPLEMENTATION ///< This define is necessary to use stb_image.
#include <stb/stb_image.h>
#include <rend/rend.h>

namespace vita
{
    std::sr1::shared_ptr<rend::Texture> Texture::GetRendTexture()
    {
        return m_texture;
    }

    void Texture::OnLoad(const std::string& _path)
    {
        /// Creates a rend's Texture.
        m_texture = GetContext()->createTexture();

        int width = 0;
        int height = 0;
        int channels = 0;

        /// Load texture data from the image file specified using STB_Image.
        unsigned char *data = stbi_load(_path.c_str(), &width, &height, &channels, 3);

        if (!data)
        {
            throw Exception("Texture: STB_Image failed to open a specified texture.");
        }

        /// Set the rend's texture size.
        m_texture->setSize(width, height);

        /** Set the colour data for each pixel
         *  in the rend's Texture object. */
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                m_texture->setPixel(x, y, rend::vec3(
                data[3 * x + 3 * width * y] / 255.0f,
                data[3 * x + 3 * width * y + 1] / 255.0f,
                data[3 * x + 3 * width * y + 2] / 255.0f));
            }
        }

        /// Free the texture data.
        stbi_image_free(data);
    }
}

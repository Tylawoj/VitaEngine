#include "Texture.h"
#include "Exception.h"
#define STB_IMAGE_IMPLEMENTATION ///< This define is necessary to use stb_image.
#include "stb_image.h"
#include <rend/rend.h>

namespace vita
{
    std::sr1::shared_ptr<rend::Texture> Texture::GetRendTexture()
    {
        return m_texture;
    }

    void Texture::OnLoad(const std::string& _path)
    {
        m_texture = GetContext()->createTexture();

        int width = 0;
        int height = 0;
        int channels = 0;

        unsigned char *data = stbi_load(_path.c_str(), &width, &height, &channels, 3);

        if (!data)
        {
            throw Exception("STB_Image failed to open a specified texture.");
        }

        m_texture->setSize(width, height);

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

        stbi_image_free(data);
    }
}

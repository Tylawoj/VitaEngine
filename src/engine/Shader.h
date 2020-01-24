/** @file Shader.h
 *  @brief Class for loading a shader from a text file and storing a rend's Shader.
 */

#include "Resource.h"

namespace rend
{
    struct Shader;
}

namespace vita
{
    class Shader : public Resource
    {
        private:
            std::sr1::shared_ptr<rend::Shader> m_shader; ///< rend's Shader object.
        public:
            /**
             * @brief Returns the rend's Shader, used in rendering.
             * @return The rend's Mesh shader.
             */
            std::sr1::shared_ptr<rend::Shader> GetRendShader();
            /**
             * @brief Loads a Shader from a text file.
             * @param _path The file path to the text file.
             */
            void OnLoad(const std::string& _path);
    };
}

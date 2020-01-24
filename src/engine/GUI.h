/** @file GUI.h
 *  @brief Class for displaying 2D images on screen.
 */

#include <glm/ext.hpp>
#include <sr1/memory>
#include <sr1/vector>

namespace vita
{
    class Core;
    class Material;

    class GUI
    {
        /** Core is set as a friend class to set itself as a weak_ptr during
         *  the construction of the GUI. */
        friend class vita::Core;

        private:
            std::sr1::weak_ptr<Core> m_core; ///< A weak_ptr to Core, used to obtain rend's Context.
            std::sr1::vector<glm::vec2> m_positions; ///< Vector used to set a_Position in shaders.
            glm::mat4 m_projection; ///< The orthographic projection matrix used in rendering.
            std::sr1::vector<glm::vec2> m_texCoords; ///< Vector used to set TexCoords in shaders.
        public:
            /**
             * @brief Draws a 2D image on screen with a specified size.
             * @param _position The position of the 2D image.
             * @param _size The size of the 2D image.
             * @param _material The material used by the 2D image (shader and texture).
             */
            void DrawGUITexture(glm::vec2 _position, glm::vec2 _size, std::sr1::shared_ptr<Material> _material);
            /**
             * @brief Draws a 2D image on screen.
             * @param _position The position of the 2D image.
             * @param _material The material used by the 2D image (shader and texture).
             */
            void DrawGUITexture(glm::vec2 _position, std::sr1::shared_ptr<Material> _material);
            /// @brief Initializes the member variables.
            void Init();
    };
}

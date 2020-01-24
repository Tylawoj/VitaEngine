/** @file GUI.cpp
 *  @brief Implementation of functions for the GUI class.
 */

#include "GUI.h"
#include "Core.h"
#include "Material.h"
#include "Screen.h"
#include <rend/rend.h>

namespace vita
{
    void GUI::DrawGUITexture(glm::vec2 _position, glm::vec2 _size, std::sr1::shared_ptr<Material> _material)
    {
        /// Ensure that the Material with its class members exists.
        if (_material != NULL)
        {
            if (_material->GetShader() != NULL && _material->GetTexture() != NULL)
            {
                std::sr1::shared_ptr<rend::Shader> rendShader = _material->GetRendShader();
                /// Create an OpenGL buffer for the positions and texture coordinates.
                std::sr1::shared_ptr<rend::Buffer> positionBuffer = m_core.lock()->GetContext()->createBuffer();
                std::sr1::shared_ptr<rend::Buffer> texCoordBuffer = m_core.lock()->GetContext()->createBuffer();

                /// Add the positions to the buffer.
                for (std::sr1::vector<glm::vec2>::iterator posIterator = m_positions.begin(); posIterator != m_positions.end(); posIterator++)
                {
                    positionBuffer->add(*posIterator);
                }

                /// Add the texture coordinates to the buffer.
                for (std::sr1::vector<glm::vec2>::iterator texCoordIterator = m_texCoords.begin(); texCoordIterator != m_texCoords.end(); texCoordIterator++)
                {
                    texCoordBuffer->add(*texCoordIterator);
                }

                /// Create an empty mesh to render the GUI.
                std::sr1::shared_ptr<rend::Mesh> rendMesh = m_core.lock()->GetContext()->createMesh();

                /// Set the positions and texture coordinates in the buffer.
                rendMesh->setBuffer("a_Position", positionBuffer);
                rendMesh->setBuffer("a_TexCoord", texCoordBuffer);

                glm::mat4 model(1.0f);

                /// Translate the model for rendering, using the positions.
                model = glm::translate(model, glm::vec3(_position.x, _position.y, 0.0f));
                /// Scale the model.
                model = glm::scale(model, glm::vec3(_size.x, _size.y, 1.0f));

                /** Set the shader to use the model and projection matrix.
                 *  Unfortunately, using setUniform("u_Model", model) gives a segmentation fault.
                 *  Further debugging required. */
                rendShader->setUniform("u_Model", model);
                rendShader->setUniform("u_Projection", m_projection);
                /// Set the 2D texture in the mesh.
                rendMesh->setTexture("u_Texture", _material->GetRendTexture());
                /// Set the mesh to render.
                rendShader->setMesh(rendMesh);
                /// Disable the depth testing to render the GUI correctly.
                rendShader->setDepthTesting(false);
                /// Render the GUI.
                rendShader->render();
                /// Enable depth testing again for other meshes.
                rendShader->setDepthTesting(true);
            }

            else
            {
                throw Exception("GUI: Material's Shader or Texture was not loaded correctly.");
            }
        }

        else if (_material == NULL)
        {
            throw Exception("GUI: Material was not loaded correctly.");
        }
    }

    void GUI::DrawGUITexture(glm::vec2 _position, std::sr1::shared_ptr<Material> _material)
    {
        /// Ensure that the Material with its class members exists.
        if (_material != NULL)
        {
            if (_material->GetShader() != NULL && _material->GetTexture() != NULL)
            {
                std::sr1::shared_ptr<rend::Shader> rendShader = _material->GetRendShader();
                /// Create an OpenGL buffer for the positions and texture coordinates.
                std::sr1::shared_ptr<rend::Buffer> positionBuffer = m_core.lock()->GetContext()->createBuffer();
                std::sr1::shared_ptr<rend::Buffer> texCoordBuffer = m_core.lock()->GetContext()->createBuffer();

                /// Add the positions to the buffer.
                for (std::sr1::vector<glm::vec2>::iterator posIterator = m_positions.begin(); posIterator != m_positions.end(); posIterator++)
                {
                    positionBuffer->add(*posIterator);
                }

                /// Add the texture coordinates to the buffer.
                for (std::sr1::vector<glm::vec2>::iterator texCoordIterator = m_texCoords.begin(); texCoordIterator != m_texCoords.end(); texCoordIterator++)
                {
                    texCoordBuffer->add(*texCoordIterator);
                }


                /// Create an arbitrary mesh to render the GUI.
                std::sr1::shared_ptr<rend::Mesh> rendMesh = m_core.lock()->GetContext()->createMesh();

                /// Set the positions and texture coordinates in the buffer.
                rendMesh->setBuffer("a_Position", positionBuffer);
                rendMesh->setBuffer("a_TexCoord", texCoordBuffer);

                glm::mat4 model(1.0f);

                /// Translate the model for rendering, using the positions.
                model = glm::translate(model, glm::vec3(_position.x, _position.y, 0.0f));
                /// Let the model use the size of the texture.
                model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));

                /** Set the shader to use the model and projection matrix.
                 *  Unfortunately, using setUniform("u_Model", model) gives a segmentation fault.
                 *  Further debugging required. */
                rendShader->setUniform("u_Model", model);
                rendShader->setUniform("u_Projection", m_projection);
                /// Set the 2D texture in the mesh.
                rendMesh->setTexture("u_Texture", _material->GetRendTexture());
                /// Set the mesh to render.
                rendShader->setMesh(rendMesh);
                /// Disable the depth testing to render the GUI correctly.
                rendShader->setDepthTesting(false);
                /// Render the GUI.
                rendShader->render();
                /// Enable depth testing again for other meshes.
                rendShader->setDepthTesting(true);
            }
        }
    }
    void GUI::Init()
    {
        /// Creates an orthographic projection matrix using the screen's dimensions.
        m_projection = glm::ortho(0.0f, (float)m_core.lock()->GetScreen()->GetWidth(), (float)m_core.lock()->GetScreen()->GetHeight(), 0.0f, -1.0f, 1.0f);

        /// Sets the 2D rendering positions.
        m_positions = { glm::vec2(0.0f, 1.0f),
                        glm::vec2(1.0f, 0.0f),
                        glm::vec2(0.0f, 0.0f),
                        glm::vec2(0.0f, 1.0f),
                        glm::vec2(1.0f, 1.0f),
                        glm::vec2(1.0f, 0.0f) };


        /// Sets the 2D rendering texture coordinates.
        m_texCoords = { glm::vec2(0.0f, 1.0f),
                        glm::vec2(1.0f, 0.0f),
                        glm::vec2(0.0f, 0.0f),
                        glm::vec2(0.0f, 1.0f),
                        glm::vec2(1.0f, 1.0f),
                        glm::vec2(1.0f, 0.0f) };
    }
}

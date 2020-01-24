/** @file Shader.cpp
 *  @brief Implementation of functions for the Shader class.
 */

#include "Shader.h"
#include "Exception.h"
#include <rend/rend.h>
#include <fstream>

namespace vita
{
    std::sr1::shared_ptr<rend::Shader> Shader::GetRendShader()
    {
        return m_shader;
    }

    void Shader::OnLoad(const std::string& _path)
    {
        /// Creates a rend's Shader.
        m_shader = GetContext()->createShader();

        /// Open the file from the specified path.
        std::ifstream shaderFile(_path.c_str());

        if (!shaderFile.is_open())
        {
            throw Exception("Shader: std::ifstream failed to open a shader file.");
        }

        std::string shaderSource;

        /// Store the file's content into a string.
        while(!shaderFile.eof())
        {
          std::string line;
          std::getline(shaderFile, line);
          shaderSource += line + "\n";
        }

        shaderFile.close();

        /// Parse the string with the shader to rend.
        m_shader->parse(shaderSource);
    }
}

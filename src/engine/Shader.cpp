#include "Shader.h"
#include "Exception.h"
#include <fstream>

namespace vita
{
    void Shader::OnLoad(const std::string& _path)
    {
        m_shader = GetContext()->createShader();

        std::ifstream shaderFile(_path.c_str());

        if (!shaderFile.is_open())
        {
            throw Exception("std::ifstream failed to open a shader file.");
        }

        std::string shaderSource;

        while(!shaderFile.eof())
        {
          std::string line;
          std::getline(shaderFile, line);
          shaderSource += line + "\n";
        }

        shaderFile.close();

        m_shader->parse(shaderSource);
    }
}
#include "Mesh.h"
#include "Exception.h"
#include <fstream>

namespace vita
{
    void Mesh::OnLoad(const std::string &_path)
    {
        m_mesh = GetContext()->createMesh();

        std::ifstream meshFile(_path.c_str());

        if (!meshFile.is_open())
        {
            throw Exception("std::ifstream failed to open a shader file.");
        }

        std::string meshSource;

        while(!meshFile.eof())
        {
          std::string line;
          std::getline(meshFile, line);
          meshSource += line + "\n";
        }

        meshFile.close();

        m_mesh->parse(meshSource);
    }
}

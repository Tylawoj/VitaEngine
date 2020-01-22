#include "Mesh.h"
#include "Exception.h"
#include <rend/rend.h>
#include <fstream>

namespace vita
{
    std::sr1::shared_ptr<rend::Mesh> Mesh::GetRendMesh()
    {
        return m_mesh;
    }

    void Mesh::OnLoad(const std::string &_path)
    {
        m_mesh = GetContext()->createMesh();

        std::ifstream meshFile(_path.c_str());

        if (!meshFile.is_open())
        {
            throw Exception("Mesh: std::ifstream failed to open a mesh file.");
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

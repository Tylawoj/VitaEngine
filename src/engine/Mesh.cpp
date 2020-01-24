/** @file Mesh.cpp
 *  @brief Implementation of functions for the Mesh class.
 */

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
        /// Creates a rend's Mesh.
        m_mesh = GetContext()->createMesh();

        /// Open the file from the specified path.
        std::ifstream meshFile(_path.c_str());

        if (!meshFile.is_open())
        {
            throw Exception("Mesh: std::ifstream failed to open a mesh file.");
        }

        std::string meshSource;

        /// Store the file's content into a string.
        while(!meshFile.eof())
        {
          std::string line;
          std::getline(meshFile, line);
          meshSource += line + "\n";
        }

        meshFile.close();

        /// Parse the string with the mesh to rend.
        m_mesh->parse(meshSource);
    }
}

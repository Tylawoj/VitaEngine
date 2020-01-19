#include "Component.h"
#include <glm/mat4x4.hpp>

namespace vita
{
    class Camera : public Component
    {
        public:
            glm::mat4 GetProjectionMatrix();
            glm::mat4 GetViewMatrix();
    };
}


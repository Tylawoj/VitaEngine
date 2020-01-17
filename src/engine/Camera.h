#include <glm/mat4x4.hpp>

namespace vita
{
    class Camera
    {
        public:
            glm::mat4 getProjection();
            glm::mat4 getView();
            Camera();
            ~Camera();
    };
}


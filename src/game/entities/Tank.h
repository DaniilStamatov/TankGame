#include <glm/glm.hpp>
#include "../../engine/scene/Components.h"
namespace game {

class Tank {
public:
    Tank(const glm::vec3& position, int health);
    void move(float deltaX, float deltaY);
    void rotate(float angle);
    void shoot();

private:
   TransformComponent m_transform;
   int m_health;
}; 

}
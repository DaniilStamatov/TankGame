#include "Tank.h"
#include <iostream>
namespace tanks {


void Tank::move(const glm::vec2& delta)
{
    glm::vec3 newPos = Transform().position + glm::vec3(glm::vec2(delta) * GetComponent<TankComponent>().speed, 0.0f);

    float minX = 0.0f, maxX = 800.0f - Transform().scale.x;
    float minY = 0.0f, maxY = 600.0f - Transform().scale.y;

    newPos.x = glm::clamp(newPos.x, minX, maxX);
    newPos.y = glm::clamp(newPos.y, minY, maxY);

    Transform().position = newPos;
}

void Tank::rotate(float angle)
{
    // Rotation logic here
}

void Tank::shoot()
{
    // Shooting logic here
}

}
#include "Tank.h"
#include <iostream>
namespace game {


void Tank::move(const glm::vec2& delta)
{
    Transform().position.x += delta.x;
    Transform().position.y += delta.y;
    std::cout << "Tank moved to position: (" 
              << Transform().position.x << ", " 
              << Transform().position.y << ", "
              << Transform().position.z << ")\n";
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
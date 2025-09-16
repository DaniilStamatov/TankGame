#include "Tank.h"
#include <iostream>
namespace game {

Tank::Tank(const glm::vec3& position, int health) : 
    m_transform(position)
    , m_health(100) {}

void Tank::move(float deltaX, float deltaY)
{
    m_transform.position.x += deltaX;
    m_transform.position.y += deltaY;
    std::cout << "Tank moved to position: (" 
              << m_transform.position.x << ", " 
              << m_transform.position.y << ", "
              << m_transform.position.z << ")\n";
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
#include "Tank.h"
#include <iostream>
namespace tanks {
Tank::Tank(nova::Scene &scene, const glm::vec3 &pos) : GameObject(scene) 
{
    auto& transform = m_entity.GetComponent<nova::TransformComponent>();
    transform.position = pos;
    transform.scale = {100.0f, 100.0f, 1.0f};
    auto& sprite = m_entity.AddComponent<nova::SpriteRendererComponent>();
    sprite.texture = nova::Texture::Create("res/textures/tank.jpeg");

    m_entity.AddComponent<TankComponent>(100, 5.0f); 
}

void Tank::move(const glm::vec2& delta)
{
    if (glm::length(delta) < 0.01f) return;
    auto& transform = Transform();
    glm::vec2 direction = glm::normalize(delta);
    
    glm::vec3 newPos = Transform().position + glm::vec3(glm::vec2(delta) * GetComponent<TankComponent>().speed, 0.0f);
    float halfWidth = transform.scale.x * 0.5f;
    float halfHeight = transform.scale.y * 0.5f;
    
    float minX = 0.0f + halfWidth;     
    float maxX = 800.0f - halfWidth;   
    float minY = 0.0f + halfHeight;    
    float maxY = 600.0f - halfHeight;
    newPos.x = glm::clamp(newPos.x, minX, maxX);
    newPos.y = glm::clamp(newPos.y, minY, maxY);
    
    Transform().position = newPos;
     if (delta.y > 0) { 
        transform.rotation.z = 0.0f;
    }
    else if (delta.y < 0) {
        transform.rotation.z = 180.0f;
    }
    else if (delta.x > 0) { 
        transform.rotation.z = -90.0f; 
    }
    else if (delta.x < 0) { 
        transform.rotation.z = 90.0f; 
    }
}

void Tank::shoot()
{
    // Shooting logic here
}

}
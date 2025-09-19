#pragma once
#include <glm/glm.hpp>
#include "components/TankComponent.h"
#include "engine/scene/GameObject.h"
#include <iostream>
namespace tanks {

class Tank: public GameObject {
public:
    Tank(nova::Scene& scene, const glm::vec3& pos)
        : GameObject(scene) 
    {
        auto& transform = m_entity.GetComponent<nova::TransformComponent>();
        transform.position = pos;
        transform.scale = {100.0f, 100.0f, 1.0f};

        auto& sprite = m_entity.AddComponent<nova::SpriteRendererComponent>();
        sprite.texture = nova::Texture::Create("res/textures/tank.jpeg");
 
        m_entity.AddComponent<TankComponent>(100, 5.0f); 
    }
    void OnInit() override {
         
    }
    void move(const glm::vec2& delta);
    void rotate(float angle);
    void shoot();

private:
   int m_health;
}; 

}
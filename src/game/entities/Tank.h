#pragma once
#include <glm/glm.hpp>
#include "../../engine/scene/Components.h"
#include "GameObject.h"
namespace game {

class Tank: public GameObject {
public:
    Tank(engine::Scene& scene, const glm::vec3& pos)
        : GameObject(scene) 
    {
        auto& transform = m_entity.GetComponent<engine::TransformComponent>();
        transform.position = pos;
        transform.scale = {0.5f, 0.5f, 1.0f};

        auto& sprite = m_entity.AddComponent<engine::SpriteRendererComponent>();
        sprite.color = glm::vec4(0, 1, 0, 1);

       // m_entity.AddComponent<TankComponent>(100, 5.0f); // hp, speed
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
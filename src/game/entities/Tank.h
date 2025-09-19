#pragma once
#include <glm/glm.hpp>
#include "components/TankComponent.h"
#include "../../engine/scene/GameObject.h"
namespace tanks {

class Tank: public GameObject {
public:
    Tank(nova::Scene& scene, const glm::vec3& pos)
        : GameObject(scene) 
    {
        auto& transform = m_entity.GetComponent<nova::TransformComponent>();
        transform.position = pos;
        transform.scale = {50.0f, 50.0f, 1.0f};

        auto& sprite = m_entity.AddComponent<nova::SpriteRendererComponent>();
        sprite.color = glm::vec4(0, 1, 0, 1);
 
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
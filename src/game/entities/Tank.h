#pragma once
#include <glm/glm.hpp>
#include "components/TankComponent.h"
#include "engine/scene/GameObject.h"
#include <iostream>
namespace tanks {

class Tank: public GameObject {
public:
    Tank(nova::Scene& scene, const glm::vec3& pos);
    void OnInit() override {
         
    }
    void move(const glm::vec2& delta);
    void shoot();

private:
   int m_health;
}; 

}
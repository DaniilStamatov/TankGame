#pragma once
#include "components/TankComponent.h"
#include "engine/scene/GameObject.h"
#include <glm/glm.hpp>
#include <iostream>
namespace tanks {

class Tank : public GameObject {
public:
  Tank(nova::Scene &scene, const glm::vec3 &pos);
  void OnInit() override {}
  void OnUpdate(float dt) override;
  void move(const glm::vec2 &delta);
  void shoot();
  glm::vec2 GetForwardDirection() const;

private:
  float m_cooldown;
  int m_health;
};

} // namespace tanks
#include "Tank.h"
#include "engine/core/EventSystem.h"
#include "game/events/GameEvents.h"
#include "TankController.h"
#include <iostream>
namespace tanks {
Tank::Tank(nova::Scene &scene, const glm::vec3 &pos) : GameObject(scene) {
  auto &transform = m_entity.GetComponent<nova::TransformComponent>();
  transform.position = pos;
  transform.scale = {100.0f, 100.0f, 1.0f};
  
  auto &tank = m_entity.AddComponent<TankComponent>(100, 500.0f);
  tank.fireRate = 1.0f;
  tank.bulletSpeed = 800.0f;
  m_cooldown = GetComponent<TankComponent>().fireRate;
}

void Tank::SetController(std::unique_ptr<TankController> controller)
{
  m_controller = std::move(controller);
}

void Tank::OnInit() {
  auto &sprite = m_entity.AddComponent<nova::SpriteRendererComponent>();
  sprite.texture = nova::Texture::Create("res/textures/tank.jpeg");
}

void Tank::move(const glm::vec2 &delta) {
  if (glm::length(delta) < 0.01f)
    return;
  auto &transform = Transform();
  glm::vec2 direction = glm::normalize(delta);

  glm::vec3 newPos =
      Transform().position +
      glm::vec3(glm::vec2(delta) * GetComponent<TankComponent>().speed, 0.0f);
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
  } else if (delta.y < 0) {
    transform.rotation.z = 180.0f;
  } else if (delta.x > 0) {
    transform.rotation.z = -90.0f;
  } else if (delta.x < 0) {
    transform.rotation.z = 90.0f;
  }
}

void Tank::OnUpdate(float dt) {

  m_cooldown -= 0.016f;

  if (m_cooldown < 0) {
    m_cooldown = 0;
  }
  if(m_controller) {
    m_controller->Update(*this, dt);
    move(m_controller->GetInput() * dt);
  }
}
void Tank::shoot() {
  if (m_cooldown > 0)
    return;

  auto &transform = Transform();
  auto &tankComp = GetComponent<TankComponent>();

  tanks::BulletFiredEvent event{Transform().position, GetForwardDirection(),
                                tankComp.bulletSpeed, tankComp.damage,
                                m_entity};

  nova::EventSystem::Instance().Notify(event);

  m_cooldown = tankComp.fireRate;
}

glm::vec2 Tank::GetForwardDirection() const {
  const auto &t = Transform();
  switch (static_cast<int>(t.rotation.z)) {
  case 0:
    return {0.0f, 1.0f};
  case 180:
    return {0.0f, -1.0f};
  case -90:
    return {1.0f, 0.0f};
  case 90:
    return {-1.0f, 0.0f};
  default:
    return {0.0f, 1.0f};
  }
}
} // namespace tanks
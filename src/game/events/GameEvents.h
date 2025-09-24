#pragma once
#include "engine/scene/Entity.h"
#include <glm/glm.hpp>
namespace tanks {

struct BulletFiredEvent {
  glm::vec3 position;
  glm::vec2 direction;
  float speed;
  float damage;
  nova::Entity &owner;
};
} // namespace tanks
#pragma once
#include <glm/glm.hpp>
#include "engine/scene/Entity.h"
namespace tanks {


struct BulletFiredEvent {
    glm::vec3 position;
    glm::vec2 direction;
    float speed;
    float damage;
    nova::Entity& owner;
};
}
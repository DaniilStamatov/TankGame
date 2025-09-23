#pragma once
#include <glm/glm.hpp>
namespace tanks {
    struct BulletComponent {
        float damage;
        float speed;
        glm::vec3 direction;
        float lifetime;

        BulletComponent(float damage = 10.0f
            , float speed = 5.0f
            , const glm::vec3& direction = {0.0f, 1.0f, 0.0f}
            , float lifetime = 3.0f) 
            : damage(damage)
            , speed(speed)
            , direction(direction)
            , lifetime(lifetime) {
            }
    };
}

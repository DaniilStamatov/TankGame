#pragma once

#include "components/BulletComponent.h"
#include "engine/scene/GameObject.h"
#include <memory>

namespace tanks {
class Tank;

class Bullet : public GameObject {
    public:
        Bullet(nova::Scene &scene, nova::Entity& owner, const glm::vec2& direction, float damage, float speed, const glm::vec3& pos);
        void OnInit() override;
        void OnUpdate(float dt) override;
    private:
        float m_damage, m_speed;
        glm::vec3 m_pos;
        nova::Entity& m_owner;
        glm::vec2 m_dir;
};
}

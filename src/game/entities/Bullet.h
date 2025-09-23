#pragma once

#include "components/BulletComponent.h"
#include "engine/scene/GameObject.h"
#include <memory>

namespace tanks {
class Tank;

class Bullet : public GameObject {
    public:
        Bullet(nova::Scene &scene, std::shared_ptr<Tank> owner, float damage, float speed, const glm::vec3& pos);
        void OnUpdate(float dt) override;
    private:
        std::shared_ptr<Tank> m_owner;
};
}

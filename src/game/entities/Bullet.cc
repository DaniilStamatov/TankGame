#include "Bullet.h"
#include "Tank.h"
namespace tanks {
    Bullet::Bullet(nova::Scene &scene, std::shared_ptr<Tank> owner, float damage, float speed, const glm::vec3& pos)
     : GameObject(scene), m_owner(owner) {
        auto& transform = Transform();
        transform.position = pos;
        auto& bullet = m_entity.AddComponent<BulletComponent>(damage, speed);
        auto& collider = m_entity.AddComponent<nova::SphereCollider>(transform.scale);
    }
    void Bullet::OnUpdate(float dt)
    {
        Transform().position += glm::vec3(glm::vec2(dt) * GetComponent<BulletComponent>().speed, 0.0f);
    }
}
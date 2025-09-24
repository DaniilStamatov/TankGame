#include "Bullet.h"
#include "Tank.h"
namespace tanks {
    Bullet::Bullet(nova::Scene &scene,  nova::Entity& owner, const glm::vec2& dir, float damage, float speed, const glm::vec3& pos)
     : GameObject(scene), m_owner(owner), m_damage(damage), m_speed(speed), m_pos(pos), m_dir(dir) {
        
    }
    void Bullet::OnInit()
    {
        auto& transform = Transform();
        transform.position = m_pos;
        transform.scale = {10, 10, 10};
        auto& bullet = m_entity.AddComponent<BulletComponent>(m_damage, m_speed);
        auto& collider = m_entity.AddComponent<nova::SphereCollider>();
        collider.radius = Transform().scale.x;
        auto& sprite = m_entity.AddComponent<nova::SpriteRendererComponent>();
        sprite.texture = nova::Texture::Create("res/textures/tank.jpeg");
    }
    void Bullet::OnUpdate(float dt)
    {
        Transform().position += glm::vec3(m_dir * glm::vec2(dt) * GetComponent<BulletComponent>().speed, 0.0f);
    }
}
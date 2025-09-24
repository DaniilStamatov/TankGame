#pragma once
#include "engine/core/IGame.h"
#include "entities/Tank.h"
#include "engine/scene/Scene.h"
#include "engine/scene/Entity.h"
#include "engine/core/Input.h"
#include "entities/Bullet.h"
#include "engine/core/EventSystem.h"
#include "events/GameEvents.h"
#include <iostream>
namespace tanks {
class Game : public IGame {
public:
    Game(const glm::vec3& playerStartPos, int playerHealth) 
      : m_startPos(playerStartPos) {
        float width = 800.0f;
        float height = 600.0f;
        glm::mat4 viewProj = glm::ortho(0.0f, width, 0.0f, height, -1.0f, 1.0f);
        m_scene.SetViewProjection(viewProj);
    }

    void OnInit() override {
        m_scene.Init();
        CreatePlayerTank(m_startPos);
        auto& eventSystem = nova::EventSystem::Instance();
         eventSystem.Subscribe<tanks::BulletFiredEvent>(
        [this](const tanks::BulletFiredEvent& event) {
            CreateBullet(event);
        }
    );
    }
    void Update(float dt) override {
        m_tank->OnUpdate(dt);

        ProcessInput(dt);
        for(auto& bullet: m_bullets) {
            bullet->OnUpdate(dt);
        }
    }

    void ProcessInput(float dt) override {
        glm::vec2 movement(0.0f);
    
        if (nova::InputSystem::Instance().GetKey(nova::KeyCode::W)) {
            movement.y += 1.0f;
        }
        if (nova::InputSystem::Instance().GetKey(nova::KeyCode::S)) {
            movement.y -= 1.0f;
        }
        if (nova::InputSystem::Instance().GetKey(nova::KeyCode::A)) {
            movement.x -= 1.0f;
        }
        if (nova::InputSystem::Instance().GetKey(nova::KeyCode::D)) {
            movement.x += 1.0f;
        }

        if (m_tank && glm::length(movement) > 0) {
            m_tank->move(movement * dt);
        }

        if (nova::InputSystem::Instance().GetKey(nova::KeyCode::Space)) {
            if (m_tank) {
                m_tank->shoot();
            }
        }
    }

    void Render() override {
        m_scene.Render();
    }

    void CreatePlayerTank(const glm::vec3& startPos) {
        m_tank = std::make_unique<Tank>(m_scene, startPos);
    }
    void CreateBullet(const BulletFiredEvent& event) {
        auto bullet = std::make_shared<Bullet>(m_scene, event.owner, event.direction, event.damage, event.speed, event.position);
        bullet->OnInit();
        m_bullets.push_back(bullet);
    }
private:
    glm::vec3 m_startPos;
    nova::Scene m_scene;
    std::unique_ptr<Tank> m_tank;
    std::vector<std::shared_ptr<Bullet>> m_bullets;
    nova::Entity m_player;
    std::vector<std::shared_ptr<GameObject>> m_objects;
};
}
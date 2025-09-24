#pragma once
#include "Tank.h"
#include "engine/core/Input.h"
namespace tanks {
class TankController {
    public:
        virtual ~TankController() = default;
        virtual void Update(Tank& tank, float dt) = 0;
        virtual glm::vec2 GetInput() const = 0;
};

class PlayerController : public TankController {
    public:
        void Update(Tank& tank, float dt) override {
            if(nova::InputSystem::Instance().GetKey(nova::KeyCode::Space)) {
                tank.shoot();
            }
        }

        glm::vec2 GetInput() const override {
            glm::vec2 input = {0, 0};
            if(nova::InputSystem::Instance().GetKey(nova::KeyCode::W)) {
                input.y += 1.0f;
            } else if(nova::InputSystem::Instance().GetKey(nova::KeyCode::S)) {
                input.y -= 1.0f;
            } else if(nova::InputSystem::Instance().GetKey(nova::KeyCode::D)) {
                input.x += 1.0f;
            } else if(nova::InputSystem::Instance().GetKey(nova::KeyCode::A)) {
                input.x -= 1.0f;
            }

            return input;
        }
    };
}

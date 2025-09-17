#pragma once
#include "../engine/core/IGame.h"
#include "entities/Tank.h"
#include "../engine/scene/Scene.h"
#include "../engine/scene/Entity.h"
#include <iostream>
namespace game {
class Game : public IGame {
public:
    Game(const glm::vec3& playerStartPos, int playerHealth) 
      : m_startPos(playerStartPos) {
        float width = 800.0f;
        float height = 600.0f;
        glm::mat4 viewProj = glm::ortho(0.0f, width, 0.0f, height, -1.0f, 1.0f);
        m_scene.SetViewProjection(viewProj);
    }

    void OnInit(GLFWwindow* window) override {
        m_window = window;
        m_scene.Init();
        CreatePlayerTank(m_startPos);
    }
    void Update(float dt) override {
        if(m_window == nullptr) return;
        glm::vec2 input(0.0f);

        if (glfwGetKey(m_window, GLFW_KEY_W) == GLFW_PRESS)
            input.y += 1.0f;
        if (glfwGetKey(m_window, GLFW_KEY_S) == GLFW_PRESS)
            input.y -= 1.0f;
        if (glfwGetKey(m_window, GLFW_KEY_D) == GLFW_PRESS)
            input.x += 1.0f;
        if (glfwGetKey(m_window, GLFW_KEY_A) == GLFW_PRESS)
            input.x -= 1.0f;

        m_tank->move(input * dt); 
    }

    void Render() override {
        m_scene.Render();
    }

    void CreatePlayerTank(const glm::vec3& startPos) {
        m_tank = std::make_unique<Tank>(m_scene, startPos);
    }
private:
    GLFWwindow* m_window;
    glm::vec3 m_startPos;
    engine::Scene m_scene;
    std::unique_ptr<Tank> m_tank;
    engine::Entity m_player;
};
}
#pragma once
#include <GLFW/glfw3.h>
#include <glad/glad.h> 

class IGame {
    public:
        virtual ~IGame() = default;
        virtual void Update(float dt) = 0;
        virtual void Render() = 0;
        virtual void OnInit(GLFWwindow* window) = 0;
};
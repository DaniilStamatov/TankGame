#pragma once
#include <glm/vec3.hpp>
#include <memory>
#include "Shader.h"
namespace engine {
class Renderer2D {
public:
    void Init();
    void DrawQuad(const glm::mat4& viewProj, const glm::mat4& transform, const glm::vec4& color);
private:
    glm::vec4 m_clearColor;
    glm::mat4 m_viewProjection;
    
    unsigned int m_quadVAO;
    unsigned int m_quadVBO;
    unsigned int m_quadEBO;
    
    bool m_initialized;
    std::unique_ptr<Shader> m_shader;
};
}
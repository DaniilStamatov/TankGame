#include "Renderer.h"
#include <glad/glad.h>
#include <iostream>
static const float quadVertices[] = {
    -0.5f, -0.5f, 0.0f, 
     0.5f, -0.5f, 0.0f, 
     0.5f,  0.5f, 0.0f, 
    -0.5f,  0.5f, 0.0f
};

static const unsigned int quadIndices[] = {
    0, 1, 2,
    2, 3, 0
};
namespace engine {
    void Renderer2D::Init() {
         const char* vertexSrc = R"(
        #version 330 core
        layout(location = 0) in vec3 aPosition;
        
        out vec4 vColor;
        uniform vec4 u_color;
        uniform mat4 u_transform;
        
        void main() {
            vColor = u_color;
            gl_Position =  u_transform * vec4(aPosition, 1.0);
        }
    )";
    
    const char* fragmentSrc = R"(
        #version 330 core
        in vec4 vColor;
        out vec4 FragColor;
        
        void main() {
            FragColor = vColor;
        }
    )";
        m_shader = Shader::Create(vertexSrc, fragmentSrc);

            // Создаем VAO для квада
        glGenVertexArrays(1, &m_quadVAO);
        glGenBuffers(1, &m_quadVBO);
        glGenBuffers(1, &m_quadEBO);
        
        glBindVertexArray(m_quadVAO);
        
        glBindBuffer(GL_ARRAY_BUFFER, m_quadVBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), quadVertices, GL_STATIC_DRAW);
        
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_quadEBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(quadIndices), quadIndices, GL_STATIC_DRAW);
        
        // position attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        
        glBindVertexArray(0);
    }


void Renderer2D::DrawQuad(const glm::mat4& viewProj, const glm::mat4& transform, const glm::vec4& color) {
    m_shader->Bind();
    m_shader->SetVec4("u_color", color);
    m_shader->SetMat4("u_transform", transform);
    
    glBindVertexArray(m_quadVAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
    m_shader->Unbind();
}
}
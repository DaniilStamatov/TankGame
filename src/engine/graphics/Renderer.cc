#include "Renderer.h"
#include <glad/glad.h>
#include <iostream>
static float quadVertices[] = {
    // x, y, z (z всегда 0 для 2D)
    0.0f, 0.0f, 0.0f,   0.0f, 0.0f,  // 0: левый-нижний
    1.0f, 0.0f, 0.0f,   1.0f, 0.0f,  // 1: правый-нижний  
    1.0f, 1.0f, 0.0f,   1.0f, 1.0f,  // 2: правый-верхний
    0.0f, 1.0f, 0.0f,   0.0f, 1.0f   // 3: левый-верхний
};

static unsigned int quadIndices[] = {
    0, 1, 2,
    2, 3, 0
};

namespace nova { 
    void Renderer2D::Init() {
        m_shader = Shader::Create("res/shaders/quad_shader.sh");
        m_texturedShader = Shader::Create("res/shaders/quad_textured_shader.sh");

        m_vao = VertexArrayObject::Create();

        m_vbo = VertexBuffer::Create(quadVertices, sizeof(quadVertices));

        m_vbo->SetLayout({
            { ShaderDataType::Float3, "a_position" },
            { ShaderDataType::Float2, "a_texCoord" }
        });
    
        m_vao->AddVertexBuffer(m_vbo);
    
        m_ebo = IndexBuffer::Create(quadIndices, sizeof(quadIndices) / sizeof(unsigned int));
        m_vao->SetIndexBuffer(m_ebo);
    }


    void Renderer2D::DrawQuad(const glm::mat4& viewProj, const glm::mat4& transform, const glm::vec4& color) {
        m_shader->Bind();
        m_shader->SetVec4("u_color", color);
        m_shader->SetMat4("u_transform", transform);
        m_shader->SetMat4("u_viewProj", viewProj);
        m_vao->Bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        m_vao->Unbind();
        m_shader->Unbind();
    }
    void Renderer2D::DrawQuad(const glm::mat4 &viewProj, const glm::mat4 &transform, const Texture &texture, const glm::vec4 &color)
    {
        m_texturedShader->Bind();
        m_texturedShader->SetInt("u_texture", 0);

        texture.Bind(0);
        m_texturedShader->SetVec4("u_texColor", color);
        m_texturedShader->SetMat4("u_transform", transform);
        m_texturedShader->SetMat4("u_viewProj", viewProj);
        

        m_vao->Bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        m_vao->Unbind();
        m_texturedShader->Unbind();
    }
}
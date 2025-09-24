#pragma once
#include "Shader.h"
#include "Texture.h"
#include "VertexArrayObject.h"
#include <glm/vec3.hpp>
#include <memory>
namespace nova {
class Renderer2D {
public:
  void Init();
  void DrawQuad(const glm::mat4 &viewProj, const glm::mat4 &transform,
                const glm::vec4 &color);
  void DrawQuad(const glm::mat4 &viewProj, const glm::mat4 &transform,
                const Texture &texture, const glm::vec4 &color);

private:
  glm::vec4 m_clearColor;
  glm::mat4 m_viewProjection;

  unsigned int m_quadVAO;
  unsigned int m_quadVBO;
  unsigned int m_quadEBO;

  bool m_initialized;
  std::unique_ptr<Shader> m_shader;
  std::unique_ptr<Shader> m_texturedShader;
  std::shared_ptr<VertexArrayObject> m_vao;
  std::shared_ptr<VertexBuffer> m_vbo;
  std::shared_ptr<IndexBuffer> m_ebo;
};
} // namespace nova
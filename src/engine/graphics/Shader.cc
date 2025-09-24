#include "Shader.h"
#include <memory>
namespace nova {
std::unique_ptr<Shader> CreateOpenGLShader(const std::string &vertexSrc,
                                           const std::string &fragmentSrc);
std::unique_ptr<Shader> CreateOpenGLShader(const std::string &filename);
} // namespace nova

namespace nova {

std::unique_ptr<Shader> Shader::Create(const std::string &vertexSrc,
                                       const std::string &fragmentSrc) {
  // Здесь может быть проверка на тип рендерера (OpenGL, Vulkan, etc.)
  // Пока всегда создаем OpenGL шейдер
  return CreateOpenGLShader(vertexSrc, fragmentSrc);
}

std::unique_ptr<Shader> Shader::Create(const std::string &filename) {
  // Здесь может быть проверка на тип рендерера (OpenGL, Vulkan, etc.)
  // Пока всегда создаем OpenGL шейдер
  return CreateOpenGLShader(filename);
}

} // namespace nova
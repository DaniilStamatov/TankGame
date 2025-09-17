#include "Shader.h"
#include <memory>
namespace engine {
    std::unique_ptr<Shader> CreateOpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc);
}


namespace engine {

std::unique_ptr<Shader> Shader::Create(const std::string& vertexSrc, const std::string& fragmentSrc) {
    // Здесь может быть проверка на тип рендерера (OpenGL, Vulkan, etc.)
    // Пока всегда создаем OpenGL шейдер
    return CreateOpenGLShader(vertexSrc, fragmentSrc);
}
    
} 
#pragma once
#include "Components.h"
#include "engine/graphics/Renderer.h"
#include <entt.hpp>
namespace nova {
class Entity;
class Scene {
public:
  Scene();
  void Init();
  void Shutdown();
  void Render();
  Entity CreateEntity();
  void SetViewProjection(const glm::mat4 &viewProj);

private:
  Renderer2D m_renderer;
  entt::registry m_registry;
  glm::mat4 m_viewProj;
  friend class Entity;
};
} // namespace nova
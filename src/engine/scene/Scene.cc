#include "Scene.h"
#include "Entity.h"
namespace nova {
Scene::Scene()
{
}
void Scene::Init() {
    m_renderer.Init();
}

void Scene::Shutdown() {
    // Здесь можно добавить очистку ресурсов, если необходимо
}

void Scene::SetViewProjection(const glm::mat4& viewProj) {
    m_viewProj = viewProj;
}
void Scene::Render() {
    auto group = m_registry.group<TransformComponent>(entt::get<SpriteRendererComponent>);
    for (auto entity : group) {
        auto [transform, sprite] = group.get<TransformComponent, SpriteRendererComponent>(entity);
        if(!sprite.texture)
            m_renderer.DrawQuad(m_viewProj, transform.GetTransform(), sprite.color);
        else {
            m_renderer.DrawQuad(m_viewProj, transform.GetTransform(), *sprite.texture, sprite.color);
        }
    }
}

 Entity Scene::CreateEntity() {
	Entity entity = { m_registry.create(), this };
    entity.AddComponent<TransformComponent>();
    return entity;
}
}

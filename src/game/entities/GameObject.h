#pragma once
#include "../../engine/scene/Scene.h"
#include "../../engine/scene/Entity.h"
class GameObject {
public:
    GameObject(engine::Scene& scene) 
        : m_scene(scene), m_entity(scene.CreateEntity()) {}

    virtual ~GameObject() = default;

    virtual void OnInit() {}
    virtual void OnUpdate(float dt) {}
    virtual void OnRender() {}

    engine::Entity& GetEntity() { return m_entity; }
    engine::TransformComponent& Transform() {
        return m_entity.GetComponent<engine::TransformComponent>();
    }

    const engine::TransformComponent& Transform() const {
        return m_entity.GetComponent<engine::TransformComponent>();
    }
    
protected:
    engine::Scene& m_scene;
    engine::Entity m_entity;
};
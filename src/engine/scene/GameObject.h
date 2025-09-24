#pragma once
#include "Scene.h"
#include "Entity.h"
class GameObject {
public:
    GameObject(nova::Scene& scene) 
        : m_scene(scene), m_entity(scene.CreateEntity()) {}

    virtual ~GameObject() = default;

    virtual void OnInit() {}
    virtual void OnUpdate(float dt) {}
    virtual void OnRender() {}

    nova::Entity& GetEntity() { return m_entity; }
    nova::TransformComponent& Transform() {
        return m_entity.GetComponent<nova::TransformComponent>();
    }

    const nova::TransformComponent& Transform() const {
        return m_entity.GetComponent<nova::TransformComponent>();
    }

    template<typename T>
    T& GetComponent() {
        return m_entity.GetComponent<T>();
    }
    
    nova::Scene& GetScene() { return m_scene; }
protected:
    nova::Scene& m_scene;
    nova::Entity m_entity;
};
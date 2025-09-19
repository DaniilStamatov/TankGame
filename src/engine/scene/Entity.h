#pragma once
#include "entt.hpp"
#include "Scene.h"
#include "Components.h"
namespace nova {
    class Entity {
        public:
        Entity() = default;
		Entity(entt::entity handle, Scene* scene);
		Entity(const Entity& other) = default;
        template<typename T, typename... Args>
		T& AddComponent(Args&&... args)
		{
			T& component = m_scene->m_registry.emplace<T>(m_entityHandle, std::forward<Args>(args)...);
			return component;
		}

        template<typename T>
		bool HasComponent()
		{
			return m_scene->m_registry.has<T>(m_entityHandle);
		}

        template<typename T>
        T& GetComponent() {
            return m_scene->m_registry.get<T>(m_entityHandle);
        }

        template<typename T>
        const T& GetComponent() const {
            return m_scene->m_registry.get<T>(m_entityHandle);
        }

        operator entt::entity() const { return m_entityHandle; }

        private:
        entt::entity m_entityHandle{entt::null};
        Scene* m_scene;
    };
}
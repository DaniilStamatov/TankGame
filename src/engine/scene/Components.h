#pragma once
#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "engine/graphics/Texture.h"
namespace nova {

struct TransformComponent {
    glm::vec3 position;
    glm::vec3 rotation = {0.0, 0.0, 0.0};
    glm::vec3 scale = {1.0, 1.0, 1.0};

    TransformComponent() = default;
    TransformComponent(const glm::vec3& pos) : position(pos) {}
    TransformComponent(const TransformComponent& other) = default;

    glm::mat4 GetTransform() const {
        auto rot = glm::toMat4(glm::quat(rotation));
        auto trans = glm::translate(glm::mat4(1.0f), position);
        auto scl = glm::scale(glm::mat4(1.0f), scale);
        return trans * rot * scl;
    }
};

struct SpriteRendererComponent
{
	glm::vec4 color{ 1.0f, 1.0f, 1.0f, 1.0f };
    std::shared_ptr<Texture> texture;
	SpriteRendererComponent() = default;
	SpriteRendererComponent(const SpriteRendererComponent&) = default;
	SpriteRendererComponent(const glm::vec4& color)
		: color(color) {}
};
}

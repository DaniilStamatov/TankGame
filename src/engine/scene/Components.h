#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>
struct TransformComponent {
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;

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
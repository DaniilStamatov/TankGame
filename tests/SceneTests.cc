#include <gtest/gtest.h>
#include "engine/scene/Scene.h"
#include "engine/scene/Entity.h"
#include "engine/scene/Components.h"

using namespace nova;

TEST(SceneTest, CanCreateEntity) {
    Scene scene;

    Entity entity = scene.CreateEntity();

    // Проверяем, что у Entity есть TransformComponent по умолчанию
    EXPECT_TRUE(entity.HasComponent<TransformComponent>());
}

TEST(SceneTest, TransformComponentIsDefaultInitialized) {
    Scene scene;

    Entity entity = scene.CreateEntity();
    auto& transform = entity.GetComponent<TransformComponent>();

    // Проверяем дефолтные значения
    EXPECT_EQ(transform.position, glm::vec3(0.0f));
    EXPECT_EQ(transform.rotation, glm::vec3(0.0f));
    EXPECT_EQ(transform.scale, glm::vec3(1.0f));
}

TEST(SceneTest, CanAddSpriteRendererComponent) {
    Scene scene;

    Entity entity = scene.CreateEntity();
    auto& sprite = entity.AddComponent<SpriteRendererComponent>();
    sprite.color = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);

    EXPECT_TRUE(entity.HasComponent<SpriteRendererComponent>());
    EXPECT_EQ(sprite.color, glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
}

TEST(SceneTest, CanSetViewProjection) {
    Scene scene;

    glm::mat4 proj = glm::ortho(0.0f, 100.0f, 0.0f, 100.0f, -1.0f, 1.0f);
    scene.SetViewProjection(proj);

    SUCCEED();
}

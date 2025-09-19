#include <gtest/gtest.h>
#include "game/entities/Tank.h"
#include "engine/scene/Scene.h"

using namespace tanks;
using namespace nova;

TEST(TankTest, TankInitializesWithTransformAndSprite) {
    glm::vec3 startPos{50.0f, 60.0f, 0.0f};
    Scene scene;
    Tank tank(scene, startPos);

    auto& transform = tank.Transform();
    auto& sprite = tank.GetComponent<SpriteRendererComponent>();

    EXPECT_EQ(transform.position, startPos);
    EXPECT_EQ(transform.scale, glm::vec3(50.0f, 50.0f, 1.0f));
    EXPECT_EQ(sprite.color, glm::vec4(0, 1, 0, 1));
}

TEST(TankTest, TankCanMove) {
    glm::vec3 startPos{0, 0, 0};
    Scene scene;

    Tank tank(scene, startPos);

    tank.move({10.0f, 5.0f});

    auto& transform = tank.Transform();
    EXPECT_EQ(transform.position.x, 10.0f);
    EXPECT_EQ(transform.position.y, 5.0f);
}

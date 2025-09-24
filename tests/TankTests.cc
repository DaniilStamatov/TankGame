#include "engine/scene/Scene.h"
#include "game/entities/Tank.h"
#include "game/entities/TankController.h"
#include <gtest/gtest.h>
using namespace tanks;
using namespace nova;

TEST(TankTest, TankInitializesWithTransformAndSprite) {
  glm::vec3 startPos{50.0f, 60.0f, 0.0f};
  Scene scene;
  Tank tank(scene, startPos);

  auto &transform = tank.Transform();

  EXPECT_EQ(transform.position, startPos);
  EXPECT_EQ(transform.scale, glm::vec3(100.0f, 100.0f, 1.0f));
}

TEST(TankTest, TankCanMove) {
  glm::vec3 startPos{0, 0, 0};
  Scene scene;

  Tank tank(scene, startPos);

  tank.move({10.0f, 5.0f});

  auto &transform = tank.Transform();
  EXPECT_NE(transform.position.x, 0.0f);
  EXPECT_NE(transform.position.y, 0.0f);
}

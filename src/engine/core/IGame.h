#pragma once
#include <glm/glm.hpp>
class IGame {
public:
  virtual ~IGame() = default;
  virtual void Update(float dt) = 0;
  virtual void Render() = 0;
  virtual void OnInit() = 0;
  virtual void ProcessInput(float dt) = 0;
};
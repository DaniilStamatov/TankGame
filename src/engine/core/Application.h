#pragma once
#include "IGame.h"
#include "Window.h"
namespace nova {

class Application {
public:
  Application(int width, int height, const std::string &title, IGame &game);

  void Run();

private:
  float m_lastFrameTime;
  Window m_window;
  IGame &m_game;
};
} // namespace nova
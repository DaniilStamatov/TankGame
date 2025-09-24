#pragma once
#include "Input.h"
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <memory>
#include <string>
namespace nova {
class Window {
public:
  Window(int width, int height, const std::string &title);
  ~Window();

  void PollEvents();
  bool ShouldClose() const;
  void SwapBuffers();
  GLFWwindow *GetGLFWwindow() { return m_window; }

private:
  GLFWwindow *m_window;
};
} // namespace nova
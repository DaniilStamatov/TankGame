#pragma once
#include <functional>
#include <glm/glm.hpp>
#include <unordered_map>
namespace nova {

enum class KeyCode {
  W,
  A,
  S,
  D,
  Space,
  Enter,
  Escape,
  Up,
  Down,
  Left,
  Right,
};

enum class InputState { Pressed, Released, Held };

class InputSystem {
public:
  static InputSystem &Instance() {
    static InputSystem inputSystem;
    return inputSystem;
  }
  void Update();

  bool GetKey(KeyCode key, InputState state = InputState::Held) const;
  bool GetKeyDown(KeyCode key) const {
    return GetKey(key, InputState::Pressed);
  }
  bool GetKeyUp(KeyCode key) const { return GetKey(key, InputState::Released); }

  glm::vec2 GetMousePosition() const;
  bool GetMouseButton(int button) const;
  void SetKeyState(KeyCode key, bool pressed);

private:
  std::unordered_map<KeyCode, bool> m_currentKeyState;
  std::unordered_map<KeyCode, bool> m_previousKeyState;

  friend class Window; // Window будет обновлять состояния
};

} // namespace nova
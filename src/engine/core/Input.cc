#include "Input.h"
#include <iostream>
void nova::InputSystem::Update() { m_previousKeyState = m_currentKeyState; }

bool nova::InputSystem::GetKey(KeyCode key, InputState state) const {
  auto currentIt = m_currentKeyState.find(key);
  auto previousIt = m_previousKeyState.find(key);

  bool current =
      currentIt != m_currentKeyState.end() ? currentIt->second : false;
  bool previous =
      previousIt != m_previousKeyState.end() ? previousIt->second : false;

  switch (state) {
  case InputState::Held:
    return current;
  case InputState::Pressed:
    return current && !previous;
  case InputState::Released:
    return !current && previous;
  }
  return false;
}

void nova::InputSystem::SetKeyState(KeyCode key, bool pressed) {
  m_currentKeyState[key] = pressed;
}
#include "Application.h"
#include <stdexcept>
Application::Application(int width, int height, const std::string &title) : m_window(width, height, title) {
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        throw std::runtime_error("Failed to initialize GLAD");
    }

    glViewport(0, 0, width, height);
}


void Application::Run()
{
     while (!m_window.ShouldClose()) {
        // Расчёт deltaTime
        float currentFrame = static_cast<float>(glfwGetTime());
        float deltaTime = currentFrame - m_lastFrameTime;
        m_lastFrameTime = currentFrame;

        // Обновление логики
        // TODO: вызвать update() состояния игры

        // Очистка экрана
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Рендер
        // TODO: вызвать draw() состояния игры

        m_window.SwapBuffers();
        m_window.PollEvents();
    }
}

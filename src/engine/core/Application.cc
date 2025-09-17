#include "Application.h"
#include <stdexcept>
Application::Application(int width, int height, const std::string &title, IGame& game) : m_window(width, height, title), m_game(game) {
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        throw std::runtime_error("Failed to initialize GLAD");
    }
    glViewport(0, 0, width, height);
    m_game.OnInit(m_window.GetGLFWwindow());
}

void Application::Run()
{
     while (!m_window.ShouldClose()) {
        float currentFrame = static_cast<float>(glfwGetTime());
        float deltaTime = currentFrame - m_lastFrameTime;
        m_lastFrameTime = currentFrame;
        
        m_game.Update(deltaTime);

        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        m_game.Render();

        m_window.SwapBuffers();
        m_window.PollEvents();
    }
}

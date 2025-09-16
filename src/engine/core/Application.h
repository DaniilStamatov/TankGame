#pragma once
#include "Window.h"

class Application {
    public:
        Application(int width, int height, const std::string& title);

        void Run();
    private:
        float m_lastFrameTime;
        Window m_window;
};
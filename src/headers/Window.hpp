#ifndef WINDOW_H
#define WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window {

    public:
        GLFWwindow* window;

        Window(int width, int height, const char* windowname);

        void handleInput();

        int WindowClosed();

        void RenderFrame();
};

#endif
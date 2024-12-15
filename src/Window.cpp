#include <Window.hpp>
#include <stdexcept>

// OpenGL version 3.3
#define OPENGL_VERSION_MAJOR 3
#define OPENGL_VERSION_MINOR 3

const int LOWER_LEFT_X = 0;
const int LOWER_LEFT_Y = 0;

// update OpenGL view port on window resize
void WindowResize(GLFWwindow* window, int width, int height){
    glViewport(LOWER_LEFT_X, LOWER_LEFT_Y, width, height);
}

Window::Window(int width, int height,const char* windowname){

    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, OPENGL_VERSION_MAJOR);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, OPENGL_VERSION_MINOR);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow( width, height, windowname, NULL, NULL); 

    if (window == NULL){

        glfwTerminate();
        throw std::runtime_error("Window Creation Failed");

    }

    glfwMakeContextCurrent(window);

    // init GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        
        throw std::runtime_error("Glad Init Failed");

    }

    // tell OpenGL the size of the window
    glViewport(LOWER_LEFT_X, LOWER_LEFT_Y, width, height);

    // set function call when window is resized
    glfwSetFramebufferSizeCallback(window, WindowResize);

}

void Window::handleInput(){
    
    // if escape key is pressed close window
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(window, true);
    }

}

int Window::WindowClosed(){
    return glfwWindowShouldClose(window);
}

void Window::RenderFrame(){
    glfwSwapBuffers(window);
    glfwPollEvents();
}
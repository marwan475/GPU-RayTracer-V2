#include <Window.hpp>
#include <GLshader.hpp>
#include <GLviewport.hpp>
#include <cmath>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const char* WINDOW_NAME = "Test";

const char* GLVERTEXSHADER = "GLshaders/vertexshader.vs";
const char* GLFRAGMENTSHADER = "GLshaders/fragmentshader.fs";

int main(){

    Window GLwindow( WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);

    GLShader GLshaderprogram( GLVERTEXSHADER, GLFRAGMENTSHADER);

    GLviewport GLview;

    while(!GLwindow.WindowClosed()){

        GLwindow.handleInput();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        GLshaderprogram.use();
        
        GLview.RenderViewport();

        GLwindow.RenderFrame();
    }

    return 0;
}
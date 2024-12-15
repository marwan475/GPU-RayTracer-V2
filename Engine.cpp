#include <Window.hpp>
#include <GLshader.hpp>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const char* WINDOW_NAME = "Test";

int main(){

    Window GLwindow( WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);

    GLShader GLshaderprogram("GLshaders/vertexshader.vs", "GLshaders/fragmentshader.fs");

    while(!GLwindow.WindowClosed()){

        GLwindow.handleInput();

        GLwindow.RenderFrame();
    }

    return 0;
}
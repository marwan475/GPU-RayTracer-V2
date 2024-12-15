#include <Window.hpp>
#include <GLshader.hpp>
#include <GLviewport.hpp>
#include <algorithm>
#include <cmath>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const char* WINDOW_NAME = "Test";

const char* GLVERTEXSHADER = "GLshaders/vertexshader.vs";
const char* GLFRAGMENTSHADER = "GLshaders/fragmentshader.fs";

GLuint CreateTexture(float* rgbData, int width, int height) {
    GLuint texture;
    glGenTextures(1, &texture);  // Generate a texture ID
    glBindTexture(GL_TEXTURE_2D, texture);  // Bind the texture

    // Set texture parameters for wrapping and filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);  
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);  
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_FLOAT, rgbData);

    return texture;  // Return the texture ID
}

int main(){

    Window GLwindow( WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);

    GLShader GLshaderprogram( GLVERTEXSHADER, GLFRAGMENTSHADER);

    GLviewport GLview;

    

    while(!GLwindow.WindowClosed()){

        GLwindow.handleInput();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        float time = glfwGetTime();
        float val = (sin(time)/2.0) + 0.5;

        float *frame = new float[WINDOW_WIDTH*WINDOW_HEIGHT*3]();
        std::fill_n(frame, WINDOW_WIDTH*WINDOW_HEIGHT*3, val);

        GLuint texture = CreateTexture( frame, WINDOW_WIDTH, WINDOW_HEIGHT);

        glBindTexture(GL_TEXTURE_2D, texture);

        GLshaderprogram.use();
        
        GLview.RenderViewport();

        GLwindow.RenderFrame();

        glDeleteTextures(1,&texture);

        delete frame;
    }


    return 0;
}
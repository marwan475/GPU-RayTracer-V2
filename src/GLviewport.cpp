#include <GLviewport.hpp>

float vertices[] = {
    // triangle 1  // texture cords
    1.0, 1.0, 0.0, 1.0, 1.0,
    1.0, -1.0, 0.0, 1.0, 0.0,
    -1.0, 1.0, 0.0, 0.0, 1.0,
    // triangle 2
    1.0, -1.0, 0.0, 1.0, 0.0,
    -1.0, -1.0, 0.0, 0.0, 0.0, 
    -1.0, 1.0, 0.0, 0.0, 1.0
};

GLviewport::GLviewport(){

    glGenVertexArrays(1, &vertexarray); 
    glBindVertexArray(vertexarray); 

    glGenBuffers(1,&vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);

    // copy data into buffer
    // how GPU should manage the data
    // GL_STREAM_DRAW: the data is set only once and used by the GPU at most a few times.
    // GL_STATIC_DRAW: the data is set only once and used many times.
    // GL_DYNAMIC_DRAW: the data is changed a lot and used many times.
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // telling the gpu how to handle inputed data
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0); 

    glVertexAttribPointer(1 , 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);

}

void GLviewport::RenderViewport(){
    glBindVertexArray(vertexarray);
    glDrawArrays(GL_TRIANGLES, 0, 6);
}
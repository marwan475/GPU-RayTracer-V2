#ifndef GLVIEWPORT_H
#define GLVIEWPORT_H

#include <glad/glad.h>

class GLviewport {

    public:
        unsigned int vertexarray;
        unsigned int vertexbuffer;

        GLviewport();

        void RenderViewport();

};

#endif
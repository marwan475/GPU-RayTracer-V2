#ifndef GLSHADER_H
#define GLSHADER_H

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class GLShader {
    public:

        unsigned int programID;

        GLShader(const char* vertexShaderfilename, const char* fragmentShaderfilename);

        void use();

        void setBool(const std::string &name, bool value) const;
        void setInt(const std::string &name, int value) const;
        void setFloat(const std::string &name, float value) const;
};

#endif
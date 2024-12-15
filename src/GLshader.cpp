#include <GLshader.hpp>

GLShader::GLShader(const char* vertexShaderfilename, const char* fragmentShaderfilename){

    std::string vertexShadercode;
    std::string fragmentShadercode;

    std::ifstream vertexShaderfile;
    std::ifstream fragmentShaderfile;

    vertexShaderfile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fragmentShaderfile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    // read in shader code

    try {
        vertexShaderfile.open(vertexShaderfilename);
        fragmentShaderfile.open(fragmentShaderfilename);

        std::stringstream vertexShaderstream;
        std::stringstream fragmentShaderstream;

        vertexShaderstream << vertexShaderfile.rdbuf();
        fragmentShaderstream << fragmentShaderfile.rdbuf();

        vertexShaderfile.close();
        fragmentShaderfile.close();

        vertexShadercode = vertexShaderstream.str();
        fragmentShadercode = fragmentShaderstream.str();
    } catch (std::ifstream::failure e) {
        std::cout << "ERROR::SHADER::FILE_NOT_READ" << std::endl;
    }

    const char* GPUvShadercode = vertexShadercode.c_str();
    const char* GPUfShadercode = fragmentShadercode.c_str();

    // compile shaders

    unsigned int vertexShader;
    unsigned int fragmentShader;

    int success;
    char infolog[512];

    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &GPUvShadercode, NULL);
    glCompileShader(vertexShader);

    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    if (!success){
        glGetShaderInfoLog(vertexShader, 512, NULL, infolog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infolog << std::endl; 
    }

    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &GPUfShadercode, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

    if (!success){
        glGetShaderInfoLog(fragmentShader, 512, NULL, infolog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infolog << std::endl; 
    }

    // link the shader program
    programID = glCreateProgram();
    glAttachShader(programID, vertexShader);
    glAttachShader(programID, fragmentShader);
    glLinkProgram(programID);

    glGetProgramiv(programID, GL_LINK_STATUS, &success);
    if (!success){
        glGetProgramInfoLog(programID, 512, NULL, infolog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infolog << std::endl;
    }

    // clean up

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

}

void GLShader::use(){
    glUseProgram(programID);
}

void GLShader::setBool(const std::string &name, bool value) const
{         
    glUniform1i(glGetUniformLocation(programID, name.c_str()), (int)value); 
}
void GLShader::setInt(const std::string &name, int value) const
{ 
    glUniform1i(glGetUniformLocation(programID, name.c_str()), value); 
}
void GLShader::setFloat(const std::string &name, float value) const
{ 
    glUniform1f(glGetUniformLocation(programID, name.c_str()), value); 
} 
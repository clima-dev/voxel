#pragma once

#include "gfx.hpp"
#include "shader.hpp"
#include "glmi.hpp"

class Mesh {
public:
    Mesh();
    GLuint VAO;
    GLuint VBO;
    GLuint EBO;
    int id;
    glm::vec3 pos;
};

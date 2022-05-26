#pragma once

#include "gfx.hpp"
#include "shader.hpp"
#include "glmi.hpp"

struct vec3 {
    float x;
    float y;
    float z;
};

struct mesh {
    GLuint VAO;
    GLuint VBO;
    GLuint EBO;
    Shader sh;
    int id;
    glm::vec3 pos;
};

void init_mesh(mesh *m);
void render_mesh(mesh *m);

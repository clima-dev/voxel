<<<<<<< HEAD
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
    glm::vec3 pos; // This is fine. Later, you will have scale and rotation is here as well
};
=======
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
    glm::vec3 pos; // This is fine. Later, you will have scale and rotation is here as well
};
>>>>>>> f60595c4253207cfc255fa0f31b056e1bae51a24

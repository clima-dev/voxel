#pragma once

#include "gfx.hpp"
#include <vector>
#include "mesh.hpp"
#include "shader.hpp"

struct game {
    mesh* meshes;
    Shader sh;
    GLuint modelLoc;
    GLuint viewLoc;
    GLuint projLoc;
    glm::mat4 blocks_model;
    glm::mat4 view;
    glm::mat4 projection;
};

void init_world(game* g);
void render_world(game* g);
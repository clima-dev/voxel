#pragma once

#include "gfx.hpp"
#include <vector>
#include "mesh.hpp"
#include "shader.hpp"

class Game
{
public:
    Game();
    void render_game();
private:
    mesh *meshes;
    Shader sh;
    GLuint modelLoc;
    GLuint viewLoc;
    GLuint projLoc;
    glm::mat4 blocks_model;
    glm::mat4 view;
    glm::mat4 projection;
};
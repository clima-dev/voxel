<<<<<<< HEAD
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
    Mesh *meshes;
    Shader sh;
    GLuint modelLoc;
    GLuint viewLoc;
    GLuint projLoc;
    glm::vec3 model_scale; //To do later: move scale to your Mesh object. I did it this way so you can visualize what's happening
    glm::vec3 model_rotation; //To do later: move rotation to your Mesh object. I did it this way so you can visualize what's happening
    glm::mat4 view;
    glm::mat4 projection;
};
=======
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
    std::vector<Mesh> meshes;
    Shader sh;
    GLuint modelLoc;
    GLuint viewLoc;
    GLuint projLoc;
    glm::vec3 model_scale; //To do later: move scale to your Mesh object. I did it this way so you can visualize what's happening
    glm::vec3 model_rotation; //To do later: move rotation to your Mesh object. I did it this way so you can visualize what's happening
    glm::mat4 view;
    glm::mat4 projection;
};
>>>>>>> f60595c4253207cfc255fa0f31b056e1bae51a24

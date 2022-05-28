#include "renderer.hpp"
#include <iostream>

Game::Game()
: sh(Shader("res/shaders/plain.vs", "res/shaders/plain.fs"))
{
    this->sh.use();
    std::cout << "got shaderid: " << this->sh.ID << std::endl;
    this->modelLoc = this->sh.getUniformLocation("model");
    this->viewLoc = this->sh.getUniformLocation("view");
    this->projLoc = this->sh.getUniformLocation("projection");

    this->blocks_model = glm::mat4(1.0f);
    this->view = glm::mat4(1.0f);
    this->projection = glm::mat4(1.0f);

    std::cout << "gg" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout << "initialized mesh: " << i << std::endl;
        init_mesh(&this->meshes[i]);
    }
}

void Game::render_game()
{
    this->projection = glm::perspective(glm::radians(90.f), (float)1280 / (float)720, 0.1f, 1000.f);
    this->view = glm::translate(this->view, glm::vec3(0.0f, 0.0f, -3.0f));
    this->sh.use();

    glUniformMatrix4fv(this->modelLoc, 1, GL_FALSE, glm::value_ptr(this->blocks_model));
    glUniformMatrix4fv(this->viewLoc, 1, GL_FALSE, &this->view[0][0]);

    this->sh.setMat4("projection", this->projection);
    for (int i = 0; i < 10; i++)
    {
        mesh *m = &this->meshes[i];

        this->blocks_model = glm::translate(this->blocks_model, glm::vec3(i * 8.f, 0.0f, 0.0f));
        glUniformMatrix4fv(this->modelLoc, 1, GL_FALSE, glm::value_ptr(this->blocks_model));
        glBindVertexArray(m->VAO);
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    }
}
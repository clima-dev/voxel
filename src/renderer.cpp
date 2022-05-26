#include "renderer.hpp"

void init_world(game* g) {
    g->sh = Shader("res/shaders/plain.vs", "res/shaders/plain.fs");
    g->viewLoc = glGetUniformLocation(g->sh.ID, "view");
    g->modelLoc = glGetUniformLocation(g->sh.ID, "model");
    g->projLoc = glGetUniformLocation(g->sh.ID, "projection");

    for(int i = 0; i < 10; i++) {
        init_mesh(&g->meshes[i]);
    }
}

void render_world(game* g) {
    g->projection = glm::perspective(glm::radians(90.f), (float)1280 / (float)720, 0.1f, 1000.f);
    g->view = glm::translate(g->view, glm::vec3(0.0f, 0.0f, -3.0f));
    g->sh.use();

    glUniformMatrix4fv(g->modelLoc, 1, GL_FALSE, glm::value_ptr(g->blocks_model));
    glUniformMatrix4fv(g->viewLoc, 1, GL_FALSE, &g->view[0][0]);

    g->sh.setMat4("projection", g->projection);
    for(int i = 0; i < 10; i++) {
        mesh *m = &g->meshes[i];

        g->blocks_model = glm::translate(g->blocks_model, glm::vec3(i*8.f, 0.0f, 0.0f));
        glUniformMatrix4fv(g->modelLoc, 1, GL_FALSE, glm::value_ptr(g->blocks_model));
        glBindVertexArray(m->VAO);
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
    }
}
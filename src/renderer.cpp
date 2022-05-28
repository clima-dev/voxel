#include "renderer.hpp"
#include <iostream>

Game::Game()
: sh(Shader("Debug/res/shaders/plain.vs", "Debug/res/shaders/plain.fs"))
{
    sh.use();
    std::cout << "got shaderid: " << sh.ID << std::endl;
    modelLoc = sh.getUniformLocation("model");
    viewLoc = sh.getUniformLocation("view");
    projLoc = sh.getUniformLocation("projection");

    view = glm::mat4(1.0f);
    projection = glm::mat4(1.0f);
    
    //Also, always initialize your variables to something reasonable. I didn't do it for scale and rotation, try it yourself!

    std::cout << "gg" << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout << "initialized mesh: " << i << std::endl;
        meshes.push_back(Mesh());
    }
}

void Game::render_game()
{
    sh.use();
    projection = glm::perspective(glm::radians(45.f), (float)1280 / (float)720, 0.1f, 1000.f);
    glm::mat4 viewTransform = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 5.0f)); // Positive Z values = zoom out

    view = glm::inverse(viewTransform);

    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

    for (int i = 0; i < 10; i++)
    {
        meshes[i].pos = glm::vec3(i * 0.1f, 0.0f, 0.0f); // 8 might end up out of your screen, it's harder to debug. Change this value at your needs (try having y and z variation as well)
        
        glm::mat4 transform = glm::translate(glm::mat4(1.0f), meshes[i].pos) * glm::mat4(1.0f) * glm::scale(glm::mat4(1.0f), glm::vec3(0.1f, 0.1f, 0.1f)); // Assembling the model transformation matrix (It should be the job of the mesh, in reality). Also, I don't remember how I named the scale and rotation vectors, haha. Please make sure it's right
        
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(transform)); // Submiting your transform to shader
        glBindVertexArray(meshes[i].VAO);
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    }
}

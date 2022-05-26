#include "gfx.hpp"
#include "mesh.hpp"
#include "glmi.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (!glfwInit())
    {
        std::cerr << "Couldn't initialize GLFW." << '\n';
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

    GLFWwindow *window = glfwCreateWindow(1280, 720, "Voxel", NULL, NULL);
    if (!window)
    {
        std::cerr << "Couldn't create a window." << '\n';
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(0);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "Couldn't initialize GLAD." << '\n';
        return -1;
    }

    mesh *m;
    init_mesh(m);

    while (!glfwWindowShouldClose(window))
    {
        // input

        // render
        glClearColor(0.4f, 0.3f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        m->sh.use();

        glm::mat4 model         = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
        glm::mat4 view          = glm::mat4(1.0f);
        glm::mat4 projection    = glm::mat4(1.0f);
        model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        view  = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
        projection = glm::perspective(glm::radians(45.0f), (float)1280 / (float)720, 0.1f, 100.0f);

        GLuint modelLoc = glGetUniformLocation(m->sh.ID, "model");
        GLuint viewLoc = glGetUniformLocation(m->sh.ID, "view");

        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);

        m->sh.setMat4("projection", projection);

        render_mesh(m);
        // clean
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
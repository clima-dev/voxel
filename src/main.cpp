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
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        render_mesh(m);
        // clean
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
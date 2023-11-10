#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "GL/glut.h"

#include <iostream>

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;

void error_callback(int code, const char * desc)
{
    std::cerr << desc << std::endl;
}

int main(int, char**)
{
    if (!glfwInit())
    {
        return EXIT_FAILURE;
    }
    glfwSetErrorCallback(error_callback);

    GLFWwindow* window;
    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "", nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        return EXIT_FAILURE;
    }

    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D (0.0, (GLdouble) WINDOW_WIDTH, 0.0, (GLdouble) WINDOW_HEIGHT);
    glEnableClientState(GL_VERTEX_ARRAY);

     while (!glfwWindowShouldClose(window))
    {
        // glClearColor(128.0f / 255.0f, 166.0f / 255.0f, 255.0f  / 255.0f, 1);
        glClear(GL_COLOR_BUFFER_BIT); 

        glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f, 0.5f);
        glVertex2f(0.0f, 0.5f);
        glVertex2f(0.5f, -0.5f);
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    
    return EXIT_SUCCESS;
}

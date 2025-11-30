#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <cstdlib>
#include <ctime>

void drawGrid() {
    for(float i=0.9f; i>-1.0f; i=i-0.1f) {
        glColor3f(0, 0, 0);
        glBegin(GL_LINE_STRIP);
        glVertex2f(i, 1.0f);
        glVertex2f(i, -1.0f);
        glEnd();
    }
    for(float i=0.9f; i>-1.0f; i=i-0.1f) {
        glColor3f(0, 0, 0);
        glBegin(GL_LINE_STRIP);
        glVertex2f(1.0f, i);
        glVertex2f(-1.0f, i);
        glEnd();
    }
}

void drawSnakeSq(float x, float y) {
    glColor3f(1, 0, 0.05);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    glVertex2f(x+0.1, y);
    glVertex2f(x+0.1, y-0.1);
    glVertex2f(x, y-0.1);
    glEnd();
}

void drawFood(float x, float y) {
    glColor3f(0, 0, 0.5);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    glVertex2f(x+0.1, y);
    glVertex2f(x+0.1, y-0.1);
    glVertex2f(x, y-0.1);
    glEnd();
}

// void drawShape() {
//     glBegin(GL_LINE_STRIP);
//     glVertex2f(0, 1);
//     glVertex2f(0,-1);
//     glEnd();

//     glBegin(GL_LINE_STRIP);
//     glVertex2f(1, 0);
//     glVertex2f(-1,0);
//     glEnd();

//     for(float i=0.05f; i<1.0f; i+=0.04f) {
//         glColor3f(0, 0, 0);
//         glBegin(GL_LINE_STRIP);
//         glVertex2f(i, 0);
//         glVertex2f(0, 1+0.05-i);
//         glVertex2f(-i, 0);
//         glVertex2f(0, -1-0.05+i);
//         glVertex2f(i, 0);
//         glEnd();
//     }
// }

int main() {
    srand(static_cast<unsigned int>(time(NULL)));
    if (!glfwInit()) return -1;

    GLFWwindow* window = glfwCreateWindow(600, 600, "Pong!", NULL, NULL);
    if (!window) { glfwTerminate(); return -1; }

    glfwMakeContextCurrent(window);

    glfwSwapInterval(1);

    glewInit();

    float svx=0.001f;
    float x=0, y=0;
    int fx = rand() % 21 - 10;
    int fy = rand() % 21 - 10;
    // glfwSetKeyCallback(window, key_callback);
    while (!glfwWindowShouldClose(window)) {
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        drawGrid();
        drawSnakeSq(x, y);
        x+=svx;

        drawFood(fx/10, fy/10);

        if(x>=1) {
            x=-1;
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}
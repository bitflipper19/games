#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>

float yp=0.2f;
float vyp = 0.01f;
float h=0.4f;

bool close = false;
bool upPressed = false;
bool downPressed = false;

void drawPaddle(float y) {
    glColor3f(0.0f, 0.0f, 0.95f);
    float x=-1.0f;
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x+0.05, y);
    glVertex2f(x+0.05, y-h);
    glVertex2f(x, y-h);
    glEnd();
}

void drawBall(float x, float y, float radius) {
    glColor3f(1.0f, 0.0f, 0.0f);
    int segments = 100;
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < segments; i++) {
        float theta = 2.0f * M_PI * float(i) / float(segments);
        float cx = radius * cosf(theta);
        float cy = radius * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

bool detectCollision(float ypp, float x, float y, float r) {
    if(x-r<-0.95 && (y<=ypp && y>=ypp-h)) {
        return true;
    }
    return false;
}

// void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
//     if(key==GLFW_KEY_UP) yp+=vyp;
//     if(key==GLFW_KEY_DOWN) yp-=vyp;

//     if (yp > 1.0f) yp = 1.0f;
//     if (yp < -1.0f + h) yp = -1.0f + h;
// }

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if(key == GLFW_KEY_UP) {
        if(action == GLFW_PRESS) upPressed = true;
        if(action == GLFW_RELEASE) upPressed = false;
    }

    if(key == GLFW_KEY_DOWN) {
        if(action == GLFW_PRESS) downPressed = true;
        if(action == GLFW_RELEASE) downPressed = false;
    }

    if(key == GLFW_KEY_Q) {
        close = true;   
    }
}

int main() {
    if (!glfwInit()) return -1;

    GLFWwindow* window = glfwCreateWindow(600, 600, "Pong!", NULL, NULL);
    if (!window) { glfwTerminate(); return -1; }

    glfwMakeContextCurrent(window);

    glfwSwapInterval(1);

    glewInit();

    float x = 0.0f, y = 0.0f;
    float dx = -0.0045f, dy =  0.003f;
    float r = 0.07f;

    int cp=0, cn=0;
    glfwSetKeyCallback(window, key_callback);
    while (!glfwWindowShouldClose(window) && !close) {
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        drawBall(x, y, r);
        drawPaddle(yp);

        // paddle movement
        if(upPressed) yp += vyp;
        if(downPressed) yp -= vyp;
        if (yp > 1.0f) yp = 1.0f;
        if (yp < -1.0f + h) yp = -1.0f + h;
        
        // update position
        x += dx;
        y += dy;

        // collison logic
        bool hit = detectCollision(yp, x, y, r);
        if(hit) {
            dx = fabs(dx);
            cp++;
            //std::cout<< score<< std::endl;
        }
        else if(x - r < -1.0f) {
            dx = fabs(dx);
            cn++;
            //std::cout<< score<< std::endl;
        }
        if(x + r > 1.0f) dx = -fabs(dx);
        if(y + r > 1.0f || y - r < -1.0f) dy = -dy;

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    std::cout<< cp<< " "<< -cn<< std::endl;
    std::cout<< "FINAL SCORE: "<< cp-cn<< std::endl;
    return 0;
}
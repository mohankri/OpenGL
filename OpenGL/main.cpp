//
//  main.cpp
//  OpenGL
//
//  Created by Krishna Mohan on 8/21/17.
//  Copyright © 2017 Krishna Mohan. All rights reserved.
//
// http://www.glfw.org/docs/latest/quick.html

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>

#include <iostream>

using namespace std;

static void handle_callback(int error, const char *description) {
    cout << "Handle Callback" << endl;
    return;
}

static void window_callback(GLFWwindow *window, int key, int scancode, int action, int mode) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

int main(int argc, char *argv[])
{
    GLFWwindow *window;
    glfwSetErrorCallback(handle_callback);
    
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    //glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    cout << glfwGetVersionString() << endl;
    /* initialize GLFW */
    if (!glfwInit()) {
        fprintf(stderr, "ERROR: could not start GLFW3");
        return 1;
    }
    
    window = glfwCreateWindow(1024, 768, "OpenGL", NULL, NULL);
    if (!window) {
        glfwTerminate();
        cout << "Error Creating Window " << endl;
        return 1;
    }
    
    // window specific callback
    glfwSetKeyCallback(window, window_callback);
    
    glfwMakeContextCurrent(window);
    
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

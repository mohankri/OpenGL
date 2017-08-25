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
    int major, minor, revision;
    glfwSetErrorCallback(handle_callback);
    
        /* initialize GLFW */
    if (!glfwInit()) {
        fprintf(stderr, "ERROR: could not start GLFW3");
        return 1;
    }
    glfwGetVersion(&major, &minor, &revision);
    cout << major << "." << minor <<"." << revision << endl;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    cout << glfwGetVersionString() << endl;
    
    window = glfwCreateWindow(1024, 768, "OpenGL", NULL, NULL);
    if (!window) {
        glfwTerminate();
        cout << "Error Creating Window " << endl;
        return 1;
    }
    /*
     GLFW has two primary coordinates: virtual screens and windows(content) area.
     coordinates doesn't necessarily means pixel.
     */
    // make OpenGL context current
    glfwMakeContextCurrent(window);
    
    // window specific callback
    glfwSetKeyCallback(window, window_callback);
    
    glfwMakeContextCurrent(window);
    
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

#include <SDL2/SDL.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>

#include "window.h"


void AQ_graphics_window_initialize(int width, int height)
{
    /*
        Buffer clearing values
    */
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClearAccum(0.0, 0.0, 0.0, 0.0);
    glClearDepth(1);
    glClearStencil(0);


    /*
        Set drawing viewport to the width and height of the screen
    */
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);

    /*
        Switch the matrix mode to PROJECTION for matrix transformation
    */
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    /*
        https://upload.wikimedia.org/wikipedia/commons/4/41/Graphical_projection_comparison.png
    */
    glFrustum(-width, width, -height, height, -10, 10);


    /*
        Clear the screen with the color set at the top of the function (black)
        (Clear all buffers)
    */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_ACCUM_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);


    /*
        Change the matrix mode back to MODELVIEW for drawing
    */
    glMatrixMode(GL_MODELVIEW);
}


/*
    This is the window resize callback to reinitialize a coordinate system based on x, y
*/

void AQ_graphics_window_resize(int width, int height)
{
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-width, width, -height, height, -10, 10);
    glMatrixMode(GL_MODELVIEW);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_ACCUM_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

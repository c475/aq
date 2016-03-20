#include <SDL2/SDL.h>

#include "window.h"


/*
    For reference
    http://www.swiftless.com/tutorials/opengl/reshape.html
*/


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

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    /*

        https://upload.wikimedia.org/wikipedia/commons/4/41/Graphical_projection_comparison.png

        void gluPerspective(
            GLdouble fovy,
            GLdouble aspect,
            GLdouble zNear,
            GLdouble zFar
        );

        A lot like Three.js perspective camera.

    */


    gluPerspective(60, (GLfloat)width / (GLfloat)height, 1.0, 100.0);


    /*
        Clear the screen with the color set at the top of the function (black)
        (Clear all buffers)
    */

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_ACCUM_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

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
    gluPerspective(60, (GLfloat)width / (GLfloat)height, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_ACCUM_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}

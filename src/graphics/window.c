#include <OpenGL/gl.h>
#include <GLUT/glut.h>

#include "window.h"


void window_initialize(int width, int height)
{
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);

    /*
        Set the clear color to black
    */

    glClearColor(0.0, 0.0, 0.0, 0.0);

    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();

    /*
        Clear the color buffer. There are a few more as well.
    */

    glClear(GL_COLOR_BUFFER_BIT);


    /*

        https://upload.wikimedia.org/wikipedia/commons/4/41/Graphical_projection_comparison.png

        void glOrtho(
            GLdouble left,
            GLdouble right,
            GLdouble bottom,
            GLdouble top,
            GLdouble nearVal,
            GLdouble farVal
        );

        left, right: Specify the coordinates for the left and right vertical clipping planes.

        bottom, top: Specify the coordinates for the bottom and top horizontal clipping planes.

        nearVal, farVal: Specify the distances to the nearer and farther depth clipping planes.
            These values are negative if the plane is to be behind the viewer.

        nearVal and farVal are kind of like the near and far "frustrum planes".

    */

    glOrtho(0.0, (GLdouble)width, 0.0, (GLdouble)height, -1.0, 1.0);


    /*
        Clear the screen with the color set at the top of the function (black)
    */

    glClear(GL_COLOR_BUFFER_BIT);
}


/*
    This is the window resize callback to reinitialize a coordinate system based on x, y
*/

void window_resize(int width, int height)
{
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, (GLdouble)width, 0.0, (GLdouble)height, -1.0, 1.0);
}

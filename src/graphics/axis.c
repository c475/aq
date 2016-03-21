#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <SDL2/SDL.h>


void AQ_graphics_axis_draw_axis(float max)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINE_LOOP);

    /*
        x-axis RED
    */
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-max, 0.0, 0.0);
    glVertex3f(max, 0.0, 0.0);

    /*
        y-axis GREEN
    */
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0.0, -max, 0.0);
    glVertex3f(0.0, max, 0.0);

    /*
        z-axis BLUE
    */
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.0, 0.0, -max);
    glVertex3f(0.0, 0.0, max);

    glEnd();

    glFlush();
}

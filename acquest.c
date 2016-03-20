#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include <OpenGL/gl.h>
#include <GLUT/glut.h>

#include "src/system/system.h"
#include "src/system/state.h"
#include "src/system/error.h"

#include "src/environment/map.h"


int main(int argc, char *argv[])
{
    if (!al_init()) {
        die("init.");
    }

    SYSTEM *sys = init_system();

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);

    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

    Map *map = create_map();

    while (1) {

        ALLEGRO_EVENT event = get_system_event(sys->event_queue);

        printf("KEYPRESS: %d\n", event.keyboard.keycode);

        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            break;
        } else if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
            break;
        }

        al_flip_display();
        al_rest(0.05);
    }

    destroy_system(sys);
    destroy_map(map);

    return 0;
}

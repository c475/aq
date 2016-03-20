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

    ALLEGRO_KEYBOARD_STATE keyboard_state;

    SYSTEM *sys = init_system();

    printf("INITIALIZED SYSTEM!\n");

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

    Map *map = create_map();

    printf("CREATED MAP\n");

    while (!al_key_down(&keyboard_state, ALLEGRO_KEY_ESCAPE)) {

        // int event = handle_events(sys->event_queue);

        // if (event == ALLEGRO_EVENT_DISPLAY_CLOSE) {
        //     break;
        // }

        al_flip_display();
        al_rest(0.05);
    }

    destroy_system(sys);
    destroy_map(map);

    return 0;
}

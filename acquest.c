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

#include "src/graphics/window.h"

#include "src/system/system.h"


#define WINDOW_DEFAULT_WIDTH 640
#define WINDOW_DEFAULT_HEIGHT 480


int main(int argc, char *argv[])
{
    if (!al_init()) {
        die("init.");
    }

    /*
        SYSTEM *init_system(
            int width: display width,
            int height: display height
        );
    */

    SYSTEM *sys = init_system(WINDOW_DEFAULT_WIDTH, WINDOW_DEFAULT_HEIGHT);

    /*
        Probably return some sort of window object/abstraction here like SYSTEM
    */

    window_initialize(WINDOW_DEFAULT_WIDTH, WINDOW_DEFAULT_HEIGHT);

    Map *map = create_map();

    while (sys->__RUNNING__) {

        /*
            Handle any events
        */

        ALLEGRO_EVENT event = get_system_event(sys->event_queue);

        switch (event.type) {

            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                sys->__RUNNING__ = 0;
                break;

            case ALLEGRO_EVENT_KEY_DOWN:

                if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
                    sys->__RUNNING__ = 0;
                }

                break;

            case ALLEGRO_EVENT_DISPLAY_RESIZE:

                window_resize(al_get_display_width(sys->display), al_get_display_height(sys->display));

                break;

            default:
                break;
        }


        /*
            Flip back buffer then rest
        */

        al_flip_display();

        al_rest(0.05);
    }

    /*
        Clean everything up
    */

    destroy_system(sys);
    destroy_map(map);

    return 0;
}

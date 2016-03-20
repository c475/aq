#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include "system.h"
#include "error.h"


SYSTEM *init_system(int width, int height)
{

    /*
        Initialize Allegro library
    */

    if (!al_init()) {
        die("init.");
    }

    /*
        Construct the system object.
        Stores:
            1. Display object
            2. Event queue object
            3. Mouse and keyboard state objects
            4. Mouse and keyboard file descriptors
    */

    ALLEGRO_MOUSE_STATE mouse_state;
    ALLEGRO_KEYBOARD_STATE keyboard_state;

    SYSTEM *sys = calloc(1, sizeof(SYSTEM));

    if (!sys) {
        die("Could not initialize system object");
    }

    sys->display = NULL;
    sys->event_queue = NULL;
    sys->mouse_state = NULL;
    sys->keyboard_state = NULL;

    sys->display = al_create_display(width, height);

    if (!sys->display) {
        die("No display.");
    }

    sys->event_queue = al_create_event_queue();

    if (!sys->event_queue) {
        destroy_system(sys);
        die("No event_queue.");
    }

    sys->mouse_state = malloc(sizeof(mouse_state));

    if (!sys->mouse_state) {
        destroy_system(sys);
        die("Could not allocate memory for mouse_state");
    } else {
        memcpy(sys->mouse_state, &mouse_state, sizeof(mouse_state));
    }

    sys->keyboard_state = malloc(sizeof(keyboard_state));

    if (!sys->keyboard_state) {
        destroy_system(sys);
        die("Could not allocate memory for keyboard_state");
    } else {
        memcpy(sys->keyboard_state, &keyboard_state, sizeof(keyboard_state));
    }

    sys->mouse = al_install_mouse();

    if (!sys->mouse) {
        destroy_system(sys);
        die("No mouse driver.");
    }

    sys->keyboard = al_install_keyboard();

    if (!sys->keyboard) {
        destroy_system(sys);
        die("No keyboard driver.");
    }


    /*
        Register event sources.
    */

    al_register_event_source(sys->event_queue, al_get_display_event_source(sys->display));
    al_register_event_source(sys->event_queue, al_get_keyboard_event_source());

    /*
        Various add-on installation (fonts, images, etc)
    */

    al_init_primitives_addon();
    al_init_image_addon();
    // al_init_font_addon();


    /*
        Set display options
    */

    al_set_new_display_flags(ALLEGRO_WINDOWED | ALLEGRO_RESIZABLE | ALLEGRO_OPENGL);
    al_set_new_display_refresh_rate(1);


    sys->__RUNNING__ = 1;

    return sys;
}


void destroy_system(SYSTEM *sys)
{
    if (sys) {

        if (sys->mouse_state) {
            free(sys->mouse_state);
        }

        if (sys->keyboard_state) {
            free(sys->keyboard_state);
        }

        if (sys->event_queue) {
            al_destroy_event_queue(sys->event_queue);
        }

        if (sys->display) {
            al_destroy_display(sys->display);
        }

        free(sys);
    }
}

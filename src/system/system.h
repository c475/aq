#ifndef SYSTEM_INI_HEADER

#define SYSTEM_INI_HEADER

#include <allegro5/allegro.h>


typedef struct SYSTEM {

    int __RUNNING__;

    ALLEGRO_DISPLAY *display;
    ALLEGRO_EVENT_QUEUE *event_queue;
    ALLEGRO_MOUSE_STATE *mouse_state;
    ALLEGRO_KEYBOARD_STATE *keyboard_state;

    int mouse;
    int keyboard;
} SYSTEM;


SYSTEM *init_system(int width, int height);

void destroy_system(SYSTEM *sys);


#endif

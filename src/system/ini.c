#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include "error.h"


void init_essentials(void)
{
    // install primitives, whatever those are
    al_init_primitives_addon();

    // Install a mouse driver.
    int mouse = al_install_mouse();

    if (!mouse) {
        die("Couldn't install mouse driver\n");
    }

    // Install a keyboard driver. Returns true if successful.
    int keyboard = al_install_keyboard();

    if (!keyboard) {
        die("Couldn't install keyboard driver\n");
    }

    // Initializes the image addon. 
    // This registers bitmap format handlers for:
    // al_load_bitmap, al_load_bitmap_f, al_save_bitmap, al_save_bitmap_f.
    al_init_image_addon();

    // Note that if you intend to load bitmap fonts, 
    // you will need to initialise allegro_image separately 
    // (unless you are using another library to load images).
    // al_init_font_addon();

    al_set_new_display_flags(ALLEGRO_WINDOWED | ALLEGRO_RESIZABLE);
    al_set_new_display_refresh_rate(1);
}

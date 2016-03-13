#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>


#include "system/ini.h"
#include "environment/map.h"


// ALLEGRO_BITMAP *get_cursor(ALLEGRO_DISPLAY *display)
// {
//     al_hide_mouse_cursor(display);

//     ALLEGRO_BITMAP *cursor;

//     cursor = al_load_bitmap("assets/cursor.tga");

//     if (!cursor) {
//         die("Could not create the cursor!\n");
//     }

//     return cursor;
// }


// void draw_tiles(Tile *t, int viewport_width, int viewport_height, int total)
// {
//     int i = 0;

//     float mwidth = (float)viewport_width / ROW_SIZE;
//     float mheight = (float)viewport_height / ROW_SIZE;

//     ALLEGRO_COLOR gray = al_map_rgb(0xe0, 0xe0, 0xe0);
//     ALLEGRO_COLOR black = al_map_rgb(0, 0, 0);

//     for (i = 0; i < total; i++) {
//         // printf("mwidth: %f, mheight: %f\n", mwidth, mheight);
//         // printf("t->x: %d, t->y: %d, t-x+1: %d, t->y+1: %d\n", t[i].x, t[i].y, t[i].x+1, t[i].y+1);

//         t[i].xreal = t[i].x * mwidth;
//         t[i].yreal = t[i].y * mheight;

//         ALLEGRO_COLOR fill = t[i].hover ? black : gray;

//         al_draw_filled_rectangle(
//             t[i].xreal,
//             t[i].yreal,
//             (t[i].x + 1) * mwidth,
//             (t[i].y + 1) * mheight,
//             fill
//         );

//         al_draw_rectangle(
//             t[i].xreal,
//             t[i].yreal,
//             (t[i].x + 1) * mwidth,
//             (t[i].y + 1) * mheight,
//             black,
//             0
//         );
//     }
// }


// int collision(Tile *t, int mx, int my, int vw, int vh)
// {
//     printf("mx: %d, my: %d\n", mx, my);
//     printf("t->xreal: %d, t->yreal: %d\n", t->xreal, t->yreal);


//     return 
//         mx >= t->x * (vw / ROW_SIZE) && 
//         mx <= (t->x + 1) * (vw / ROW_SIZE) && 
//         my >= t->y * (vh / ROW_SIZE) && 
//         my <= (t->y + 1) * (vh / ROW_SIZE);
// }


// void tile_hover(Tile *t, int mx, int my, int viewport_height, int viewport_width, int total)
// {

//     int i = 0;

//     for (i = 0; i < total; i++) {
//         t[i].hover = collision(&t[i], mx, my, viewport_width, viewport_height);
//     }
// }



int main(int argc, char *argv[])
{
    ALLEGRO_DISPLAY *display;
    ALLEGRO_MOUSE_STATE mouse_state;
    ALLEGRO_KEYBOARD_STATE keyboard_state;
    ALLEGRO_BITMAP *cursor;

    if (!al_init()) {
        die("init");
    }

    init_essentials();

    display = al_create_display(640, 480);
    if (!display) {
        die("No display.\n");
    }


    // cursor = get_cursor(display);
    // if (!cursor) {
    //     die("No cursor.\n");
    // }

    Map *map = create_map();

    while (!al_key_down(&keyboard_state, ALLEGRO_KEY_ESCAPE)) {
        al_get_mouse_state(&mouse_state);
        al_get_keyboard_state(&keyboard_state);

        // clear to color...
        al_clear_to_color(al_map_rgb(0xff, 0xff, 0xff));

        // al_acknowledge_resize(display);

        // int w = al_get_display_width(display);
        // int h = al_get_display_height(display);

        // printf("W: %d, H: %d\n", w, h);

        // tile_hover(
        //     world->tiles,
        //     mouse_state.x,
        //     mouse_state.y,
        //     w,
        //     h,
        //     MAP_SIZE
        // );

        // draw_tiles(
        //     world->tiles,
        //     al_get_display_width(display),
        //     al_get_display_height(display),
        //     MAP_SIZE
        // );

        // // then draw that bitmap so it can overlap the rectangles
        // al_draw_bitmap(cursor, mouse_state.x, mouse_state.y, 0);

        // // Copies or updates the front and back buffers 
        // // so that what has been drawn previously on the 
        // // currently selected display becomes visible on screen.
        al_flip_display();

        al_rest(0.005);
    }

    al_destroy_display(display);
    destroy_map(map);

    return 0;
}

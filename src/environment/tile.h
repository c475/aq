#ifndef TILE_HEADER

#define TILE_HEADER

#include <stdlib.h>


typedef struct Tile {

    // normalized x and y coordinates
    int16_t x;
    int16_t y;

    int8_t building;
    int8_t unit;
    int8_t terrain;

    /*
        1: Hovered
        2: Selected
        4: "Active (is in viewport)"
        8: IDK
        16: IDK
        32: IDK
        64: IDK
        128: IDK
    */
    int8_t flags;
} Tile;


/*
    GET tile values
*/

int16_t tile_get_x(Tile *tile);

int16_t tile_get_y(Tile *tile);

int8_t tile_get_building(Tile *tile);

int8_t tile_get_unit(Tile *tile);

int8_t tile_get_terrain(Tile *tile);

int8_t tile_get_hover(Tile *tile);

int8_t tile_get_selected(Tile *tile);

int8_t tile_get_active(Tile *tile);


/*
    SET tile values
*/

void tile_set_x(Tile *tile, int16_t x);

void tile_set_y(Tile *tile, int16_t y);

void tile_set_building(Tile *tile, int8_t building);

void tile_set_hover(Tile *tile, uint8_t hover);

void tile_set_selected(Tile *tile, uint8_t selected);

void tile_set_active(Tile *tile, uint8_t active);



/*
    Create/destroy functions
*/

Tile tile_get_blank(int16_t x, int16_t y);

Tile *create_tiles(int map_size);

#endif

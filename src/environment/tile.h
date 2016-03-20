#ifndef ENVIRONMENT_TILE_HEADER

#define ENVIRONMENT_TILE_HEADER

#include <stdlib.h>


typedef struct EnvironmentTile {

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

} EnvironmentTile;


/*
    GET tile values
*/

int16_t AQ_environment_tile_get_x(EnvironmentTile *tile);

int16_t AQ_environment_tile_get_y(EnvironmentTile *tile);

int8_t AQ_environment_tile_get_building(EnvironmentTile *tile);

int8_t AQ_environment_tile_get_unit(EnvironmentTile *tile);

int8_t AQ_environment_tile_get_terrain(EnvironmentTile *tile);

int8_t AQ_environment_tile_get_hover(EnvironmentTile *tile);

int8_t AQ_environment_tile_get_selected(EnvironmentTile *tile);

int8_t AQ_environment_tile_get_active(EnvironmentTile *tile);


/*
    SET tile values
*/

void AQ_environment_tile_set_x(EnvironmentTile *tile, int16_t x);

void AQ_environment_tile_set_y(EnvironmentTile *tile, int16_t y);

void AQ_environment_tile_set_building(EnvironmentTile *tile, int8_t building);

void AQ_environment_tile_set_hover(EnvironmentTile *tile, uint8_t hover);

void AQ_environment_tile_set_selected(EnvironmentTile *tile, uint8_t selected);

void AQ_environment_tile_set_active(EnvironmentTile *tile, uint8_t active);



/*
    Create/destroy functions
*/

EnvironmentTile AQ_environment_tile_get_blank(int16_t x, int16_t y);

EnvironmentTile *AQ_environment_tile_create_tiles(int map_size);

#endif

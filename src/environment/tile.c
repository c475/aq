#include <stdlib.h>
#include <math.h>
#include "tile.h"


/*
    GET tile values
*/

int16_t tile_get_x(Tile *tile)
{
    return tile->x;
}

int16_t tile_get_y(Tile *tile)
{
    return tile->y;
}

int8_t tile_get_building(Tile *tile)
{
    return tile->building;
}

int8_t tile_get_unit(Tile *tile)
{
    return tile->unit;
}

int8_t tile_get_terrain(Tile *tile)
{
    return tile->terrain;
}


/*
    operates on tile->flags
*/

int8_t tile_get_hover(Tile *tile)
{
    return tile->flags & 1;
}

int8_t tile_get_selected(Tile *tile)
{
    return tile->flags & 2;
}

int8_t tile_get_active(Tile *tile)
{
    return tile->flags & 4;
}




/*
    SET tile values
*/

void tile_set_x(Tile *tile, int16_t x)
{
    tile->x = x;
}

void tile_set_y(Tile *tile, int16_t y)
{
    tile->y = y;
}


void tile_set_building(Tile *tile, int8_t building)
{
    tile->building = building;
}


/*
    operates on tile->flags
*/

void tile_set_hover(Tile *tile, uint8_t hover)
{
    int8_t flags = tile->flags;
    tile->flags = hover ? flags | 1 : flags & 0xFE;
}

void tile_set_selected(Tile *tile, uint8_t selected)
{
    int8_t flags = tile->flags;
    tile->flags = selected ? flags | 2 : flags & 0xFD;
}

void tile_set_active(Tile *tile, uint8_t active)
{
    int8_t flags = tile->flags;
    tile->flags = active ? flags | 4 : flags & 0xFC;
}



/*
    Create functions
*/

Tile tile_get_blank(int16_t x, int16_t y)
{
    Tile tile;
    tile.x = x;
    tile.y = y;
    tile.building = 0;
    tile.unit = 0;
    tile.terrain = 0;
    tile.flags = 0;

    return tile;
}

Tile *create_tiles(int map_size)
{
    Tile *tile_buffer = malloc(sizeof(Tile) * map_size);
    Tile *tbp = tile_buffer;

    int i = 0;

    int16_t x = 0;
    int16_t y = 0;

    int16_t row_size = sqrt(map_size);

    for (i = 0; i < map_size; i++, tbp++, x++) {

        *tbp = tile_get_blank(x, y);

        if (x + 1 == row_size) {
            x = -1;
            y++;
        }
    }

    return tile_buffer;
}

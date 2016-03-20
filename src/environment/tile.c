#include <stdlib.h>
#include <math.h>
#include "tile.h"


/*
    GET tile values
*/

int16_t AQ_environment_tile_get_x(EnvironmentTile *tile)
{
    return tile->x;
}

int16_t AQ_environment_tile_get_y(EnvironmentTile *tile)
{
    return tile->y;
}

int8_t AQ_environment_tile_get_building(EnvironmentTile *tile)
{
    return tile->building;
}

int8_t AQ_environment_tile_get_unit(EnvironmentTile *tile)
{
    return tile->unit;
}

int8_t AQ_environment_tile_get_terrain(EnvironmentTile *tile)
{
    return tile->terrain;
}


/*
    operates on tile->flags
*/

int8_t AQ_environment_tile_get_hover(EnvironmentTile *tile)
{
    return tile->flags & 1;
}

int8_t AQ_environment_tile_get_selected(EnvironmentTile *tile)
{
    return tile->flags & 2;
}

int8_t AQ_environment_tile_get_active(EnvironmentTile *tile)
{
    return tile->flags & 4;
}




/*
    SET tile values
*/

void AQ_environment_tile_set_x(EnvironmentTile *tile, int16_t x)
{
    tile->x = x;
}

void AQ_environment_tile_set_y(EnvironmentTile *tile, int16_t y)
{
    tile->y = y;
}


void AQ_environment_tile_set_building(EnvironmentTile *tile, int8_t building)
{
    tile->building = building;
}


/*
    operates on tile->flags
*/

void AQ_environment_tile_set_hover(EnvironmentTile *tile, uint8_t hover)
{
    int8_t flags = tile->flags;
    tile->flags = hover ? flags | 1 : flags & 0xFE;
}

void AQ_environment_tile_set_selected(EnvironmentTile *tile, uint8_t selected)
{
    int8_t flags = tile->flags;
    tile->flags = selected ? flags | 2 : flags & 0xFD;
}

void AQ_environment_tile_set_active(EnvironmentTile *tile, uint8_t active)
{
    int8_t flags = tile->flags;
    tile->flags = active ? flags | 4 : flags & 0xFC;
}



/*
    Create functions
*/

EnvironmentTile AQ_environment_tile_get_blank(int16_t x, int16_t y)
{
    EnvironmentTile tile;
    tile.x = x;
    tile.y = y;
    tile.building = 0;
    tile.unit = 0;
    tile.terrain = 0;
    tile.flags = 0;

    return tile;
}

EnvironmentTile *AQ_environment_tile_create_tiles(int map_size)
{
    EnvironmentTile *tile_buffer = malloc(sizeof(EnvironmentTile) * map_size);
    EnvironmentTile *tbp = tile_buffer;

    int i = 0;

    int16_t x = 0;
    int16_t y = 0;

    int16_t row_size = sqrt(map_size);

    for (i = 0; i < map_size; i++, tbp++, x++) {

        *tbp = AQ_environment_tile_get_blank(x, y);

        if (x + 1 == row_size) {
            x = -1;
            y++;
        }
    }

    return tile_buffer;
}

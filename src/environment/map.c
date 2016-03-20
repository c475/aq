#include <stdlib.h>

#include "map.h"
#include "tile.h"
#include "../system/error.h"


// pass in "level" struct eventually as a map loader
EnvironmentMap *AQ_environment_map_create(void)
{
    EnvironmentMap *map = malloc(sizeof(EnvironmentMap));

    // hard code map size for now
    map->tiles = AQ_environment_tile_create_tiles(1024);

    return map;
}


void AQ_environment_map_destroy(EnvironmentMap *map)
{
    if (map) {

        if (map->tiles) {
            free(map->tiles);
        }

        free(map);
    }
}

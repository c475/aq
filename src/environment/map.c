#include <stdlib.h>

#include "map.h"
#include "tile.h"
#include "../system/error.h"
#include "../system/config.h"


// pass in "level" struct eventually as a map loader
Map *create_map(void)
{
    Map *map = malloc(sizeof(Map));

    Config *config = get_config("maps");

    if (!config) {
        die("Unable to load config 'maps' in create_map()");
    }

    // hard code map size for now...
    map->tiles = create_tiles(1024);

    destroy_config(config);

    return map;
}


void destroy_map(Map *map)
{
    if (map) {
        if (map->tiles) {
            free(map->tiles);
        }

        free(map);
    }
}

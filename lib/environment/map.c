#include <stdlib.h>
#include "map.h"
#include "tile.h"
#include "../system/config.h"


Map *create_map(void)
{
    Map *map = malloc(sizeof(Map));

    Config *config = get_config("maps");

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

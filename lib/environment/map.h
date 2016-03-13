#ifndef ENVIRONMENT_MAP_HEADER

#define ENVIRONMENT_MAP_HEADER

#include "tile.h"

typedef struct Map {
    Tile *tiles;
} Map;


Map *create_map(Map *world);

int destroy_map(Map *world);

#endif

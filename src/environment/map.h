#ifndef ENVIRONMENT_MAP_HEADER

#define ENVIRONMENT_MAP_HEADER

#include "tile.h"

typedef struct EnvironmentMap {

    EnvironmentTile *tiles;

} EnvironmentMap;


EnvironmentMap *AQ_environment_map_create(void);

void AQ_environment_map_destroy(EnvironmentMap *world);

#endif

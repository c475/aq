#ifndef SYSTEM_CONFIG_HEADER

#define SYSTEM_CONFIG_HEADER

#include <allegro5/allegro.h>


typedef struct Config {

    // pointer to actual config object
    ALLEGRO_CONFIG *__CONFIG__;

    const char *name;

} Config;


Config *get_config(const char *config_file);

void destroy_config(Config *config);

#endif

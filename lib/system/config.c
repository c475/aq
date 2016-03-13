#include <stdlib.h>
#include <allegro5/allegro.h>
#include "config.h"


Config *get_config(const char *config_file)
{
    char buffer[256] = {'\0'};
    snprintf(buffer, sizeof(buffer), "../../config/%s.conf", config_file);

    ALLEGRO_CONFIG *al_conf = al_load_config_file(buffer);

    if (!al_conf) {
        return NULL;
    }

    Config *config = malloc(sizeof(Config));

    if (!config) {
        return NULL;
    }

    config->name = config_file;
    config->__CONFIG__ = al_conf;

    return config;
}


void destroy_config(Config *config)
{
    if (config) {
        if (config->__CONFIG__) {
            al_destroy_config(config->__CONFIG__);
        }

        free(config);
    }
}

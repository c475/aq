#ifndef SYSTEM_INI_HEADER

#define SYSTEM_INI_HEADER

#include <SDL2/SDL.h>


typedef struct AQ_SYSTEM {

    int __RUNNING__;

    SDL_Window *window;

    SDL_GLContext context;

    SDL_Event event;

} AQ_SYSTEM;


AQ_SYSTEM *AQ_system_init(int width, int height);

void AQ_system_destroy(AQ_SYSTEM *sys);


#endif

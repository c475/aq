#include <stdlib.h>
#include <SDL2/SDL.h>

#include "system.h"
#include "error.h"


AQ_SYSTEM *AQ_system_init(int width, int height)
{
    if (atexit(SDL_Quit)) {
        AQ_system_error_die("Could not set SDL_Quit exit function");
    }

    if(SDL_Init(SDL_INIT_VIDEO) != 0) {
        AQ_system_error_die("Unable to initialize SDL");
    }

    AQ_SYSTEM *sys = calloc(1, sizeof(AQ_SYSTEM));

    if (!sys) {
        AQ_system_error_die("Could not initialize system object");
    }

    sys->window = NULL;
    sys->context = NULL;

    /*
        Create the window
    */

    sys->window = SDL_CreateWindow("AQ", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_OPENGL);

    if (!sys->window) {
        AQ_system_destroy(sys);
        AQ_system_error_die("No window.");
    }

    /*
        Create an OpenGL rendering context so we can use OpenGL
    */

    sys->context = SDL_GL_CreateContext(sys->window);

    if (!sys->context) {
        AQ_system_destroy(sys);
        AQ_system_error_die("Failed to create OpenGL context on window");
    }

    SDL_Event event;

    sys->event = event;

    sys->__RUNNING__ = true;

    return sys;
}


void AQ_system_destroy(AQ_SYSTEM *sys)
{
    if (sys) {

        if (sys->window) {
            SDL_DestroyWindow(sys->window);
        }

        free(sys);
    }
}

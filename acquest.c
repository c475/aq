#include <stdlib.h>
#include <SDL2/SDL.h>

#include "src/system/system.h"
#include "src/system/state.h"
#include "src/system/error.h"
#include "src/system/system.h"
#include "src/environment/map.h"
#include "src/graphics/window.h"

#define WINDOW_DEFAULT_WIDTH 640
#define WINDOW_DEFAULT_HEIGHT 480


int main(int argc, char *argv[])
{
    /*
        SYSTEM *init_system(
            int width: display width,
            int height: display height
        );
    */
    SYSTEM *sys = AQ_system_init(WINDOW_DEFAULT_WIDTH, WINDOW_DEFAULT_HEIGHT);

    /*
        Probably return some sort of window object/abstraction here like SYSTEM
    */
    AQ_graphics_window_initialize(WINDOW_DEFAULT_WIDTH, WINDOW_DEFAULT_HEIGHT);

    Map *map = AQ_environment_map_create();

    while (sys->__RUNNING__) {

        /*
            Handle any events
        */
        int event = AQ_system_state_event(sys->event);

        if (event) {
            printf("there was some sort of event...\n");
        }


        /*
            Flip back buffer
        */
        SDL_GL_SwapWindow(sys->window);
    }

    /*
        Clean everything up
    */
    AQ_system_destroy(sys);
    AQ_environment_map_destroy(map);

    return 0;
}

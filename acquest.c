#include <stdlib.h>
#include <SDL2/SDL.h>

#include "src/system/system.h"
#include "src/system/state.h"
#include "src/system/error.h"
#include "src/system/system.h"
#include "src/environment/map.h"
#include "src/graphics/window.h"
#include "src/graphics/axis.h"

#define WINDOW_DEFAULT_WIDTH 640
#define WINDOW_DEFAULT_HEIGHT 480


int main(int argc, char *argv[])
{
    /*
        AQ_SYSTEM *init_system(
            int width: display width,
            int height: display height
        );
    */
    AQ_SYSTEM *sys = AQ_system_init(WINDOW_DEFAULT_WIDTH, WINDOW_DEFAULT_HEIGHT);

    /*
        Probably return some sort of window object/abstraction here like AQ_SYSTEM
    */
    AQ_graphics_window_initialize(WINDOW_DEFAULT_WIDTH, WINDOW_DEFAULT_HEIGHT);

    EnvironmentMap *map = AQ_environment_map_create();

    while (sys->__RUNNING__) {

        /*
            Handle any events
        */
        int event = AQ_system_state_event(&sys->event);

        if (event) {
            
            switch (sys->event.type) {

                case SDL_QUIT:
                    sys->__RUNNING__ = 0;
                    break;

                case SDL_KEYDOWN:

                    switch (sys->event.key.keysym.sym) {

                        case SDLK_ESCAPE:
                            sys->__RUNNING__ = 0;
                            break;

                        default:
                            break;

                    }

                    break;

                default:

                    break;
            }

        }

        AQ_graphics_axis_draw_axis(100.0);

        /*
            Flip back buffer
        */
        SDL_GL_SwapWindow(sys->window);

        SDL_Delay(20);
    }

    /*
        Clean everything up
    */
    AQ_system_destroy(sys);
    AQ_environment_map_destroy(map);

    return 0;
}

#include <SDL2/SDL.h>

#include "state.h"


/*
    Returns 1 if an event is popped off the queue, 0 if no pending event
*/

int AQ_system_state_event(SDL_Event *event)
{
    return SDL_PollEvent(event);
}

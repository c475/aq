#include <allegro5/allegro.h>

#include "state.h"

#define EVENTS_TIMEOUT 0.06


ALLEGRO_EVENT get_system_event(ALLEGRO_EVENT_QUEUE *event_queue)
{
    ALLEGRO_EVENT event;
    ALLEGRO_TIMEOUT timeout;
    
    al_init_timeout(&timeout, EVENTS_TIMEOUT);

    bool returned_event = al_wait_for_event_until(event_queue, &event, &timeout);

    if (returned_event) {

        /*
            Potentially some special event processing before it is returned to game loop
        */

        switch(event.type) {

            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                break;

            default:
                break;
        }
    }

    return event;
}

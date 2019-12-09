#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"

#endif
#include <stdio.h>
#include <stdlib.h>
#include "../headers/destination_row.h"

#include "../headers/print_passenger.h"

/* function that defines the direction the passenger moves
    and changes passengers location */
void movement (transition_system *t) {
    int i = dir = 0;

    for (i = 0; i < t->length; i++) {

        /* direction; positive is right, negative is left */
        dir = (d_row(&(t->passengers[i]), t) - t->passenger[i].location) != 0 ? 
              (d_row(&(t->passengers[i]), t) - t->passenger[i].location) / abs(d_row(&(t->passengers[i]), t) - t->passenger[i].location) : 0;

        if (t->passengers[i].location > -1 && t->passengers[i].wait_time == 0 && dir != 0) {
            if (t->passengers[i].spotting->location == NULL ) {

                t->passengers[i].location += dir;
                t->passengers[i].wait_time += t->wait.t_m;

                print_but_with_silence(&(t->passengers[i]), "MOVEMENT", i);
            }
            /* if going left and person spotting is more than one 'place' ahead */
            else if (dir == -1 && t->passengers[i].spotting->location < t->passengers[i].location - 1) {

                t->passengers[i].location += dir;
                t->passengers[i].wait_time += t->wait.t_m;

                print_but_with_silence(&(t->passengers[i]), "MOVEMENT", i);
            }
            /* if going right and person spotting is more than one 'place' ahead */
            else if (dir == 1 && t->passengers[i].spotting->location > t->passengers[i].location + 1) {

                t->passengers[i].location += dir;
                t->passengers[i].wait_time += t->wait.t_m;
                
                print_but_with_silence(&(t->passengers[i]), "MOVEMENT", i);
            }
        }
    } 
}

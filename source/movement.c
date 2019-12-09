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
    int i = 0, dir = 0, P_SL;

    for (i = 0; i < t->length; i++) {
        P_SL = (t->passengers[i].spotting != NULL) ? t->passengers[i].spotting->location : -1;
        
        /* direction; positive is right, negative is left */
        dir = (d_row(&(t->passengers[i]), t) - t->passengers[i].location) != 0 ? 
              (d_row(&(t->passengers[i]), t) - t->passengers[i].location) / abs(d_row(&(t->passengers[i]), t) - t->passengers[i].location) : 0;

        if (t->passengers[i].location > -1 && t->passengers[i].wait_time == 0 && dir != 0) {
            if (t->passengers[i].spotting == NULL) {

                t->passengers[i].location += dir;
                t->passengers[i].wait_time += t->wait.t_m;

                print_but_with_silence(&(t->passengers[i]), "MOVEMENT", i);
            }
            /* if going left and person spotting is more than one 'place' ahead */
            else if (dir == -1 && P_SL < t->passengers[i].location - 1) {

                t->passengers[i].location += dir;
                t->passengers[i].wait_time += t->wait.t_m;

                print_but_with_silence(&(t->passengers[i]), "MOVEMENT", i);
            }
            /* if going right and person spotting is more than one 'place' ahead */
            else if (dir == 1 && P_SL > t->passengers[i].location + 1) {

                t->passengers[i].location += dir;
                t->passengers[i].wait_time += t->wait.t_m;
                
                print_but_with_silence(&(t->passengers[i]), "MOVEMENT", i);
            }
        }
    } 
}

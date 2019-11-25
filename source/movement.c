#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"

#endif
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* function that defines the direction the passenger moves
    and changes passengers location */
void movement (transition_system *t, int length) {
    int i = 0, 
        dir = 0;
    int P_L, P_D, P_SL;
    passenger *P_S;

    for(i = 0; i < length; i++) {
        P_L = t->passengers[i].location;
        P_D = t->passengers[i].destination;
        P_S = t->passengers[i].spotting;
        P_SL = (P_S != NULL) ? t->passengers[i].spotting->location : -1;

        dir = (floor(P_D / 6) - P_L) / abs(floor(P_D / 6) - P_L); /* direction; positive is right, negative is left */

        if (P_L > -1) {
            
            if(P_S == NULL) {
                t->passengers[i].location += dir;
            }
            /* if going left and person spotting is more than one 'place' ahead */
            else if (dir == - 1 && P_SL < P_L - 1) {
                t->passengers[i].location += dir;
            }
            /* if going right and person spotting is more than one 'place' ahead */
            else if (dir == 1 && P_SL > P_L + 1) {
                t->passengers[i].location += dir;
            }
        }
    } 
}
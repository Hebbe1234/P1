#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"

#endif
#include <stdio.h>
#include <stdlib.h>

/* function that defines the direction the passenger moves
    and changes passengers location */
void movement (transition_system *t, int length) {
    int i, dir = 0;
    int P_L = t->passengers[i].location;
    int P_D = t->passengers[i].destination;
    int P_S = t->passengers[i].spotting;
    int P_SL = t->passengers[i].spotting->location;

    for(i = 0; i < length; i++) {
        dir = (P_D - P_L) / abs(P_D - P_L); /* direction; positive is right, negative is left */

        if (P_L != -1) {
            
            if(P_S == NULL) {
                P_L += dir;
            }
            /* if going left and person spotting is more than one 'place' ahead */
            else if (dir == - 1 && P_SL < P_L - 1) {
                P_L += dir;
            }
            /* if going right and person spotting is more than one 'place' ahead */
            else if (dir == 1 && P_SL > L + 1) {
                P_L += dir;
            }
        }
    } 
}
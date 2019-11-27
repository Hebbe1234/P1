#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"

#endif
#include <stdio.h>
#include <stdlib.h>

void initialize_passenger(transition_system *t) {
    int i, 
        P_L,
        P_E = t->entrance;
    
    passenger p;

    for (i = 0; i < t->length; i++) {
        p = t->passengers[i];
        P_L = p.location;

        if (P_L == -1 && (p.spotting == NULL || ( p.spotting->location != P_E && p.spotting->location != -1 ))) {
            t->passengers[i].location = P_E;
        }    
    }  
}

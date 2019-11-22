#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"

#endif
#include <stdio.h>
#include <stdlib.h>

void initialize_passenger(passenger* passengers, aircraft plane) {
    int i, 
        P_L,
        P_E = plane.entrance;
    
    passenger p;

    for (i = 0; i < 2; i++) {
        p = passengers[i];
        P_L = p.location;
        if (P_L == -1 && (( p.spotting->location != P_E && p.spotting->location != -1 ) || p.spotting == NULL)) {
            passengers[i].location = P_E;
        }    
    }  
}

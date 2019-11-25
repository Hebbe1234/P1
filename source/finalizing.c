#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"

#endif

#ifndef FINAL
#define FINAL

#include "../headers/finalizing.h"

#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void finalising_passenger(transition_system *t) {
    int P_L, i;
    passenger p;
    int queue = 1;

    for (i = 0; i < queue; i++)
    {
        p  = t->passengers[i];
        P_L = p.location;
        if (P_L == floor(p.destination/6) && p.carry_on == 0 && p.wait_time == 0){
            t->passengers[i].finish = 1;
        }
    }
}

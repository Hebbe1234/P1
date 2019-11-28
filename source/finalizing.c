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

/* Checks if a passenger is finished by destination wait time and carry on */
void finalising_passenger(transition_system *t) {
    int P_L, i;
    passenger p;

    for (i = 0; i < t->length; i++)
    {
        p  = t->passengers[i];
        P_L = p.location;
        if (P_L == floor(p.destination/6) && p.carry_on == 0 && p.wait_time == 0 && p.interference_flag == 1){
            t->passengers[i].finish = 1;
        }
    }
}

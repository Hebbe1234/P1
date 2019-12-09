#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"

#endif

#include "../headers/rear.h"
#include "../headers/print_passenger.h"

#include <stdio.h>
#include <stdlib.h>

/* Function to initialize passenger */
void initialize_passenger(transition_system *t) {
    int i, r;
    passenger p;

    for (i = 0; i < t->length; i++) {
        p = t->passengers[i];

        if (p.location == -1 && (p.spotting == NULL || (p.spotting->location != t->entrance && p.spotting->location != -1))) {
            t->passengers[i].location = t->entrance;
            
            t->passengers[i].wait_time += t->wait.t_m;
            r = rear_function(t, i);

            if (r != -1) {
                t->passengers[i].spotting = &(t->passengers[r]);
            } else {
                t->passengers[i].spotting = NULL;
            }
            print_but_with_silence(&(t->passengers[i]), "INITIALIZE", i);
        }
    }     
}

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
    int i, r, P_L, P_E = t->entrance;

    passenger p;

    for (i = 0; i < t->length; i++) {
        p = t->passengers[i];
        P_L = p.location;

        if (P_L == -1 && (p.spotting == NULL || (p.spotting->location != P_E && p.spotting->location != -1))) {
            t->passengers[i].location = P_E;
            
            t->passengers[i].wait_time += t->wait.t_m;
            r = rear_function(t, i);

            if(r != -1){
                t->passengers[i].spotting = &(t->passengers[r]);
            } else {
                t->passengers[i].spotting = NULL;
            }
            print_but_with_silence(&(t->passengers[i]), "INITIALIZE", i);
        }
    }  
           
        
    
}

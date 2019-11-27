#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"

#endif
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Checks which passenger the last initialized passenger must look at 
 * by finding the passenger closest to the entrance. Input is index
 * of initialized passenger, output is index of passenger closest to 
 * the entrance. If no one is found, output is index = -1 */ 
int rear_function (transition_system *t, int i) {
    passenger q;
    int index = -1;

    if (t->entrance <= floor(t->passengers[i].destination / t->seats_row) 
                      && t->passengers[i].finish == 0 && t->passengers[i].location != -1) {

        q.location = (t->length / t->seats_row) - 1;

        for(i = 0; i < t->length; i++) {

            if(t->passengers[i].location >= t->entrance && t->passengers[i].location - t->entrance < q.location - t->entrance 
                                                        && t->passengers[i].location != -1 && t->passengers[i].finish == 0) {
                q = t->passengers[i];
                index = i;
            }
        }
    }

    else if (t->entrance > floor(t->passengers[i].destination / t->seats_row) 
                    && t->passengers[i].finish == 0 && t->passengers[i].location != -1) {

        q.location = 0;
        
        for(i = 0; i < t->length; i++) {

            if(t->passengers[i].location <= t->entrance && t->entrance - t->passengers[i].location < t->entrance - q.location 
                                                        && t->passengers[i].location != -1 && t->passengers[i].finish == 0) {
                q = t->passengers[i];
                index = i;
            }
        }
    }
    return index;
}

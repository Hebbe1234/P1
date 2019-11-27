#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"

#endif
#include <stdio.h>
#include <stdlib.h>

/* Checks which passenger the last initialized passenger must look at 
 * by finding the passenger closest to the entrance */
int rear_function (transition_system *t, int i) {
    passenger q;
    int index = NULL;

    if(t->entrance < floor(t->passengers[i].destination / 6) 
                      && t->passengers[i].finish == 0 && t->passengers[i].location != -1) {

        q.location = (t->length / t->seats_row) - 1;

        for(i = 0; i < t->length; i++) {

            if(t->passengers[i].location >= t->entrance && t->passengers[i].location - t->entrance < q.location - t->entrance && t->passengers[i].location != -1 && t->passengers[i].finish == 0) {
                q = t->passengers[i];
                index = i;
            }
        }
    }

    else if (t->entrance > floor(t->passengers[i].destination / 6) 
                    && t->passengers[i].finish == 0 && t->passengers[i].location != -1) {

        q.location = 0;
        

        for(i = 0; i < t->length; i++) {

            if(t->passengers[i].location <= t->entrance && t->entrance - t->passengers[i].location < t->entrance - q.location && t->passengers[i].location != -1 && t->passengers[i].finish == 0) {
                q = t->passengers[i];
                index = i;
            }
        }
    }

    return index;
}
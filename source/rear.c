#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"

#endif
#include <stdio.h>
#include <stdlib.h>

void rear_function (transition_system *t) {
    passenger q;
    int i = 0;
    int index;

    if(t->entrance < floor(t->passengers[i].destination / 6) 
                      && t->passengers[i].finish == 0 && t->passengers[i].location != -1) {

        q.location = (t->length / t->seats_row) - 1;

        for(i = 0; i < t->length; i++) {

            if(t->passengers[i].location >= t->entrance && t->passengers[i].location - t->entrance < q.location - t->entrance) {
                q = t->passengers[i];
                index = i;
            }
        }
    }

    else if (t->entrance > floor(t->passengers[i].destination / 6) 
                    && t->passengers[i].finish == 0 && t->passengers[i].location != -1) {

        q.location = 0;
        

        for(i = 0; i < t->length; i++) {

            if(t->passengers[i].location <= t->entrance && t->entrance - t->passengers[i].location < t->entrance - q.location) {
                q = t->passengers[i];
                index = i;
            }
        }
    }

    return index;
}
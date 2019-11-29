#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"

#endif
#include <stdio.h>
#include <stdlib.h>
#include <math.h>



void wait_time(transition_system *t) {
    int i, p_W;
    passenger p;

    for(i = 0; i < t->length; i++) {
        p = t->passengers[i];
        p_W = p.wait_time;
        if(p_W > 0) {
            t->passengers[i].wait_time -= 1;
        }
    }
}

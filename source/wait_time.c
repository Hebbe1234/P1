#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"

#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/*Checking if passengers can finish*/
void wait_time(transition_system *t) {
    int i, j , p_W;
    passenger p;
    for(i = 0; i < t->length; i++) {
        p = t->passengers[i];
        p_W = p.wait_time;
        for (j = 0; j < t->passengers[i].wait_time ; j++){
            if (p_W > 0) {
                p_W -= 1;
            }
        }
    t->passengers[i].wait_time = p_W;
    }
}

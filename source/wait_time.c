#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"

#endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../headers/print_passenger.h"

/*Decreasing wait time for everyone in the system */
void wait_time(transition_system *t) {
    int i;

    for (i = 0; i < t->length; i++) {

        if (t->passengers[i].wait_time > 0) {
            
            t->passengers[i].wait_time--;
            print_but_with_silence(&(t->passengers[i]), "WAITING", i);
        }
    }
}

#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"

#endif
#include <stdio.h>
#include <stdlib.h>

/* Checks if entire transition system is finished */
int is_finished (transition_system *t, int length) {
    int finished = 1;
    int i;

    for (i = 0; i < length; i++) {
        if (t->passengers[i].finish == 0) {
            finished = 0;
        }
    }

    return finished;
}
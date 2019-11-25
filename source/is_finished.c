#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"

#endif
#include <stdio.h>
#include <stdlib.h>

int is_finished (transition_system *t, int length) {
    int finished = 1;

    for (i = 0; i < length; i++) {
        if (p.finish == 0) {
            finished = 0;
        }
    }

    return finished;
}
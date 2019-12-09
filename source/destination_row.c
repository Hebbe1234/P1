#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"

#endif

#include <math.h>

/* Encapsulation of the formula for getting the destination row */
int d_row(passenger *p, transition_system *t) {
    return floor(p->destination / t->seats_per_row);
}


#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"

#endif
#include <stdio.h>
#include <stdlib.h>

/* This function takes a t_system as input and prints its current values */
void print_t_system (transition_system t_system) {

    printf("Deistination \t %d ", t_system.destinations);
    printf("Entrance \t %d ", t_system.entrance);
    printf("Rows \t %d ", t_system.rows);
    printf("Seats per row \t %d ", t_system.seats_per_row);
    printf("length \t%d ", t_system.length);
    printf("Carry on percentage \t%d ", t_system.carryon_percentage);
    printf("terations \t%d ", t_system.iterations);
    printf("\n");
    printf("waittime carryon \t%d ", t_system.wait.t_c);
    printf("waittime movement \t%d ", t_system.wait.t_m);
    printf("waittime inteference 0 \t%d ", t_system.wait.t_0);
    printf("waittime inteference 1 \t%d ", t_system.wait.t_1);
    printf("waittime inteference 2 \t%d ", t_system.wait.t_2);
    printf("waittime inteference 3 \t%d ", t_system.wait.t_3);
}
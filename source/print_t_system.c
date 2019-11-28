#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"

#endif
#include <stdio.h>
#include <stdlib.h>

/* This function takes a t_system as input and prints its current values */
void print_t_system (transition_system t_system){

    printf("Deistination \t\t %d \n", t_system.destinations);
    printf("Entrance \t\t %d \n", t_system.entrance);
    printf("Rows \t\t\t %d\n", t_system.rows);
    printf("Seats per row \t\t %d \n", t_system.seats_per_row);
    printf("length \t\t\t%d \n", t_system.length);
    printf("Carry on percentage \t%d \n", t_system.carryon_percentage);
    printf("terations \t\t%d \n", t_system.iterations);
    printf("\n");
    printf("waittime carryon \t%d \n", t_system.wait.t_c);
    printf("waittime movement \t%d \n", t_system.wait.t_m);
    printf("waittime inteference 0 \t%d \n", t_system.wait.t_0);
    printf("waittime inteference 1 \t%d \n", t_system.wait.t_1);
    printf("waittime inteference 2 \t%d \n", t_system.wait.t_2);
    printf("waittime inteference 3 \t%d \n", t_system.wait.t_3);
}
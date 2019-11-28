#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"

#endif
#include <stdio.h>
#include <stdlib.h>

/* This function takes a t_system as input and prints its current values */
void print_t_system (transition_system t_system){

    printf("Destination \t\t %d \n", t_system.destination_length);
    printf("Entrance \t\t %d \n", t_system.entrance);
    printf("Rows \t\t\t %d\n", t_system.rows);
    printf("Seats per row \t\t %d \n", t_system.seats_per_row);
    printf("Length \t\t\t%d \n", t_system.length);
    printf("Carry on percentage \t%d \n", t_system.carryon_percentage);
    printf("Iterations \t\t%d \n", t_system.iterations);
    printf("\n");
    printf("Wait time carry-on \t%d \n", t_system.wait.t_c);
    printf("Wait time movement \t%d \n", t_system.wait.t_m);
    printf("Wait time interference 0 \t%d \n", t_system.wait.t_0);
    printf("Wait time interference 1 \t%d \n", t_system.wait.t_1);
    printf("Wait time interference 2 \t%d \n", t_system.wait.t_2);
    printf("Wait time interference 3 \t%d \n", t_system.wait.t_3);
}

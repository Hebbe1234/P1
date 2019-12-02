#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"

#endif
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../headers/print_passenger.h"


/*Gives a waittime based on having carryon, and removes carryon*/
void carry_on(transition_system *t) {
    int i;

    for(i = 0; i < t->length; i++) {
        if(t->passengers[i].carry_on == 1 &&
           t->passengers[i].location == floor(t->passengers[i].destination / t->seats_per_row)) {
               t->passengers[i].carry_on = 0;
               t->passengers[i].wait_time += t->wait.t_c;
                printf("%-15s P%d","CARRY_ON", i);
                print_passenger_line(&(t->passengers[i]));
           }
    }
}
#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"

#endif
#include <stdio.h>
#include <stdlib.h>

#include "../headers/print_passenger.h"

#include "../headers/destination_row.h"

/*Gives a waittime based on having carryon, and removes carryon*/
void carry_on(transition_system *t) {
    int i;

    for (i = 0; i < t->length; i++) {
        if (t->passengers[i].carry_on == 1 && t->passengers[i].location == d_row(&(t->passengers[i]), t)) {

            t->passengers[i].carry_on = 0;
            t->passengers[i].wait_time += t->wait.t_c;

            print_but_with_silence(&(t->passengers[i]), "CARRY-ON", i);
        }
    }
}

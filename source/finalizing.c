#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"

#endif

#ifndef FINAL
#define FINAL

#include "../headers/finalizing.h"

#endif
#include <stdio.h>
#include <stdlib.h>
#include "../headers/print_passenger.h"
#include "../headers/destination_row.h"

/* Checks if a passenger is finished by destination wait time and carry on */
void finalising_passenger(transition_system *t) {
    int i;
    passenger p;

    for (i = 0; i < t->length; i++) {
        p  = t->passengers[i];

        if (p.finish == 0 && p.location == d_row(&p, t) && p.carry_on == 0 && p.wait_time == 0 && p.interference_flag == 1) {

            t->passengers[i].finish = 1;

            print_but_with_silence(&(t->passengers[i]), "FINALIZING", i);
        }
    }
}

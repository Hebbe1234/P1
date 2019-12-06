#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"
#include "../headers/inter.h"

#endif
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../headers/print_passenger.h"

/* checks for every passenger and assign a waiting time base on current interference */
void interference_function (transition_system *t) {
    int i;

    for(i = 0; i < t->length; i++) {

        if (t->passengers[i].location == floor(t->passengers[i].destination / t->seats_per_row) && t->passengers[i].interference_flag == 0) {
 
            t->passengers[i].wait_time += inter(t, t->passengers[i]);
            t->passengers[i].interference_flag = 1;
            print_but_with_silence(&(t->passengers[i]), "INTERFERENCE", i);
        }
    }
}

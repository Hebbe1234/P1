#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"
#include "../headers/inter.h"

#endif
#include <stdio.h>
#include <stdlib.h>
#include "../headers/destination_row.h"

/* checks for every passenger and assign a waiting time base on current interference */
void interference_function (transition_system *t) {
    int i;

    for(i = 0; i < t->length; i++) {

        if (t->passengers[i].location == d_row(&(t->passengers[i]), t) && t->passengers[i].interference_flag == 0) {
 
            t->passengers[i].wait_time += inter(t, t->passengers[i]);
            t->passengers[i].interference_flag = 1;
 
        }
    }
}

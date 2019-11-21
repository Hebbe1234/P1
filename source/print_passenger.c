#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"

#endif
#include <stdio.h>
#include <stdlib.h>

/* 
    You need to remember that this function only takes a struct (or a pointer to a struct) as input.
    Depending on whether or not, you use the value of the struct, you access the fields using either:

    struct.<name_of_field>
    struct_pointer-><name_of_field>

    But instead of writing <name_of_field> you write the actual name of the field e.g destination, location, etc.
*/

void print_passenger_function (passenger *passengers) {
    int P_D = passenger.destination, 
        P_L = passenger.location, 
        P_F = passenger.finish, 
        P_S = passenger.spotting->location,
        P_C = passenger.carry_on, 
        P_W = passenger.wait_time, 
        P_I = passenger.interference_flag;
        

    printf(" Destination: %d\n Location: %d\n Finish: %d\n Location of passenger infront: %d\n Carry-on: %d\n Wait time: %d\n Interference: %d\n",
    P_D, P_L, P_F, P_S, P_C, P_W, P_I);
}

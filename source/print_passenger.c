#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"

#endif
#include <stdio.h>
#include <stdlib.h>

void print_passenger_function (passenger *passengers) {
    int P_D = passengers.destination, 
        P_L = passengers.location, 
        P_F = passengers.finish, 
        P_S = passengers.spotting->location,
        P_C = passengers.carry_on, 
        P_W = passengers.wait_time, 
        P_I = passengers.interference_flag;
        

    printf(" Destination: %d\n Location: %d\n Finish: %d\n Location of passenger infront: %d\n Carry-on: %d\n Wait time: %d\n Interference: %d\n",
    P_D, P_L, P_F, P_S, P_C, P_W, P_I);
}

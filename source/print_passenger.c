#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"

#endif
#include <stdio.h>
#include <stdlib.h>


void print_passenger_function (passenger person) {
    int P_D = person.destination, 
        P_L = person.location, 
        P_F = person.finish, 
        P_S = person.spotting->location,
        P_C = person.carry_on, 
        P_W = person.wait_time, 
        P_I = person.inteference_flag;        

    printf(" Destination: %d\n Location: %d\n Finish: %d\n Location of passenger infront: %d\n Carry-on: %d\n Wait time: %d\n Interference: %d\n",
    P_D, P_L, P_F, P_S, P_C, P_W, P_I);
}

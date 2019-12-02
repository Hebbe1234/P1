#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"

#endif
#include <stdio.h>
#include <stdlib.h>
extern int silence;
/* This function takes a passenger as input and prints his current values */
void print_passenger (passenger *person) {
    int P_D = person->destination, 
        P_L = person->location, 
        P_F = person->finish, 
        /* Finds the location of the person in front */
        P_S = person->spotting != NULL ? person->spotting->location : -100,
        P_C = person->carry_on, 
        P_W = person->wait_time, 
        P_I = person->interference_flag;        

    printf(" Destination: %d\n Location: %d\n Finished: %d\n Location of passenger infront: %d\n Carry-on: %d\n Wait time: %d\n Interference: %d\n",
    P_D, P_L, P_F, P_S, P_C, P_W, P_I);
}

/* This function takes a passenger as input and prints his current values on a single line*/
void print_passenger_line(passenger *person) {
    int P_D = person->destination, 
        P_L = person->location, 
        P_F = person->finish, 
        /* Finds the location of the person in front */
        P_S = person->spotting != NULL ? person->spotting->location : -100,
        P_C = person->carry_on, 
        P_W = person->wait_time, 
        P_I = person->interference_flag;        
    
    printf(" Destination: %d | Location: %d | Finished: %d | Location of passenger infront: %d | Carry-on: %d | Wait time: %d | Interference: %d\n",
    P_D, P_L, P_F, P_S, P_C, P_W, P_I);
}

/* Prints passenger states with option to ignore printing with --silence */
void print_but_with_silence(passenger *person, char *string, int index) {

    if(silence == 0) {
        printf("%-15s P%d\n", string, index);
        print_passenger_line(person);
    }
    
}

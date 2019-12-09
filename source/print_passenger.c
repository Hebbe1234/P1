#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"

#endif
#include <stdio.h>
#include <stdlib.h>

#include "../headers/print_passenger.h"

/* This function takes a passenger as input and prints his current values */
void print_passenger (passenger *person) {   

    printf(" Destination: %d\n Location: %d\n Finished: %d\n Location of passenger infront: %d\n 
             Carry-on: %d\n Wait time: %d\n Interference: %d\n",
             person->destination, person->location, person->finish, person->spotting->location, 
             person->carry_on, person->wait_time, person->interference_flag);
}

/* This function takes a passenger as input and prints his current values on a single line*/
void print_passenger_line(passenger *person) {

    printf(" Destination: %2d | Location: %2d | Finished: %1d | Location of passenger infront: %4d | 
             Carry-on: %1d | Wait time: %2d | Interference: %d\n",
             person->destination, person->location, person->finish, person->spotting->location, 
             person->carry_on, person->wait_time, person->interference_flag);
}

/* Prints passenger states with option to ignore printing with --silence */
void print_but_with_silence(passenger *person, char *string, int index) {

    if (silence == 0) {
        printf("%-15s P%d\n", string, index);
        print_passenger_line(person);
    }
    
}

#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"
#include "../headers/is_finished.h"
#include "../headers/finalizing.h"
#include "../headers/movement.h"
#include "../headers/person_in_front.h"
#include "../headers/rear.h"
#include "../headers/initializing.h"

#endif
#include <stdio.h>
#include <stdlib.h>

void simulation(transition_system t_system);

int main (void) {
    
    transition_system t_system;
    
    int destinationss[] = {0, 1, 2, 3};
    int i;
    passenger passengerss[4];
    
    t_system.entrance = 0; 
    t_system.rows = 2;
    t_system.destination_length = 4;
    t_system.seats_per_row = 1;
    t_system.destinations = &destinationss;
    t_system.passengers = &passengerss;
    t_system.length = 2;
    
    
    passengerss[0].spotting = NULL;
    passengerss[0].destination = 0;
    passengerss[0].location = -1;
    passengerss[0].finish = 0;

    for (i = 1; i < t_system.length; ++i) {
        passengerss[i].destination = i;
        passengerss[i].location = -1;
        passengerss[i].finish = 0;
        passengerss[i].spotting = &(passengerss[i - 1]);
    }

    simulation(t_system);
    return 0;
}

void simulation(transition_system t_system) {
    int index;

    while (is_finished(&t_system) == 0) {
        /* Finish */
        finalizing_passenger(&t_system);
        person_in_front(&t_system);
        /* Movement */
        movement(&t_system);  
        /* Entering */
        initialize_passenger(&t_system);
    }
    


}
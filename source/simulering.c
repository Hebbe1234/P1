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
    
    t_system.entrance = 0; 
    t_system.rows = 2;
    
    t_system.passengers[4];
    t_system.length = 2;
    
    simulation(t_system);
    return 0;
}

void simulation(transition_system t_system) {
    int index;

    while (is_finished(&t_system, t_system.length) == 0) {
        /* Finish */
        finalizing_passenger(&t_system);
        person_in_front(&t_system);
        /* Movement */
        movement(&t_system);  
        /* Entering */
        initialize_passenger(&t_system);
    }
    


}
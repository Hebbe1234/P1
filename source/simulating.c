#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"
#include "../headers/is_finished.h"
#include "../headers/finalizing.h"
#include "../headers/movement.h"
#include "../headers/person_in_front.h"
#include "../headers/rear.h"
#include "../headers/initializing.h"
#include "../headers/print_passenger.h"
#include "../headers/simulation.h"
#include "../headers/queue_generator.h"
#include "../headers/wait_time.h"
#include "../headers/interference.h"
#include "../headers/carry_on.h"


#endif
#include <stdio.h>
#include <stdlib.h>


void run_simulation() {
    
    transition_system t_system;
    

    t_system.iterations = 1;
    t_system.entrance = 0; 
    t_system.rows = 10;                  /*bliver beregnet*/
    t_system.destination_length = 4;    /*Bruges ikke indtilvidere*/
    t_system.seats_per_row = 6;
    t_system.length = 57;
    t_system.carryon_percentage = 50;
    t_system.wait.t_0 = 0;
    t_system.wait.t_1 = 2;
    t_system.wait.t_2 = 3;
    t_system.wait.t_3 = 4;
    t_system.wait.t_c = 5;
    t_system.wait.t_m = 1;

    t_system.passengers = (passenger*)calloc(t_system.length, sizeof(passenger));

    initialize_passenger_array(&t_system);

    simulation(&t_system);
}

void simulation(transition_system *t_system) {
    /*int index;*/
    int j, i;

    while (is_finished(t_system) == 0 && t_system->iterations <10000) {
        /* Finish */
        finalising_passenger(t_system);
        person_in_front(t_system);
        /*Waiting*/
        wait_time(t_system);
        /*Carry_on*/
        carry_on(t_system);
        /*Interference*/
        interference_function(t_system);
        /* Movement */
        movement(t_system);  
        /* Entering */
        initialize_passenger(t_system);
        t_system->iterations += 1;
    }

    printf("%d\n", t_system->iterations);

    for(j=0, i=0; j<t_system->length; j++){
        if (t_system->passengers[j].finish ==1)
            i++;
    }
    printf("\nFinished passenger amount %d\n", i);
}
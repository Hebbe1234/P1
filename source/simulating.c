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
#include "../headers/initialize_passenger_array.h"
#include "../headers/random_boarding_generator.h"
#include "../headers/wait_time.h"
#include "../headers/interference.h"
#include "../headers/carry_on.h"


#endif
#include <stdio.h>
#include <stdlib.h>


void run_simulation() {
    
    transition_system t;
    int *destination;

    t.iterations = 1;
    t.entrance = 9; 
    t.rows = 10;                  /*bliver beregnet*/
    t.destination_length = 4;    /*Bruges ikke indtilvidere*/
    t.seats_per_row = 6;
    t.length = 57;
    t.carryon_percentage = 50;
    t.wait.t_0 = 0;
    t.wait.t_1 = 2;
    t.wait.t_2 = 3;
    t.wait.t_3 = 4;
    t.wait.t_c = 5;
    t.wait.t_m = 2;

    t.passengers = (passenger*)calloc(t.length, sizeof(passenger));

    destination = (int*)calloc(t.length, sizeof(int));

    random_boarding_generator(&t, destination);

    initialize_passenger_array(&t, destination);

    simulation(&t);
}

void simulation(transition_system *t) {
    /*int index;*/
    int j, i;

    while (is_finished(t) == 0 && t->iterations <10000) {
        printf("\n-----ITERATION %d-----\n", t->iterations);
        /* Finish */
        finalising_passenger(t);
        person_in_front(t);
        /*Waiting*/
        wait_time(t);
        /*Carry_on*/
        carry_on(t);
        /*Interference*/
        interference_function(t);
        /* Movement */
        movement(t);  
        /* Entering */
        initialize_passenger(t);

        printf("-----ITERATION %2d-----\n", t->iterations);

        t->iterations += 1;
    }

    printf("%d\n", t->iterations);

    for(j=0, i=0; j<t->length; j++){
        if (t->passengers[j].finish ==1)
            i++;
    }
    printf("\nFinished passenger amount %d\n", i);
}
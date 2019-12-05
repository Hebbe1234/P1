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
#include "../headers/input.h"
#include "../headers/print_t_system.h"


#endif
#include <stdio.h>
#include <stdlib.h>

int run_simulations(void){
    int i, iterations;
    transition_system t_input, t1, t2;


    t_input.carryon_percentage = 50;
    t_input.destination_length = 60;
/*    t_input.destinations = 57; */
    t_input.entrance = 4;
    t_input.iterations = 0;
    t_input.length = 57;
    t_input.rows = 10;
    t_input.seats_per_row = 6;
    t_input.simulations = 10;
    t_input.wait.t_0 = 50;
    t_input.wait.t_1 = 100;
    t_input.wait.t_2 = 150;
    t_input.wait.t_3 = 220;
    t_input.wait.t_c = 250;
    t_input.wait.t_m = 15;
    t_input.destination_length = t_input.rows * t_input.seats_per_row;

/*
    t_input = input_t_system();
*/
    t1 = t2 = t_input;

    if((t_input.rows % 2) == 1) {
        t1.rows = (t_input.rows - 1) / 2;
        t2.rows = (t_input.rows + 1) / 2;
    }

    t1.entrance = t_input.entrance;
    t2.entrance = (t_input.rows-1) - t_input.entrance;

    print_t_system(t_input);
    print_t_system(t1);
    print_t_system(t2);

    for(i = 0, iterations = 0; i < t_input.simulations; i++) {
        run_simulation(&t1);
        run_simulation(&t2);
        iterations += t1.iterations < t2.iterations ? t2.iterations : t1.iterations; 
        printf("\n\n\n\n\n %d iterations %d iteration t1, %d iteration t2 \n\n\n\n\n", iterations, t1.iterations, t2.iterations);
        t1.iterations = t2.iterations = 0;
    }
    return (iterations / i); 
}

/*her skal der modtages en pointer til t systemet*/
void run_simulation(transition_system *t) {
    int *destination;

    t->passengers = (passenger*)calloc(t->length, sizeof(passenger));

    destination = (int*)calloc(t->length, sizeof(int));

    random_boarding_generator(t, destination);

    initialize_passenger_array(t, destination);

    simulation(t);
    free(destination);
    free(t->passengers);
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


/*

    

    t.iterations = 1;
    t.entrance = 0; 
    t.rows = 10;                 bliver beregnet
    t.destination_length = 4;    Bruges ikke indtilvidere
    t.seats_per_row = 6;
    t.length = 57;
    t.carryon_percentage = 50;
    t.wait.t_0 = 50;
    t.wait.t_1 = 100;
    t.wait.t_2 = 110;
    t.wait.t_3 = 220;
    t.wait.t_c = 180;
    t.wait.t_m = 15;

    */
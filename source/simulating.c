#ifndef STRUCTS
#define STRUCTS
#include "../headers/structs.h"
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
#define CHARACTERS_IN_LINE 100

/* runs multiple simulations and returns the average */
int run_simulations(void){
    int i, iterations;
    transition_system t_input, t1, t2;

    load_input(&t_input);

    split_plane(&t_input, &t1, &t2);

    for (i = 0, iterations = 0; i < t_input.simulations; i++) {
        run_simulation(&t1);
        run_simulation(&t2);
        iterations += t1.iterations < t2.iterations ? t2.iterations : t1.iterations; 
        t1.iterations = t2.iterations = 0;
        printf("|");
    }
    return (iterations / t_input.simulations); 
}

/* makes a transition system for the simulation */
void run_simulation(transition_system *t) {
    int *destination;

    t->passengers = (passenger*)calloc(t->length, sizeof(passenger));

    destination = (int*)calloc(t->destination_length, sizeof(int));

    random_boarding_generator(t, destination);

    initialize_passenger_array(t, destination);

    simulation(t);
    free(destination);
    free(t->passengers);
}

/* run single simulation of transition system */
void simulation(transition_system *t) {

    while (is_finished(t) == 0) {
        
        if (silence == 0) {
            printf("\n-----ITERATION %d-----\n", t->iterations);
        }
        /* Finish */
        finalising_passenger(t);
        person_in_front(t);
        /* Waiting */
        wait_time(t);
        /* Carry_on */
        carry_on(t);
        /* Interference */
        interference_function(t);
        /* Movement */
        movement(t);  
        /* Entering */
        initialize_passenger(t);

        if(silence == 0) {
            printf("-----ITERATION %2d-----\n", t->iterations);
        }
        t->iterations += 1;
    }
}

/* Reads the input file (input.txt) into the transition system */
void load_input(transition_system *t_input) {
    FILE *infile;
    char line[CHARACTERS_IN_LINE] = "";
    
    infile = fopen("input.txt", "r");

    if (infile == NULL) {
        printf("Couldnt load file properly, Error");
        return;
    }

    fgets(line, CHARACTERS_IN_LINE, infile);
    sscanf(line, "%d ", &t_input->entrance);
    fgets(line, CHARACTERS_IN_LINE, infile);
    sscanf(line, "%d ", &t_input->length);
    fgets(line, CHARACTERS_IN_LINE, infile);
    sscanf(line, "%d ", &t_input->rows);
    fgets(line, CHARACTERS_IN_LINE, infile);
    sscanf(line, "%d ", &t_input->seats_per_row);
    fgets(line, CHARACTERS_IN_LINE, infile);
    sscanf(line, "%d ", &t_input->wait.t_0);
    fgets(line, CHARACTERS_IN_LINE, infile);
    sscanf(line, "%d ", &t_input->wait.t_1);
    fgets(line, CHARACTERS_IN_LINE, infile);
    sscanf(line, "%d ", &t_input->wait.t_2);
    fgets(line, CHARACTERS_IN_LINE, infile);
    sscanf(line, "%d ", &t_input->wait.t_3);
    fgets(line, CHARACTERS_IN_LINE, infile);
    sscanf(line, "%d ", &t_input->wait.t_c);
    fgets(line, CHARACTERS_IN_LINE, infile);
    sscanf(line, "%d ", &t_input->wait.t_m);
    fgets(line, CHARACTERS_IN_LINE, infile);
    sscanf(line, "%d ", &t_input->carryon_percentage);
    fgets(line, CHARACTERS_IN_LINE, infile);
    sscanf(line, "%d ", &t_input->simulations);

    t_input->destination_length = t_input->rows * t_input->seats_per_row;
    t_input->iterations = 0;
}

/* divides the rows and passengers into 'front and back' of plane for the two transition systems
    and assigns the entrance for both */
void split_plane(transition_system *t_input, transition_system *t1, transition_system *t2) {
    *t1 = *t2 = *t_input;
    
    if ((t_input->length % 2) == 1) {
        t1->length = (t_input->length - 1) / 2;
        t2->length = (t_input->length + 1) / 2;
    } 
    else {
        t1->length = t2->length = t_input->length / 2;
    }

    if ((t_input->rows % 2) == 1) {
        t1->rows = (t_input->rows - 1) / 2;
        t2->rows = (t_input->rows + 1) / 2;
    } 
    else {
        t1->rows = t2->rows = t_input->rows / 2;
    }

    t1->entrance = t_input->entrance;
    if (t_input->rows % 2 == 1) {
        t2->entrance = (t_input->rows - 1) / 2 - t_input->entrance;
    } 
    else {
        t2->entrance = ((t_input->rows / 2) - 1)  - t_input->entrance;
    }

    t1->destination_length = t_input->destination_length / 2;
    t2->destination_length = t_input->destination_length / 2;
}

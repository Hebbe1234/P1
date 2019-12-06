#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"

#endif


/* runs multiple simulations and returns the average */
int run_simulations(void); 
/* makes a transition system for the simulation */
void run_simulation(transition_system *t);
/* run single simulation of transition system */
void simulation(transition_system *t_system);
/* Reads the input file (input.txt) into the transition system */
void load_input(transition_system *t);
/* divides the rows and passengers into 'front and back' of plane for the two transition systems
    and assigns the entrance for both */
void split_plane(transition_system *t_input, transition_system *t1, transition_system *t2) ;

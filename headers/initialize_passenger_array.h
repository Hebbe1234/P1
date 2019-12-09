#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"

#endif

/*Produces a passenger array, that contains a random destination, and carryon for each passenger*/
void initialize_passenger_array(transition_system *t, int *destination_array);
/* Resets that passenger array, and gives location -1*/
void reset_passenger_array(transition_system *t);
/* The passenger array gets filled with random destination, based on the random_destination array*/
void initialize_destination(int *destination_a, transition_system *t);
/*Passenger 0 is initialized to 0, and the rest, looks at the person in front*/
void initialize_spotting(transition_system *t);
/*Based on a carryon percentage, the passengers gets carryon*/
void get_carryon(transition_system *t);
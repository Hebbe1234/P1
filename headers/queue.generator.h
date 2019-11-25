#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"

#endif

/*Produces a passenger array, that contains a random destination, and carryon for each passenger*/
void initialize_passenger_array();
/* Resets that passenger array, and gives location -1*/
void reset_passenger_array(passenger passengers [], int length_of_array);
/*Produces an array with random numbers, from 0 to that number of seats*/
void get_random_array(int random_destinations[], int length_of_array);
/* The passenger array gets filled with random destination, based on the random_destination array*/
void passenger_get_random_destinations(int *random_destinations, passenger passengers [], int length_of_array);
/*Passenger 0 is initialized to 0, and the rest, looks at the person in front*/
void initialize_spotting(passenger passengers[], int length_of_array);
/*Based on a carryon percentage, the passengers gets carryon*/
void get_carryon(passenger passengers[], int length_of_array);
/*Tests if the seat is replaced by a door, and therefore illegal*/
int  is_illegal_seat(int i);
/*Used to create random destination, by generating 2 random numbers*/
void get_random_number(int *k,int *j);
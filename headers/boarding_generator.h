#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"

#endif

/*Fills the given array with legal destinations that is shuffled so its similar to outside in boarding*/
void outsidein_boarding_generator(transition_system *t, int *destinations);
/*Fills the given array with legal destinations that is shuffled*/
void random_boarding_generator(transition_system *t, int *random_destinations);
/*Tests if the seat is replaced by a door, and therefore illegal*/
int is_legal_seat(int seat_tested, transition_system *t);
/*Used to create random destination, by generating 2 random numbers*/
void get_random_number(int *k,int *j, int length);
/*Takes and array and shuffles it based on the lenght of the array. */
void shuffle_array(int *array, int length);


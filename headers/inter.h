#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"

#endif

/* Returns a given passenger's waittime, based on the location of other passengers in their 'row' */ 
int inter(transition_system *t, int index);

/* Returns a value true or false whether a passenger is occupying seat */
int is_passenger_at_seat(transition_system *t, passenger p, int i, int seat);

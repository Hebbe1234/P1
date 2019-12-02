#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"

#endif
/* This function takes a passenger as input and prints his current values */
void print_passenger (passenger *person);

/* This function takes a passenger as input and prints his current values on a single line*/
void print_passenger_line(passenger *person);

/* Prints passenger states with option to ignore printing with --silence */
void print_but_with_silence(passenger *person, char *string, int index);

#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"

#endif

/* Checks which passenger the last initialized passenger must look at 
 * by finding the passenger closest to the entrance. Input is index
 * of initialized passenger, output is index of passenger closest to 
 * the entrance. If no one is found, output is index = -1 */ 
int rear_function (transition_system *t, int i);

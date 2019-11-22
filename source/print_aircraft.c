#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"

#endif
#include <stdio.h>
#include <stdlib.h>

#define SIZE_OF_INTERFERENCE 2*10

void print_aircraft(aircraft plane) {
    int i;
    int O = sizeof(plane.boarding),
        V = plane.v_left.destination,
        H = plane.h_right.destination,
        E = plane.entrance;

    printf(" Number of passengers: %d\n Location of last left person: %d\n location of last right person: %d\n Location of entrance: %d\n",
    O, V, H, E);
    for (i = 0; i < SIZE_OF_INTERFERENCE; i++)
    {
        printf("%d\n", plane.interference[i]);
    }
    
}
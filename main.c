#ifndef STRUCTS
#define STRUCTS

#include "headers/structs.h"

#endif

#include "headers/input.h"
#include "headers/print_t_system.h"
#include "headers/print_passenger.h"
#include "headers/random_boarding_generator.h"

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "headers/main.h"

int silence = 0;

int main (int argc, char *argv[])
{
    int i;
    transition_system t;
    int *destination;

    t.iterations = 1;
    t.entrance = 9; 
    t.rows = 10;                  /*bliver beregnet*/
    t.destination_length = 4;    /*Bruges ikke indtilvidere*/
    t.seats_per_row = 6;
    t.length = 57;
    t.carryon_percentage = 50;
    t.wait.t_0 = 0;
    t.wait.t_1 = 2;
    t.wait.t_2 = 3;
    t.wait.t_3 = 4;
    t.wait.t_c = 5;
    t.wait.t_m = 2;

    destination = (int*)calloc(t.length+ t.seats_per_row/2, sizeof(int));


    srand(time(0));
    
    for (i = 0; i < argc; i++) {
        if (strcmp("--silence", argv[i]) == 0) {
            silence = 1;
        }
    }

    printf("Program ran OK");
    



    return EXIT_SUCCESS;
}



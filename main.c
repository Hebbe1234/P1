#ifndef STRUCTS
#define STRUCTS

#include "headers/structs.h"

#endif
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#include "headers/simulation.h"

int silence = 0;

int main (int argc, char *argv[]) {
    int i, result = 0, start = 0, simulation_type = 0;
    int *result_multiple_entrance = (int*)calloc(1, sizeof(int));

    srand(time(NULL));
    start = time(0);

    for (i = 0; i < argc; i++) { 
        if (strcmp("--silence", argv[i]) == 0) {
            silence = 1;
        }
        if (strcmp("--multiple", argv[i]) == 0) {
            simulation_type = 1;
        } 
    }

    if (simulation_type == 0) {
        result = run_simulations();
        printf("\nIt took %d iterations on average", result);

    } else if (simulation_type == 1) {
        run_simulations_with_multiple_entrances(result_multiple_entrance);
    }

    printf("\nIT TOOK %d SECONDS TO RUN THE PROGRAM\n", ((int)time(0)) - start);
    printf("Program ran OK");
    
    return EXIT_SUCCESS;
}

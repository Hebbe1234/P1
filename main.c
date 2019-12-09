#ifndef STRUCTS
#define STRUCTS

#include "headers/structs.h"

#endif

#include "headers/input.h"
#include "headers/print_t_system.h"
#include "headers/simulation.h"
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
    int i, result = 0, start = 0;
    int *results = (int *)calloc(1, sizeof(int));
    setbuf(stdout, NULL);
    srand(time(NULL));


    for (i = 0; i < argc; i++) { 
        if (strcmp("--silence", argv[i]) == 0) {
            silence = 1;
        }
    }
    
    /*result = run_simulations();*/
    
    start = time(0);
    run_simulations_with_multiple_entrances(results);
    printf("\n\n%d iterations gennemsnit osv\n", result);

    printf("Program ran OK");
    
    return EXIT_SUCCESS;
}



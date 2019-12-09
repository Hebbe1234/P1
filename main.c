#ifndef STRUCTS
#define STRUCTS

#include "headers/structs.h"

#endif

#include "headers/input.h"
#include "headers/print_t_system.h"
#include "headers/simulation.h"
#include "headers/print_passenger.h"
<<<<<<< HEAD
#include "headers/boarding_generator.h"
=======
#include "headers/random_boarding_generator.h"
>>>>>>> master

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
    srand(time(NULL));

<<<<<<< HEAD
=======

>>>>>>> master
    for (i = 0; i < argc; i++) { 
        if (strcmp("--silence", argv[i]) == 0) {
            silence = 1;
        }
    }
<<<<<<< HEAD

    start = time(0);
    result = run_simulations();
    printf("\nIT TOOK %d SECONDS\n", ((int)time(0)) - start);

=======
        
    start = time(0);
    result = run_simulations();
    printf("\nIT TOOK %d SECONDS\n", time(0) - start);

>>>>>>> master
    printf("It took %d iterations on average\n", result);
    printf("Program ran OK");
    
    return EXIT_SUCCESS;
}



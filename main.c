#ifndef STRUCTS
#define STRUCTS

#include "headers/structs.h"

#endif

#include "headers/input.h"
#include "headers/print_t_system.h"
#include "headers/simulation.h"

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#include "headers/main.h"



int main (void)
{
    srand(time(0));
    
    run_simulation();

    printf("Program ran OK");

    return EXIT_SUCCESS;
}



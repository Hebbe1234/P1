#ifndef STRUCTS
#define STRUCTS

#include "headers/structs.h"

#endif

#include "headers/input.h"
#include "headers/print_t_system.h"

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#include "headers/main.h"



int main (void)
{
    transition_system t;
    srand(time(0));
    
    
    t = input_t_system();

    print_t_system(t);

    printf("Program ran OK");

    return EXIT_SUCCESS;
}



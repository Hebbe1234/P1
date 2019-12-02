#ifndef STRUCTS
#define STRUCTS

#include "headers/structs.h"

#endif

#include "headers/input.h"
#include "headers/print_t_system.h"
#include "headers/print_passenger.h"

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
    passenger passengerq;
    passengerq.destination = 5;
    passengerq.location = 2;

    srand(time(0));
    
    for (i = 0; i < argc; i++) {
        if (strcmp("--silence", argv[i]) == 0) {
            silence = 1;
        }
    }
    print_passenger_line(&passengerq);
    printf("Program ran OK");

    return EXIT_SUCCESS;
}



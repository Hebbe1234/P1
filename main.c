#include <stdio.h>
#include <math.h>
#include "headers/main.h"

#ifndef INIT
#define INIT

#include "headers/initializing.h"

#endif

#ifndef PRINT_PASSENGER
#define PRINT_PASSENGER

#include "headers/print_passenger.h"

#endif

#ifndef STRUCTS
#define STRUCTS

#include "headers/structs.h"

#endif

#define NUMBER_OF_PASSENGERS_BOARDING 2
#define NUMBER_OF_ROWS 10
#define ENTRANCE_PLACEMENT 4 



int main (void)
{


    passenger example;
    passenger p1;
    aircraft plane;
    passenger test[2];

    p1.destination = 54;
    p1.location = -1;
    p1.finish = 0;
    p1.carry_on = 1;
    p1.wait_time = 0;
    p1.inteference_flag = 0;
    p1.spotting = &example;

    example.destination = 55;
    example.location = ENTRANCE_PLACEMENT+1;
    example.finish = 0;
    example.carry_on = 1;
    example.wait_time = 0;
    example.inteference_flag = 0;
    example.spotting = NULL;

    plane.v_left = example;

    /*printf("%d ", example.spotting->location);

    printf("%d\n", plane.v_left.spotting->location);*/
    
    test[0] = example;
    test[1] = p1;
    plane.entrance = ENTRANCE_PLACEMENT;

    initialize_passenger(test, plane);
    print_passenger(p1);

    printf("%d %d %d %d %d\n", p1.inteference_flag, p1.finish, p1.destination, p1.location, p1.carry_on);
    printf("%d %d %d %d %d\n", example.inteference_flag, example.finish, example.destination, test[0].location, example.carry_on);

    return(0);
}


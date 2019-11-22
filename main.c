#include <stdio.h>
#include <math.h>
#include "headers/main.h"

#ifndef INIT
#define INIT

#include "headers/initializing.h"

#endif

#ifndef STRUCTS
#define STRUCTS

#include "headers/structs.h"

#endif

#define NUMBER_OF_PASSENGERS_BOARDING 2
#define NUMBER_OF_ROWS 10
#define ENTRANCE_PLACEMENT 4 

void finalising(passenger* p1);


int main (void)
{


    passenger example;
    passenger p1;
    aircraft plane;
    passenger test[2];

    p1.destination = 31;
    p1.location = 5;
    p1.finish = 0;
    p1.carry_on = 0;
    p1.wait_time = 0;
    p1.inteference_flag = 2;
    p1.spotting = NULL;


    example.destination = 30;
    example.location = 4;
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

    printf("___________________\n");

    finalising(&p1);
    initialize_passenger(test, plane);

    printf("%d %d %d %d %d\n", p1.inteference_flag, p1.finish, p1.destination, p1.location, p1.carry_on);
    printf("%d %d %d %d %d\n", example.inteference_flag, example.finish, example.destination, test[0].location, example.carry_on);

    return(0);
}



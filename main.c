#include <stdio.h>
#include <math.h>
#include "headers/main.h"
#include <time.h>
#include <stdlib.h>

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
    transition_system t;
    passenger ps[2];
    int i;
    

    srand(time(0));


    p1.destination = 54;
    p1.location = -1;
    p1.finish = 0;
    p1.carry_on = 0;
    p1.wait_time = 0;
    p1.interference_flag = 0;
    p1.spotting = &example;

    example.destination = 30;
    example.location = 4;
    example.finish = 0;
    example.carry_on = 1;
    example.wait_time = 0;
    example.interference_flag = 0;
    example.spotting = NULL;

    ps[0] = p1;
    ps[1] = example;

    /*printf("%d ", example.spotting->location);

    printf("%d\n", plane.v_left.spotting->location);*/
    
    for(i = 0; i < 2; i++){
        t.passengers[i] = ps[i];
        printf("T Location i: %d\n", t.passengers[i].location);
    }

    t.entrance = ENTRANCE_PLACEMENT;
    printf("%d\n", t.entrance);

    initialize_passenger(&t, 2);

    printf("%d %d %d %d %d\n", p1.interference_flag, p1.finish, p1.destination, t.passengers[0].location, p1.carry_on);
    printf("%d %d %d %d %d\n", example.interference_flag, example.finish, example.destination, t.passengers[1].location, example.carry_on);

    return(0);
}



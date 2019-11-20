#include <stdio.h>
#include <math.h>
#include "headers/main.h"
#define NUMBER_OF_PASSENGERS_BOARDING 27
#define NUMBER_OF_ROWS 10
#define ENTRANCE_PLACEMENT 4 

int main (void)
{

/*Defining passenger as a struct type */
    typedef struct passenger
    {
        int destination, 
            location, 
            finish, 
            carry_on, 
            wait_time, 
            inteference_flag;
        struct passenger* spotting;
    } passenger s;
     

/*Defining the aircraft as a struct type */
    typedef struct aircraft 
    {
        passenger v_left;
        passenger h_right;
        int entrance;
        /*
            TODO: This should not be statically sized. 
            Use int* instead and dynamically allocate memory from a parameter given by the user
        */
        int inteference[2*NUMBER_OF_ROWS];
    } aircraft ;

    passenger example;
    passenger p1;
    aircraft plane;


    p1.destination = 54;
    p1.location = 5;
    p1.finish = 0;
    p1.carry_on = 1;
    p1.wait_time = 0;
    p1.inteference_flag = 0;
    p1.spotting = NULL;

    example.destination = 55;
    example.location = 4;
    example.finish = 0;
    example.carry_on = 1;
    example.wait_time = 0;
    example.inteference_flag = 0;
    example.spotting = &p1;


    plane.v_left = p1;

    printf("%d\n", example.spotting->destination);

    printf("%d\n", plane.v_left.destination);
    
    printf("%d %d %d %d %d\n", p1.inteference_flag, p1.finish, p1.destination, p1.location, p1.carry_on);



    return(0);
}



#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"

#endif

#ifndef INPUT
#define FINAL

#include "../headers/input.h"

#endif

#include <stdio.h>      
#include <stdlib.h>
#include <math.h>

/*Returns a transistion_system with the correct input, based on the users input*/
transition_system input_t_system(void){
    transition_system t_system ={0};
    wait_times struct_wait = {0};

    printf("\nWrite carry-on wait time\n");
    scanf("%d", &struct_wait.t_c);

    printf("\nWrite movement time\n");
    scanf("%d", &struct_wait.t_m);
    
    printf("\nWrite type 0 interference time\n");
    scanf("%d", &struct_wait.t_0);

    printf("\nWrite type 1 interference time\n");
    scanf("%d", &struct_wait.t_1);

    printf("\nWrite type 2 interference time\n");
    scanf("%d", &struct_wait.t_2);

    printf("\nWrite type 3 interference time\n");
    scanf("%d", &struct_wait.t_3);

    t_system.wait = struct_wait;

    printf("Write the amount of passengers\n");
    scanf("%d", &t_system.destination_length);

    printf("Write the amount of seats per row\n");
    scanf("%d", &t_system.seats_per_row);
    
    printf("\nWrite the amount of rows\n");
    scanf("%d", &t_system.rows);    

    printf("\nWrite entrance placement\n");
    scanf("%d", &t_system.entrance);

    printf("\nWrite the desired carryon percentage\n");
    scanf("%d", &t_system.carryon_percentage);

    printf("\nWrite the number of simulations desired\n");
    scanf("%d", &t_system.iterations);

    t_system.destination_length = t_system.rows * t_system.seats_per_row;

    t_system.passengers = (passenger*)calloc(t_system.length, sizeof(passenger));

    return t_system;
}

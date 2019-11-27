#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"

#endif

#ifndef FINAL
#define FINAL

#include "../headers/input.h"

#endif

#include <stdio.h>      
#include <stdlib.h>
#include <math.h>

/*Returns a wait_times with the correct input, based on the users input*/
/*Returns a transistion_system with the correct input, based on the users input*/
transition_system input_t_system(void){
    transition_system t_system ={0};
    wait_times struct_wait = {0};

    printf("\nWrite carryon time\n");
    scanf("%d", &struct_wait.t_c);

    printf("\nWrite movement time\n");
    scanf("%d", &struct_wait.t_m);

    printf("\nWrite type 1 inteference");
    scanf("%d", &struct_wait.t_1);

    printf("\nWrite type 1 inteference");
    scanf("%d", &struct_wait.t_2);

    printf("\nWrite type 1 inteference");
    scanf("%d", &struct_wait.t_3);

    t_system.wait = struct_wait;

    printf("Write the amount of passengers\n");
    scanf("%d", &t_system.array_length);
    
    printf("\nWrite the amount of seats\n");
    scanf("%d", &t_system.seats);    

    printf("\nWrite entrance placement\n");
    scanf("%d", &t_system.entrance);

    printf("\nWrite the desired carryon percentage\n");
    scanf("%d", &t_system.carryon_percentage);

    printf("\nWrite the number of simulations desired\n");
    scanf("%d", &t_system.iterations);

    t_system.passengers = (passenger*)calloc(t_system.array_length, sizeof(passenger));

    return t_system;
}



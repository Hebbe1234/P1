#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "../headers/main.h"
#include <time.h>

#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"
#include "../headers/queue.generator.h"

#endif

#define NUMBER_OF_PASSENGERS_BOARDING 57
#define NUMBER_OF_ROWS 10
#define ENTRANCE_PLACEMENT 4 
#define SEATS_PER_ROW 6





/*Produces a passenger array, that contains a random destination, and carryon for each passenger*/
void initialize_passenger_array() {
    int *random_destinations; 
    int length_of_array = NUMBER_OF_PASSENGERS_BOARDING;

    struct passenger *passengers;
    passengers = (struct passenger*)calloc(NUMBER_OF_PASSENGERS_BOARDING, sizeof(passenger));


    random_destinations = (int*)calloc(length_of_array + (SEATS_PER_ROW/2), sizeof(int));

    reset_passenger_array(passengers, length_of_array);
    get_random_array(random_destinations, length_of_array);
    passenger_get_random_destinations(random_destinations, passengers, length_of_array);
    initialize_spotting(passengers, length_of_array);
    get_carryon(passengers, length_of_array);
    free(random_destinations);
    free(passengers);
}


/* Resets that passenger array, and gives location -1*/
void reset_passenger_array(passenger passengers [], int length_of_array) {
    int i;
    for (i = 0; i < length_of_array; i=i+1) {
        passengers [i].destination = 0;
        passengers [i].location = -1;
        passengers [i].carry_on = 0;
        passengers [i].wait_time = 0;
        passengers [i].finish = 0;
        passengers [i].interference_flag = 0;
        passengers [i].spotting = NULL;
    }
}

/*Produces an array with random numbers, from 0 to that number of seats*/
void get_random_array(int random_destinations[], int length_of_array) {
    int i, j, k, tmp_plads;
    i = j = k = tmp_plads=0;

    for(i = 0; (i < length_of_array + (SEATS_PER_ROW/2)); i=i+1)
        random_destinations[i]=i;

    for(i = 0; i < 1000000; i = i + 1) {
        get_random_number(&k,&j);
        tmp_plads = random_destinations[k];
        random_destinations[k] = random_destinations[j];
        random_destinations[j] = tmp_plads;
    }
}




/* The passenger array gets filled with random destination, based on the random_destination array*/
void passenger_get_random_destinations(int *random_destinations, passenger passengers [], int length_of_array) {
    int *p_array, i;

    p_array = random_destinations;
    for(i=0; i < length_of_array; i=i+1)
    {
        while(*(p_array+i)== (is_illegal_seat(0)) || *(p_array+i) == (is_illegal_seat(1)) || *(p_array+i) == (is_illegal_seat(2))) {
            p_array = p_array+1;
        }
        passengers [i].destination = *(p_array+i);
    }
}

/*Tests if the seat is replaced by a door, and therefore illegal*/
int is_illegal_seat(int i) {
    int entrance_placement = 4;
    return ((entrance_placement * SEATS_PER_ROW) + (SEATS_PER_ROW/2) + i);
}

/*Passenger 0 is initialized to 0, and the rest, looks at the person in front*/
void initialize_spotting(passenger passengers[], int length_of_array) {
    int i;

    passengers [0].spotting = NULL;

    for(i=1; i < length_of_array; i=i+1) {
        passengers [i].spotting = &(passengers [i-1]);    
    }

 /*   
    for(i=1; i<57; i=i+1) {
        printf("%d , %d \n", passengers[i].spotting->destination, i);
    }
*/
}

/*Based on a carryon percentage, the passengers gets carryon*/
void get_carryon(passenger passengers[], int length_of_array){
    int i, j, carry_on_percentage;

    carry_on_percentage = 70;

    for(i = 0; i < length_of_array; i++){
        j = ((rand() % 100)+1);
        if(j <= carry_on_percentage) {
            passengers[i].carry_on = 1;
        }
        else {
            passengers[i].carry_on = 0;        
        }
    }
/*  printf("\n\n\n");
    for(i=0; i<57; i=i+1) {
        printf("%d , %d \n", passengers[i].carry_on, i);
    }
*/
}



/*Used to create random destination, by generating 2 random numbers*/
void get_random_number(int *k,int *j) {
    *k = (rand() % 60);
    *j = (rand() % 60);
}



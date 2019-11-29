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

/*Produces a passenger array, that contains a random destination, and carryon for each passenger*/
void initialize_passenger_array(transition_system t) {
    int *random_destinations; 

    random_destinations = (int*)calloc(t.length + (t.seats_per_row/2), sizeof(int));

    reset_passenger_array(t.passengers, t.length);
    get_random_array(random_destinations, t.length, t.seats_per_row, t.entrance);
    passenger_get_random_destinations(random_destinations, t.passengers, t.length,t.entrance, t.seats_per_row);
    initialize_spotting(t.passengers, t.length);
    get_carryon(t.passengers, t.length, t.carryon_percentage);
    free(random_destinations);
}


/* Resets that passenger array, and gives location -1*/
void reset_passenger_array(passenger passengers [], int length_of_array) {
    int i;
    for (i = 0; i < length_of_array; i++) {
        passengers[i].destination = 0;
        passengers[i].location = -1;
        passengers[i].carry_on = 0;
        passengers[i].wait_time = 0;
        passengers[i].finish = 0;
        passengers[i].interference_flag = 0;
        passengers[i].spotting = NULL;
    }
}

/*Produces an array with random numbers, from 0 to that number of seats*/
void get_random_array(int random_destinations[], int length_of_array, int seats_per_row, int entrance_placement) {
    int i, j, k, tmp_plads;
    i = j = k = tmp_plads = 0;

    for(i = 0; (i < length_of_array + (seats_per_row/2)); i++) {
        if( (is_illegal_seat(i, entrance_placement, seats_per_row))==0) {
            random_destinations[i] = -1;
        }
        random_destinations[i] = i;
    }

    for(i = 0; i < 1000000; i = i + 1) {
        get_random_number(&k,&j, length_of_array, seats_per_row);
        tmp_plads = random_destinations[k];
        random_destinations[k] = random_destinations[j];
        random_destinations[j] = tmp_plads;
    }
}

/*Tests if the seat is replaced by a door, and therefore illegal*/
int is_illegal_seat(int seat_tested, int entrance_placement, int seats_per_row) {
    int i;
    for(i = 0; i < (seats_per_row/2); i++) {
        if(seat_tested == ((entrance_placement * seats_per_row) + (seats_per_row/2) + i)) {
            return 0;
        }
    }
    return 1;
}


/* The passenger array gets filled with random destination, based on the random_destination array*/
void passenger_get_random_destinations(int *random_destinations, passenger passengers [], int length_of_array, int entrance_placement, int seats_per_row) {
    int *p_array, i;

    p_array = random_destinations;
    for(i=0; i < length_of_array; i++) {
        while((*(p_array+i))==-1) {
            p_array++;
        }
        passengers[i].destination = *(p_array+i);
    }
}


/*Passenger 0 is initialized to 0, and the rest, looks at the person in front*/
void initialize_spotting(passenger passengers[], int length_of_array) {
    int i;

    passengers [0].spotting = NULL;

    for(i = 1; i < length_of_array; i++) {
        passengers[i].spotting = &(passengers [i-1]);    
    }
}

/*Based on a carryon percentage, the passengers gets carryon*/
void get_carryon(passenger passengers[], int length_of_array, int carry_on_percentage){
    int i, j;

    for(i = 0; i < length_of_array; i++) {
        j = ((rand() % 100)+1);
        if(j <= carry_on_percentage) {
            passengers[i].carry_on = 1;
        }
        else {
            passengers[i].carry_on = 0;        
        }
    }
}


/*Used to create random destination, by generating 2 random numbers*/
void get_random_number(int *k,int *j,int length_of_array, int seats_per_row) {
    *k = (rand() % (length_of_array+(seats_per_row/2)));
    *j = (rand() % (length_of_array+(seats_per_row/2)));
}


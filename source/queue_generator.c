#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "../headers/main.h"
#include <time.h>

#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"
#include "../headers/queue_generator.h"

#endif

/*Produces a passenger array, that contains a random destination, and carryon for each passenger*/
void initialize_passenger_array(transition_system *t) {
    int *random_destinations; 

    random_destinations = (int*)calloc(t->length + (t->seats_per_row/2), sizeof(int));

    reset_passenger_array(t);
    get_random_array(random_destinations, t);
    passenger_get_random_destinations(random_destinations, t);
    initialize_spotting(t);
    get_carryon(t);
    free(random_destinations);
}


/* Resets that passenger array, and gives location -1*/
void reset_passenger_array(transition_system *t) {
    int i;
    for (i = 0; i < t->length; i++) {
        t->passengers[i].destination = 0;
        t->passengers[i].location = -1;
        t->passengers[i].carry_on = 0;
        t->passengers[i].wait_time = 0;
        t->passengers[i].finish = 0;
        t->passengers[i].interference_flag = 0;
        t->passengers[i].spotting = NULL;
    }
}

/*Produces an array with random numbers, from 0 to that number of seats*/
void get_random_array(int random_destinations[], transition_system *t) {
    int i, j, k, tmp_plads;
    i = j = k = tmp_plads = 0;

    for(i = 0; (i < (t->length + (t->seats_per_row/2))); i++) {

        if((is_legal_seat(i, t)) == 0) {
            random_destinations[i] = -1;
        } else {
            random_destinations[i] = i;
        }
    }


    for(i = 0; i < 1000000; i = i + 1) {
        get_random_number(&k,&j, t);
        tmp_plads = random_destinations[k];
        random_destinations[k] = random_destinations[j];
        random_destinations[j] = tmp_plads;
    }
}

/*Tests if the seat is replaced by a door, and therefore illegal*/
int is_legal_seat(int seat_tested, transition_system* t) {
    int i;
    for(i = 0; i < (t->seats_per_row/2); i++) {
        if(seat_tested == ((t->entrance * t->seats_per_row) + (t->seats_per_row/2) + i)) {
            return 0;
        }
    }
    return 1;
}


/* The passenger array gets filled with random destination, based on the random_destination array*/
void passenger_get_random_destinations(int *random_destinations, transition_system *t) {
    int *p_array, i;

    p_array = random_destinations;
    for(i=0; i < t->length; i++) {
        while((*(p_array+i))==-1) {
            p_array++;
        }
        t->passengers[i].destination = *(p_array+i);
    }
}


/*Passenger 0 is initialized to 0, and the rest, looks at the person in front*/
void initialize_spotting(transition_system *t) {
    int i;

    t->passengers[0].spotting = NULL;

    for(i = 1; i < t->length; i++) {
        t->passengers[i].spotting = &(t->passengers [i-1]);    
    }
}

/*Based on a carryon percentage, the passengers gets carryon*/
void get_carryon(transition_system *t) {
    int i, j;

    for(i = 0; i < t->length; i++) {
        j = ((rand() % 100)+1);
        if(j <= t->carryon_percentage) {
            t->passengers[i].carry_on = 1;
        }
        else {
            t->passengers[i].carry_on = 0;        
        }
    }
}


/*Used to create random destination, by generating 2 random numbers*/
void get_random_number(int *k,int *j,transition_system *t) {
    *k = (rand() % (t->length + (t->seats_per_row/2)));
    *j = (rand() % (t->length + (t->seats_per_row/2)));
}


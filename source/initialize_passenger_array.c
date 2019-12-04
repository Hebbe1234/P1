#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "../headers/main.h"
#include <time.h>

#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"
#include "../headers/initialize_passenger_array.h"

#endif

/*Produces a passenger array, that contains a random destination, and carryon for each passenger*/
void initialize_passenger_array(transition_system *t, int *destination_array) {          
    reset_passenger_array(t);
    get_carryon(t);
    initialize_spotting(t);                
    initialize_destination(destination_array, t);  
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


/*Passenger 0 is initialized to 0, and the rest, looks at the person in front*/
void initialize_spotting(transition_system *t) {
    int i;

    t->passengers[0].spotting = NULL;

    for(i = 1; i < t->length; i++) {
        t->passengers[i].spotting = &(t->passengers [i-1]);    
    }
}


/* The passenger array gets filled with random destination, based on the random_destination array*/
void initialize_destination(int *destination_a, transition_system *t) {
    int *p_array, i;

    p_array = destination_a;
    for(i=0; i < t->length; i++) {
        while((*(p_array+i))==-1) {
            p_array++;
        }
        t->passengers[i].destination = *(p_array+i);
    }
}

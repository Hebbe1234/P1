#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"
#include "../headers/random_boarding_generator.h"
#endif
#include <stdio.h>
#include <stdlib.h>


/*Fills the given array with legal destinations that is shuffled so its similar to outside in boarding*/
void outsidein_boarding_generator(transition_system *t, int *destinations) {


    
}
/*Fills the given array with legal destinations that is shuffled*/
void random_boarding_generator(transition_system *t, int *random_destinations) {
    int i, j, k, tmp_plads;
    i = j = k = tmp_plads = 0;

    for(i = 0; (i < t->length + (t->seats_per_row/2)); i++) {
        random_destinations[i] = i;
        if( (is_legal_seat(i, t)) == 0) {
            random_destinations[i] = -1;
        }
    }

    for(i = 0; i < 1000000; i++) {
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

/*Used to create random destination, by generating 2 random numbers*/
void get_random_number(int *k,int *j,transition_system *t) {
    *k = (rand() % (t->length + (t->seats_per_row/2)));
    *j = (rand() % (t->length + (t->seats_per_row/2)));
}

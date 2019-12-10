#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"

#endif
#include <stdio.h>
#include <stdlib.h>

#include "../headers/boarding_generator.h"
#define NUMBER_OF_SHUFFLES_PER_DESTINATION 100

/*Fills the given array with legal destinations that is shuffled so its similar to outside in boarding*/
void outsidein_boarding_generator(transition_system *t, int *destinations) {

    int i = 0, j = 0;
    int **arrays = (int **)calloc(t->seats_per_row/2, sizeof(int)*2*t->rows);

    for (i = 0; i < t->seats_per_row/2; i++) {
        arrays[i] = (int *)calloc(2*t->rows, sizeof(int));
    }

    for (i = 0; i < t->seats_per_row/2; i++) {
       for (j = 0; j < t->rows; j++) {
            arrays[i][j] = 6*j+i;
            arrays[i][t->rows+j] = 6*j + 5 - i;
       }
    }

    for (i = 0; i < t->seats_per_row/2; i++) {
        shuffle_array(arrays[i], 2*t->rows);
        for (j = 0; j < 2*t->rows; j++) {
            destinations[i*2*t->rows + j] = arrays[i][j];
        }
    } 

    for (i = 0; i < t->destination_length; i++) {
        if ((is_legal_seat(destinations[i], t)) == 0) {
            destinations[i] = -1;
        }
    }

    for (i = 0; i < t->seats_per_row/2; i++) {
        free(arrays[i]);
    }

    free(arrays);
}

/*Fills the given array with legal destinations that is shuffled*/
void random_boarding_generator(transition_system *t, int *random_destinations) {
    int i = 0;

    for (i = 0; i < t->destination_length; i++) {
        random_destinations[i] = i;

        if ((is_legal_seat(i, t)) == 0) {
            random_destinations[i] = -1;
        }
    }
    shuffle_array(random_destinations, t->destination_length);
}

/*Tests if the seat is replaced by a door, and therefore illegal*/
int is_legal_seat(int seat_tested, transition_system* t) {
    int i;
    for (i = 0; i < (t->seats_per_row/2); i++) {

        if (seat_tested == ((t->entrance * t->seats_per_row) + (t->seats_per_row/2) + i)) {
            return 0;
        }
    }
    return 1;
}

/*Takes and array and shuffles it based on the lenght of the array. */
void shuffle_array(int *array, int length) {
    int i, k, j, tmp_plads;
    i = k = j = tmp_plads = 0;

     for (i = 0; i < length * NUMBER_OF_SHUFFLES_PER_DESTINATION; i++) {
        get_random_number(&k,&j, length);
        tmp_plads = array[k];
        array[k] = array[j];
        array[j] = tmp_plads;
    }
}
/*Used to create random destination, by generating 2 random numbers*/
void get_random_number(int *k, int *j, int length) {
    *k = (rand() % length);
    *j = (rand() % length);
}

#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"

#endif
#include <stdio.h>
#include <stdlib.h>

#include "../headers/destination_row.h"

/* Returns a given passengers waittime, based on the location of other passengers in their 'row' */
int inter(transition_system *t, int index) {
    int i, j;
    passenger p = t->passengers[index];

    /*This is the aisle seats*/
    if (p.destination % t->seats_per_row == 2 || 
        p.destination % t->seats_per_row == 3) {
           return t->wait.t_0;
    }

    /*This is the top middle seats*/
    if (p.destination % t->seats_per_row == 1) {
           
        for (i = 0; i < t->length; i++) {

            if (is_passenger_at_seat(t, p, i, 2) == 1) {
                return t->wait.t_1;
            }
        }
        return t->wait.t_0;
    }

    /*This is the bottom middle seats*/
    if (p.destination % t->seats_per_row == 4) {

        for (i = 0; i < t->length; i++) {

            if (is_passenger_at_seat(t, p, i, 3) == 1) {
                return t->wait.t_1;
            }
        }
        return t->wait.t_0;
    }

    /*This is the top window seat*/
    if (p.destination % t->seats_per_row == 0) {

        for (i = 0; i < t->length; i++) {

            if (is_passenger_at_seat(t, p, i, 1) == 1) {
                
                for (j = 0; j < t->length; j++) {

                    if (is_passenger_at_seat(t, p, j, 2) == 1) {
                        return t->wait.t_3;                                       
                    }
                }
                return t->wait.t_2; 
            }
        }

        for (i = 0; i < t->length; i++) {

            if (is_passenger_at_seat(t, p, i, 2) == 1) {
                return t->wait.t_1;
            }
        }
        return t->wait.t_0;
    }

    /*This is the bottom window seat*/
    if (p.destination % t->seats_per_row == 5) {

        for (i = 0; i < t->length; i++) {

            if (is_passenger_at_seat(t, p, i, 4) == 1) {
                        
                for (j = 0; j < t->length; j++) {
                    if (is_passenger_at_seat(t, p, j, 3) == 1) {
                        return t->wait.t_3;                                       
                    }
                }
                return t->wait.t_2;
            }
        }

        for (i = 0; i < t->length; i++) {
          
            if (is_passenger_at_seat(t, p, i, 3) == 1) {
                return t->wait.t_1;
            }
        }
        return t->wait.t_0;
    }
    return -1;
}

/* Returns a value true or false whether a passenger is occupying seat */
int is_passenger_at_seat(transition_system *t, passenger p, int i, int seat) {
    
    if (d_row(&(t->passengers[i]), t) == d_row(&p, t) && 
        t->passengers[i].destination % t->seats_per_row == seat && 
        t->passengers[i].finish == 1) {
            return 1;
    }
    return 0;
}

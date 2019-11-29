#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"

#endif
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Gives the passenger the proper wait time based on the location of other passengers in their 'row' */
int inter(transition_system *t, passenger p) {
    int i, j;

/*This is the aisle seats*/
    if(p.destination % t->seats_per_row == 2 || 
       p.destination % t->seats_per_row == 3) {
           return t->wait.t_0;
    }


/*This is the top middle seats*/
    if(p.destination % t->seats_per_row == 1) {
           
        for(i = 0; i < t->length; i++) {

            if(floor(t->passengers[i].destination / t->seats_per_row) == floor(p.destination / t->seats_per_row) 
                    && t->passengers[i].destination % t->seats_per_row == 2
                    && t->passengers[i].finish == 1) {
                        return t->wait.t_2;
            }
        }
        return t->wait.t_0;
    }


/*This is the bottom middle seats*/
    if(p.destination % t->seats_per_row == 4) {

        for(i = 0; i < t->length; i++) {

            if(floor(t->passengers[i].destination/t->seats_per_row) == floor(p.destination/t->seats_per_row) 
                    && t->passengers[i].destination % t->seats_per_row == 3
                    && t->passengers[i].finish == 1) {
                        return t->wait.t_2;
            }
        }
        return t->wait.t_0;
    }


/*This is the top window seat*/
    if(p.destination % t->seats_per_row == 0) {

        for(i = 0; i < t->length; i++) {

            if(floor(t->passengers[i].destination/t->seats_per_row) == floor(p.destination /t->seats_per_row) 
                    && t->passengers[i].destination % t->seats_per_row == 1
                    && t->passengers[i].finish == 1) {
                        
                        for(j = 0; j < t->length; j++) {
                            if(floor(t->passengers[j].destination/t->seats_per_row) == floor(p.destination /t->seats_per_row) 
                                    && t->passengers[j].destination % t->seats_per_row == 2
                                    && t->passengers[j].finish == 1) {
                                        return t->wait.t_3;                                       
                                    }
                        }
                        return t->wait.t_1;
            }
        }
        for(i = 0; i < t->length; i++) {
            if(floor(t->passengers[i].destination/t->seats_per_row) == floor(p.destination/t->seats_per_row) 
                    && t->passengers[i].destination % t->seats_per_row == 2
                    && t->passengers[i].finish == 1) {
                        return t->wait.t_2;
              }
        }
            return t->wait.t_0;
    }


/*This is the bottom window seat*/
    if(p.destination % t->seats_per_row == 5) {

        for(i = 0; i < t->length; i++) {

            if(floor(t->passengers[i].destination/t->seats_per_row) == floor(p.destination /t->seats_per_row) 
                    && t->passengers[i].destination % t->seats_per_row == 4
                    && t->passengers[i].finish == 1) {
                        
                        for(j = 0; j < t->length; j++) {
                            if(floor(t->passengers[j].destination/t->seats_per_row) == floor(p.destination /t->seats_per_row) 
                                    && t->passengers[j].destination % t->seats_per_row == 3
                                    && t->passengers[j].finish == 1) {
                                        return t->wait.t_3;                                       
                                    }
                        }

                        return t->wait.t_1;
            }
        }
        for(i = 0; i < t->length; i++) {
            if(floor(t->passengers[i].destination/t->seats_per_row) == floor(p.destination/t->seats_per_row) 
                    && t->passengers[i].destination % t->seats_per_row == 3
                    && t->passengers[i].finish == 1) {
                        return t->wait.t_2;
            }
        }
        return t->wait.t_0;
    }


    return -1;
}

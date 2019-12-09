#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"

#endif
#include <stdio.h>
#include <stdlib.h>
#include "../headers/destination_row.h"

/* Checks which passenger the last initialized passenger must look at 
 * by finding the passenger closest to the entrance. Input is index
 * of initialized passenger, output is index of passenger closest to 
 * the entrance. If no one is found, output is index = -1 */ 
int rear_function (transition_system *t, int i) {
    passenger q;
    int index = -1;
    int j = 0;

    if (t->entrance <= d_row(&(t->passengers[i]), t) && 
        t->passengers[i].finish == 0 &&
        t->passengers[i].location > -1) {

        q.location = t->rows - 1;

        for (j = 0; j < t->length; j++) {

            if (j != i && t->passengers[i].location < t->passengers[j].location && 
                t->passengers[j].location - t->entrance <= q.location - t->entrance && 
                t->passengers[j].location > -1 && 
                t->passengers[j].finish == 0) {
                
                q = t->passengers[j];
                index = j;
                
            }
        } 
    } else if (t->entrance > d_row(&(t->passengers[i]), t) && 
               t->passengers[i].finish == 0 && 
               t->passengers[i].location > -1) {

        q.location = 0;
        
        for(j = 0; j < t->length; j++) {

            if( j != i &&
                t->passengers[i].location > t->passengers[j].location && 
                t->entrance - t->passengers[j].location < t->entrance - q.location &&
                t->passengers[j].location > -1 &&
                t->passengers[j].finish == 0) {
                
                q = t->passengers[j];
                index = j;
                
            }
        }
    }
    return index;
}

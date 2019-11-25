#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"

#endif

#ifndef FINAL
#define FINAL

#include "../headers/finalizing.h"

#endif

#include <stdio.h>
#include <stdlib.h>

void finalising_passenger(transition_system *t) {
    int P_L, i;
    passenger p;

    for (i = 0; i < 2; i++)
    {
        p  = t->passengers[i];
        P_L = p.location;
        if (P_L == p.destination/6 && p.carry_on == 0 && p.wait_time == 0){
            t->passengers[i].finish = 1;
            printf("Finish");
        }
    printf("Not finish");
        
    }
    
        /*if(test[]->location == test[]->destination/6 && test[]->carry_on == 0 && test[]->wait_time == 0){
            p1->finish = 1;
        } 
        else {
            printf("Passenger not finished!\n");
        }

        printf("%d\n", p1->finish);
        }*/
}

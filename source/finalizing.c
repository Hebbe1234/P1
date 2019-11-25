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

void finalising_passenger(*t passengers) {
    int P_L, i;
    *t p;

    for (i = 0; i < 2; i++)
    {
        p  = passengers[i];
        P_L = p.location;
        if (P_L == p.destination/6 && p.carry_on == 0 && p.wait_time == 0){
            p.finish = 1;
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

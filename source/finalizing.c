#ifndef STRUCTS
#define STRUCTS

#include "../headers/structs.h"

#endif

#ifndef FINAL
#define FINAL

#include "../headers/finalizing.h"

#endif

#include <stdio.h>

void finalising(passenger* p1) {

       /* for(int i = 0; i <= (passenger_array); i++) */

        if(p1->location == p1->destination/6 && p1->carry_on == 0 && p1->wait_time == 0 && p1->inteference_flag == 2){
            p1->finish = 1;
        } 
        else {
            printf("Passenger not finished!\n");
        }

        printf("%d\n", p1->finish);
}

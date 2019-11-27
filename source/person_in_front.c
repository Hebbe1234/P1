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
#include <math.h>


/*This function takes the transitionsystem, and changes who is spotting who, based on finished passengers. */
void person_in_front(transition_system *t, int length_of_array){
    int i;
    
    for(i = 0; i < length_of_array; i++){
        while(t->passengers[i].spotting != NULL && t->passengers[i].spotting->finish == 1)
            t->passengers[i].spotting = t->passengers[i].spotting->spotting;
    }
}
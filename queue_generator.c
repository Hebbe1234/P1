#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "headers/main.h"
#include <time.h>
#define NUMBER_OF_PASSENGERS_BOARDING 27
#define NUMBER_OF_ROWS 10
#define ENTRANCE_PLACEMENT 4 

void get_random_number(int *k,int *j);
void get_random_array(int random_destination[]);


int main(void){
    int random_destination[60];
    srand(time(0));

    get_random_array(random_destination);
    return (0);
}





void get_random_array(int random_destination[]) {
    int i, j, k, plads;
    i=j=k=plads=0;

    for(i=0; i<60; i=i+1)
        random_destination[i]=i;

    for(i=0; i<1000000; i=i+1) {
        get_random_number(&k,&j);
        plads = random_destination[k];
        random_destination[k] = random_destination[j];
        random_destination[j] = plads;
    }

    for(i=0, plads=0; i<60; i=i+1, plads=plads+1) {
        printf("%d , %d \n", random_destination[i], plads);
    }



}

void get_random_number(int *k,int *j) {
    *k = (rand() % 60);
    *j = (rand() % 60);
}





